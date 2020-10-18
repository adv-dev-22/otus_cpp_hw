#ifndef _MTB_10_BLOCK_TRANSPORTER_H_
#define _MTB_10_BLOCK_TRANSPORTER_H_

#include "mtb_transporter_worker.h"
#include "mtb_data_block.h"
#include <thread>
#include <memory>
#include <shared_mutex>
#include <queue>

class MtbBlockTransporter final
{
public:
    MtbBlockTransporter();
    ~MtbBlockTransporter() = default;

    void start_threads();
    void conclude_threads();

    void push_back_locked(const DataBlock & data_block);

    void join_threads();

    /*! Notifies std-thread and one of the file-threads. */
//    void notify_both();

private:
    std::thread thread_stdout_;
    std::thread thread_file_1_;
    std::thread thread_file_2_;

    std::unique_ptr<MtbTransporterWorkerStd>  up_worker_stdout_;
    std::unique_ptr<MtbTransporterWorkerFile> up_worker_file_1_;
    std::unique_ptr<MtbTransporterWorkerFile> up_worker_file_2_;

    std::shared_ptr<std::condition_variable> cv_stdout_;
    //std::condition_variable cv_file_x_;

    std::shared_ptr<std::mutex> mtx_stdout_;
    //std::mutex mtx_file_x_;

    std::shared_ptr<std::queue<DataBlock>> block_queue_stdout_;
    //std::queue<DataBlock> block_queue_file_x_;
};

#endif //_MTB_10_BLOCK_TRANSPORTER_H_

// End of the file
