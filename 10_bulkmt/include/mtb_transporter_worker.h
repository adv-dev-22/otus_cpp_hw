#ifndef _MTB_10_TRANSPORTER_WORKER_H_
#define _MTB_10_TRANSPORTER_WORKER_H_

#include <condition_variable>
#include <shared_mutex>
#include <queue>

class DataBlock;

// Notification is done throw cv.notify_...()
// No explicit update invocations

class MtbTransporterWorkerBase
{
public:
    MtbTransporterWorkerBase();
    virtual ~MtbTransporterWorkerBase() = default;

    virtual void operator() () = 0;

    void conclude_processing() noexcept;

    void set_condition_variable(std::weak_ptr<std::condition_variable> wp_cv);
    void set_mutex(std::mutex * ptr_mtx);
    void set_queue(std::queue<DataBlock> * block_queue);

protected:
    bool processing_is_finished_;

    std::weak_ptr<std::condition_variable> wp_cv_;
    std::mutex * ptr_mtx_;
    std::queue<DataBlock> * ptr_block_queue_;
};

class MtbTransporterWorkerStd : public MtbTransporterWorkerBase
{
public:
    MtbTransporterWorkerStd();
    virtual ~MtbTransporterWorkerStd() = default;

    virtual void operator() () override;
};

class MtbTransporterWorkerFile : public MtbTransporterWorkerBase
{
public:
    MtbTransporterWorkerFile();
    virtual ~MtbTransporterWorkerFile() = default;

    virtual void operator() () override;
};

#endif  // _MTB_10_TRANSPORTER_WORKER_H_

// End of the file
