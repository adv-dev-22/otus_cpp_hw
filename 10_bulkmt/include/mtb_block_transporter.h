#ifndef _MTB_10_BLOCK_TRANSPORTER_H_
#define _MTB_10_BLOCK_TRANSPORTER_H_

#include "mtb_transporter_worker.h"
#include <thread>
#include <memory>

class MtbBlockTransporter final
{
public:
    MtbBlockTransporter();
    ~MtbBlockTransporter() = default;

    void start_threads();
    void conclude_threads();

    void join_threads();


    //  notify


private:
    std::thread thread_cout;
    std::thread thread_file_1;
    std::thread thread_file_2;

    std::unique_ptr<MtbTransporterWorkerStd>  up_worker_std_;
    std::unique_ptr<MtbTransporterWorkerFile> up_worker_file_1_;
    std::unique_ptr<MtbTransporterWorkerFile> up_worker_file_2_;

};

#endif //_MTB_10_BLOCK_TRANSPORTER_H_

// End of the file
