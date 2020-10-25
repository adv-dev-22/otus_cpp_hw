#include "mtb_transporter_worker.h"
#include "mtb_data_block.h"
#include "mtb_stats_counter.h"
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
wp_block_queue_(),
stats_counter_(std::make_unique<MtbStatsCounterThread>(0,0))
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
    print_statistics_();
}

void MtbTransporterWorkerBase::append_stats_(const DataBlock & db)
{
    stats_counter_->blocks_counter++;
    stats_counter_->commands_counter += db.size();
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

    append_stats_(db);

    db.write(std::cout);
}

void MtbTransporterWorkerStd::print_statistics_()
{
    std::cout << stats_counter_->get_stat_str("log:  ") << std::endl;
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

    append_stats_(db);

    std::string file_name("bulk-");
    file_name.append(get_id_str());
    file_name.append("-");
    file_name.append(db.time_stamp());
    file_name.append(".log");

    std::ofstream fout(file_name, std::ofstream::out);
    db.write(fout);
    fout.close();
}

void MtbTransporterWorkerFile::print_statistics_()
{
    std::stringstream ss;
    ss << "file-" << get_id_str() << " ";
    std::cout << stats_counter_->get_stat_str(ss.str()) << std::endl;
}

std::string MtbTransporterWorkerFile::get_id_str() const
{
    std::stringstream ss;
    ss << std::this_thread::get_id();
    return ss.str();
}

// End of the file
