#include "mtb_transporter_worker.h"
#include "mtb_data_block.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <shared_mutex>

MtbTransporterWorkerBase::MtbTransporterWorkerBase():
processing_is_finished_(false),
wp_cv_(),
ptr_mtx_(nullptr),
ptr_block_queue_(nullptr)
{
}

void MtbTransporterWorkerBase::conclude_processing() noexcept
{
    processing_is_finished_ = true;
}

void MtbTransporterWorkerBase::set_condition_variable(std::weak_ptr<std::condition_variable> wp_cv)
{
    this->wp_cv_ = wp_cv;
}

void MtbTransporterWorkerBase::set_mutex(std::mutex * ptr_mtx)
{
    this->ptr_mtx_ = ptr_mtx;
}

void MtbTransporterWorkerBase::set_queue(std::queue<DataBlock> * block_queue)
{
    this->ptr_block_queue_ = block_queue;
}

MtbTransporterWorkerStd::MtbTransporterWorkerStd()
{
}

void MtbTransporterWorkerStd::operator() ()
{
//    std::cout << "std thread started " << std::endl;

    std::unique_lock<std::mutex> lck(*ptr_mtx_);
    while (!processing_is_finished_)
    {
        wp_cv_.lock()->wait(lck);

        if (ptr_block_queue_->empty()) continue;

        const DataBlock & db = ptr_block_queue_->front();
        db.write(std::cout);

        ptr_block_queue_->pop();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
//    std::cout << "std thread finished " << std::endl;
}

MtbTransporterWorkerFile::MtbTransporterWorkerFile()
{

}

void MtbTransporterWorkerFile::operator() ()
{

//    while (true)
//    {
//            cv.wait

//        if (quit_flag) break;
//    }


}

// End of the file




//std::cout << "next processing: " << processing_is_finished_ << std::endl;
