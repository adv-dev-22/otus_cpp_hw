#include "mtb_block_transporter.h"
#include <iostream>

MtbBlockTransporter::MtbBlockTransporter():
thread_stdout_(),
thread_file_1_(),
thread_file_2_(),
up_worker_stdout_(nullptr),
up_worker_file_1_(nullptr),
up_worker_file_2_(nullptr),
cv_stdout_(),
cv_file_x_(),
mtx_stdout_(),
mtx_file_x_(),
block_queue_()
{
}

void MtbBlockTransporter::start_threads()
{
    // Preliminary (necessary) initialization
    up_worker_stdout_ = std::make_unique<MtbTransporterWorkerStd>();
    up_worker_stdout_->set_condition_variable(&cv_stdout_);
    up_worker_stdout_->set_mutex(&mtx_stdout_);
    up_worker_stdout_->set_queue(&block_queue_);

    thread_stdout_ = std::move(std::thread(std::ref(*up_worker_stdout_)));

    // ..

}

void MtbBlockTransporter::conclude_threads()
{
    std::cout << "concluding thread std\n";
    //up_worker_std_->conclude_processing();
}

void MtbBlockTransporter::push_back_locked(const DataBlock & data_block)
{
    //up_worker_std_->update(&data_block);
   // up_worker_file_1_->update(&data_block);
   // up_worker_file_2_->update(&data_block);

    //cv_block_.notify_all();
}

void MtbBlockTransporter::join_threads()
{
    if (thread_stdout_.joinable()) thread_stdout_.join();
    else throw std::logic_error("Can not join thread_stdout");

//    if (thread_file_1.joinable()) thread_file_1.join();
//    else throw std::logic_error("Can not join thread_file_1");

//    if (thread_file_2.joinable()) thread_file_2.join();
//    else throw std::logic_error("Can not join thread_file_2");
}

// End of the file
