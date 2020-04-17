#include "prod_cons_simulator.h"
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

///////////////////////////////////////////////////////////////////////////////

void * producer_thread(void * arg) {

    auto data_server = (MultiThreadDataServer *) arg;

    using  std::string;
    using  std::to_string;

    const size_t loop_size = data_server->worker_loop_size();
    for (size_t i = 0; i < loop_size; ++i) {

        size_t ms = (rand() % 899) + 100;
        usleep(ms * 1000); // micro seconds

        string msg("Producer id =  ");
        msg.append(to_string(pthread_self()));
        msg.append(string(",  duration = "));
        msg.append(to_string(ms));
        msg.append(" sec");

        data_server->push(msg, ms);
    }

    pthread_exit(0);
}

void * consumer_thread(void * arg) {

    auto * data_server = (MultiThreadDataServer *) arg;

    using  std::string;
    using  std::to_string;

    const size_t loop_size = data_server->worker_loop_size();
    for (size_t i = 0; i < loop_size; ++i) {

        size_t ms = (rand() % 899) + 100;
        usleep(ms * 1000); // micro seconds

        string msg("Consumer id =  ");
        msg.append(to_string(pthread_self()));
        msg.append(string(",  duration = "));
        msg.append(to_string(ms));
        msg.append(" sec");

        data_server->pop(msg, ms);
    }

    data_server = nullptr;
    pthread_exit(0);
}

///////////////////////////////////////////////////////////////////////////////

ProdConsSimulator::ProdConsSimulator():
produsers_numb_(0),
consumers_numb_(0),
max_buff_size_(0),
max_loop_size_(0),
data_server_(nullptr),
prod_threads_(nullptr),
cons_threads_(nullptr) {

}

ProdConsSimulator::~ProdConsSimulator() {

}

void ProdConsSimulator::run() {

    srand((int) time(0));

    // Initialization block
    data_server_ = std::make_unique<MultiThreadDataServer>();
    data_server_->set_buffer_size(max_buff_size_);
    data_server_->set_worker_loop_size(max_loop_size_);

    prod_threads_ = std::make_unique<pthread_t []>(produsers_numb_);
    cons_threads_ = std::make_unique<pthread_t []>(consumers_numb_);

    // Producers. Create threads.
    for (size_t k = 0; k < produsers_numb_; ++k) {

        int ret = pthread_create(&prod_threads_[k], nullptr,
                                 producer_thread, (void *) data_server_.get());
        if (0 != ret) {
            printf("Error creating producer thread at k = %ld", k);
            exit(EXIT_FAILURE);
        }
    }

    // Consumers. Create threads.
    for (size_t k = 0; k < consumers_numb_; ++k) {

        int ret = pthread_create(&cons_threads_[k], nullptr,
                                 consumer_thread, (void *) data_server_.get());
        if (0 != ret) {
            printf("Error creating consumer pthread at k = %ld", k);
            exit(EXIT_FAILURE);
        }
    }

    // Producers join threads
    for (size_t k = 0; k < produsers_numb_; ++k) {

        void * ret_join;
        const int ret = pthread_join(prod_threads_[k], &ret_join);

        if (ret != 0) {
            printf("Producer thread_join failed");
            exit(EXIT_FAILURE);
        }
    }

    // Consumers join threads
    for (size_t k = 0; k < consumers_numb_; ++k) {

        void * ret_join;
        const int ret = pthread_join(cons_threads_[k], &ret_join);

        if (ret != 0) {
            printf("Consumer pthread_join failed");
            exit(EXIT_FAILURE);
        }
    }

    printf("Finished main run\n");
}

void ProdConsSimulator::set_producer_number(const size_t numb) {
    produsers_numb_ = numb;
}

void ProdConsSimulator::set_consumer_number(const size_t numb) {
    consumers_numb_ = numb;
}

void ProdConsSimulator::set_buffer_size(const size_t bsz) {
    max_buff_size_ = bsz;
}

void ProdConsSimulator::set_worker_loop_size(const size_t lsz) {
    max_loop_size_ = lsz;
}

// End of the file
