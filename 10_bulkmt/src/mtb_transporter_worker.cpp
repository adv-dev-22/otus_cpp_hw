#include "mtb_transporter_worker.h"
#include "mtb_data_block.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <shared_mutex>

MtbTransporterWorkerBase::MtbTransporterWorkerBase():
processing_is_finished_(false),
ptr_cv_(nullptr),
ptr_mtx_(nullptr),
ptr_block_queue_(nullptr)
{
}

void MtbTransporterWorkerBase::conclude_processing() noexcept
{
    processing_is_finished_ = true;
}

void MtbTransporterWorkerBase::set_condition_variable(std::condition_variable * ptr_cv)
{
    this->ptr_cv_ = ptr_cv;
}

void MtbTransporterWorkerBase::set_mutex(std::mutex * ptr_mtx)
{
    this->ptr_mtx_ = ptr_mtx;
}

void MtbTransporterWorkerBase::set_queue(std::queue<DataBlock> * block_queue)
{
    this->ptr_block_queue_;
}


void MtbTransporterWorkerBase::update()
{
    // TODO:
    //ptr_data_block_ = p_data_block;
}


MtbTransporterWorkerStd::MtbTransporterWorkerStd()
{
}

void MtbTransporterWorkerStd::operator() ()
{
    std::cout << "std thread started " << std::endl;

//    std::unique_lock<std::mutex> lck(*ptr_mtx_);

//    while (!processing_is_finished_)
//    {
//        ptr_cv_->wait(lck);

//        //std::shared_lock()

//        std::cout << "next processing: " << processing_is_finished_ << std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(500));

//    }
    std::cout << "std thread finished " << std::endl;

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
