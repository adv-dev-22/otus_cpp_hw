// This file is included in the mlt_thr_data_server.h

#include <cstdio>
#include <unistd.h>
#include <pthread.h>
#include "mlt_thr_data_server.h"

MultiThreadDataServer::MultiThreadDataServer():
mtx_lock_(PTHREAD_MUTEX_INITIALIZER),
consumer_cond_(PTHREAD_COND_INITIALIZER),
producer_cond_(PTHREAD_COND_INITIALIZER),
ibuffer_(0),
max_buff_size_(0),
max_loop_size_(0) {

    pthread_mutex_init(&mtx_lock_, nullptr);
}

//virtual
MultiThreadDataServer::~MultiThreadDataServer() {

}

void MultiThreadDataServer::set_buffer_size(const size_t bsz) {
    max_buff_size_ = bsz;
}

void MultiThreadDataServer::set_worker_loop_size(const size_t lsz) {
    max_loop_size_ = lsz;
}

size_t MultiThreadDataServer::worker_loop_size() const {
    return max_loop_size_;
}

void MultiThreadDataServer::push(const std::string msg, const size_t ms) {

    pthread_mutex_lock(&mtx_lock_);

    while (ibuffer_ >= max_buff_size_) {
        printf("%lu in while: int_buffer = %d\n", pthread_self(), ibuffer_);
        pthread_cond_wait(&producer_cond_, &mtx_lock_);
    }
    ++ibuffer_;

    const char * text = msg.c_str();
    printf("%s  buffer size = %d\n", text, ibuffer_);

    usleep(900'000);

    pthread_cond_signal(&consumer_cond_);
    pthread_mutex_unlock(&mtx_lock_);
}

void MultiThreadDataServer::pop(const std::string msg, const size_t ms) {

    pthread_mutex_lock(&mtx_lock_);

    while (ibuffer_ <= 0) {
        printf("%lu in while: int_buffer = %d\n", pthread_self(), ibuffer_);
        pthread_cond_wait(&consumer_cond_, &mtx_lock_);
    }

    --ibuffer_;

    const char * text = msg.c_str();
    printf("%s buffer size = %d\n", text, ibuffer_);

    usleep(900'000);

    pthread_cond_signal(&producer_cond_);
    pthread_mutex_unlock(&mtx_lock_);

}

// End of the file
