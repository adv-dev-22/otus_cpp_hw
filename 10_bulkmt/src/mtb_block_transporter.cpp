#include "mtb_block_transporter.h"
#include <iostream>

MtbBlockTransporter::MtbBlockTransporter():
thread_cout(),
thread_file_1(),
thread_file_2(),
up_worker_std_(nullptr),
up_worker_file_1_(nullptr),
up_worker_file_2_(nullptr)
{
}

void MtbBlockTransporter::start_threads()
{
    // Preliminary (necessary) initialization
    up_worker_std_ = std::make_unique<MtbTransporterWorkerStd>();


    thread_cout = std::move(std::thread(std::ref(*up_worker_std_)));

    // ..

}

void MtbBlockTransporter::conclude_threads()
{
    std::cout << "concluding thread std\n";
    up_worker_std_->conclude_processing();

}

void MtbBlockTransporter::join_threads()
{
    if (thread_cout.joinable()) thread_cout.join();
    else throw std::logic_error("Can not join thread_cout");

    if (thread_file_1.joinable()) thread_file_1.join();
    else throw std::logic_error("Can not join thread_file_1");

    if (thread_file_2.joinable()) thread_file_2.join();
    else throw std::logic_error("Can not join thread_file_2");
}

// End of the file
