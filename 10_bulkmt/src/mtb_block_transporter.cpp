#include "mtb_block_transporter.h"
#include <iostream>

MtbBlockTransporter::MtbBlockTransporter():
thread_stdout_(),
thread_file_1_(),
thread_file_2_(),
worker_stdout_(nullptr),
worker_file_1_(nullptr),
worker_file_2_(nullptr),
cv_stdout_(std::make_shared<std::condition_variable>()),
cv_file_x_(std::make_shared<std::condition_variable>()),
mtx_stdout_(std::make_shared<std::mutex>()),
mtx_file_x_(std::make_shared<std::mutex>()),
block_queue_stdout_(std::make_shared<std::queue<DataBlock>>()),
block_queue_file_x_(std::make_shared<std::queue<DataBlock>>())
{
}

void MtbBlockTransporter::start_threads()
{
    // Preliminary (necessary) initialization
    // 0. Std out
    worker_stdout_ = std::make_unique<MtbTransporterWorkerStd>();
    worker_stdout_->set_condition_variable(cv_stdout_);
    worker_stdout_->set_mutex(mtx_stdout_);
    worker_stdout_->set_queue(block_queue_stdout_);

    thread_stdout_ = std::move(std::thread(std::ref(*worker_stdout_)));

    // 1. File_1 thread
    worker_file_1_ = std::make_unique<MtbTransporterWorkerFile>();
    worker_file_1_->set_condition_variable(cv_file_x_);
    worker_file_1_->set_mutex(mtx_file_x_);
    worker_file_1_->set_queue(block_queue_file_x_);

    thread_file_1_ = std::move(std::thread(std::ref(*worker_file_1_)));

    // 2. File_2 thread
    worker_file_2_ = std::make_unique<MtbTransporterWorkerFile>();
    worker_file_2_->set_condition_variable(cv_file_x_);
    worker_file_2_->set_mutex(mtx_file_x_);
    worker_file_2_->set_queue(block_queue_file_x_);

    thread_file_2_ = std::move(std::thread(std::ref(*worker_file_2_)));
}

void MtbBlockTransporter::conclude_threads()
{
    //std::cout << "concluding thread std\n";
    cv_stdout_->notify_one();
    worker_stdout_->conclude_processing();

    cv_file_x_->notify_all();
    worker_file_1_->conclude_processing();
    worker_file_2_->conclude_processing();
}

void MtbBlockTransporter::push_back_locked(const DataBlock & data_block)
{
    // 1. Stdout thread related operations
    {
        std::unique_lock<std::mutex> lck(*mtx_stdout_);
        block_queue_stdout_->push(data_block);
        cv_stdout_->notify_one();
    }

    // 2. File threads related operations
    {
        std::unique_lock<std::mutex> lck(*mtx_file_x_);
        block_queue_file_x_->push(data_block);
        cv_file_x_->notify_all();
    }
}

void MtbBlockTransporter::join_threads()
{
    if (thread_stdout_.joinable()) thread_stdout_.join();
    else throw std::logic_error("Can not join thread_stdout");

    if (thread_file_1_.joinable()) thread_file_1_.join();
    else throw std::logic_error("Can not join thread_file_1");

    if (thread_file_2_.joinable()) thread_file_2_.join();
    else throw std::logic_error("Can not join thread_file_2");
}

// End of the file
