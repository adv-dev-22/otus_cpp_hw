#include "mtb_transporter_worker.h"
#include <iostream>
#include <chrono>
#include <thread>

MtbTransporterWorkerBase::MtbTransporterWorkerBase():
processing_is_finished_(false)
{
}

void MtbTransporterWorkerBase::conclude_processing() noexcept
{
    processing_is_finished_ = true;
}

MtbTransporterWorkerStd::MtbTransporterWorkerStd()
{
}

void MtbTransporterWorkerStd::operator() ()
{
    std::cout << "std thread started " << std::endl;
    while (!processing_is_finished_)
    {

        std::cout << processing_is_finished_ << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

    }
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
