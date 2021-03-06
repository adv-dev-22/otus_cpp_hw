#ifndef _MTB_10_TRANSPORTER_WORKER_H_
#define _MTB_10_TRANSPORTER_WORKER_H_

#include "mtb_stats_counter.h"
#include <condition_variable>
#include <shared_mutex>
#include <queue>

class DataBlock;
class MtbStatsCounterThread;

// Notification is done via cv.notify_one/all()
// No explicit update invocations

class MtbTransporterWorkerBase
{
public:
    MtbTransporterWorkerBase();
    virtual ~MtbTransporterWorkerBase() = default;

    void operator() ();

    void conclude_processing() noexcept;

    void set_condition_variable(std::weak_ptr<std::condition_variable> wp_cv);
    void set_mutex(std::weak_ptr<std::mutex> wp_mtx);
    void set_queue(std::weak_ptr<std::queue<DataBlock>> wp_block_queue);

protected:
    /*! Flag to stop inifinite cv.wait() loop */
    bool processing_is_finished_;

    /*! Auxiliary multithreading variables common for stdout or file out threads */
    std::weak_ptr<std::condition_variable> wp_cv_;
    std::weak_ptr<std::mutex> wp_mtx_;
    std::weak_ptr<std::queue<DataBlock>> wp_block_queue_;

    std::unique_ptr<MtbStatsCounterThread> stats_counter_;

    void append_stats_(const DataBlock & db);

private:
    void do_work_strategy_();

    virtual void do_specific_work_() = 0;
    virtual void print_statistics_() = 0;
};

class MtbTransporterWorkerStd : public MtbTransporterWorkerBase
{
public:
    MtbTransporterWorkerStd();
    virtual ~MtbTransporterWorkerStd() = default;

private:
    virtual void do_specific_work_() override;
    virtual void print_statistics_() override;
};

class MtbTransporterWorkerFile : public MtbTransporterWorkerBase
{
public:
    MtbTransporterWorkerFile();
    virtual ~MtbTransporterWorkerFile() = default;

private:
    virtual void do_specific_work_() override;
    virtual void print_statistics_() override;

    std::string get_id_str() const;
};

#endif  // _MTB_10_TRANSPORTER_WORKER_H_

// End of the file
