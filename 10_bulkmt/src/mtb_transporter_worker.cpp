#include "mtb_transporter_worker.h"
#include "mtb_data_block.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <shared_mutex>
#include <sstream>
#include <fstream>

MtbTransporterWorkerBase::MtbTransporterWorkerBase():
processing_is_finished_(false),
wp_cv_(),
wp_mtx_(),
wp_block_queue_()
{
}

void MtbTransporterWorkerBase::operator() ()
{
    do_work_strategy_();
}

void MtbTransporterWorkerBase::conclude_processing() noexcept
{
    processing_is_finished_ = true;
}

void MtbTransporterWorkerBase::set_condition_variable(std::weak_ptr<std::condition_variable> wp_cv)
{
    this->wp_cv_ = wp_cv;
}

void MtbTransporterWorkerBase::set_mutex(std::weak_ptr<std::mutex> wp_mtx)
{
    this->wp_mtx_ = wp_mtx;
}

void MtbTransporterWorkerBase::set_queue(std::weak_ptr<std::queue<DataBlock>> wp_block_queue)
{
    this->wp_block_queue_ = wp_block_queue;
}

void MtbTransporterWorkerBase::do_work_strategy_()
{
    // Weak pointer takes shared pointer.
    auto mtx = wp_mtx_.lock();
    // Lock mutex
    std::unique_lock<std::mutex> lck(*mtx);
    while (!processing_is_finished_)
    {
        wp_cv_.lock()->wait(lck);

        // Shared ptr from weak
        auto block_queue = wp_block_queue_.lock();
        if (block_queue->empty()) continue;

        do_specific_work_();

        block_queue->pop();
    }
}

//-----------------------------------------------------------------------------

MtbTransporterWorkerStd::MtbTransporterWorkerStd()
{
}

void MtbTransporterWorkerStd::do_specific_work_()
{
    // It is called inside the locked section.

    auto block_queue = wp_block_queue_.lock();
    const DataBlock & db = block_queue->front();
    db.write(std::cout);
}

//-----------------------------------------------------------------------------

MtbTransporterWorkerFile::MtbTransporterWorkerFile()
{
}

void MtbTransporterWorkerFile::do_specific_work_()
{
    // It is called inside the locked section.

    auto block_queue = wp_block_queue_.lock();
    const DataBlock & db = block_queue->front();

    std::string file_name("bulk-");
    std::stringstream ss;
    ss << std::this_thread::get_id();
    file_name.append(ss.str());
    file_name.append("-");
    file_name.append(db.time_stamp());
    file_name.append(".log");

    std::ofstream fout(file_name, std::ofstream::out);
    db.write(fout);
    fout.close();
}

// End of the file


//void MtbTransporterWorkerStd::operator() ()
//{
//    auto mtx = wp_mtx_.lock();
//    std::unique_lock<std::mutex> lck(*mtx);
//    while (!processing_is_finished_)
//    {
//        wp_cv_.lock()->wait(lck);

//        auto block_queue = wp_block_queue_.lock();
//        if (block_queue->empty()) continue;

//        const DataBlock & db = block_queue->front();
//        db.write(std::cout);

//        block_queue->pop();
//        std::this_thread::sleep_for(std::chrono::milliseconds(300));
//    }
//}

// TODO: move it to base class with parameter
//void MtbTransporterWorkerFile::operator() ()
//{
//    //std::cout << "file thread: " << std::this_thread::get_id() << std::endl;

//    // Weak pointer takes shared pointer.
//    auto mtx = wp_mtx_.lock();
//    // Lock mutex
//    std::unique_lock<std::mutex> lck(*mtx);
//    while (!processing_is_finished_)
//    {
//        std::cout << "file thread: " << std::this_thread::get_id() << std::endl;
//        wp_cv_.lock()->wait(lck);

//        // Shared ptr from weak
//        auto block_queue = wp_block_queue_.lock();
//        if (block_queue->empty()) continue;

//        const DataBlock & db = block_queue->front();
//        //std::cout << "file thread writes: " << std::this_thread::get_id() << std::endl;
//        db.write(std::cout);

//        block_queue->pop();
//        //std::this_thread::sleep_for(std::chrono::milliseconds(300));
//    }
//}