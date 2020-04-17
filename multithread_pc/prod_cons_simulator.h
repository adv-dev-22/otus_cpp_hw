#ifndef _PC_SIMULATOR_H_
#define _PC_SIMULATOR_H_

#include "mlt_thr_data_server.h"
#include <cstddef>
#include <string>
#include <memory>
#include <pthread.h>

class ProdConsSimulator final {
public:
    ProdConsSimulator();
    ~ProdConsSimulator();

    void run();

    void set_producer_number(const size_t numb);
    void set_consumer_number(const size_t numb);

    void set_buffer_size(const size_t bsz);
    void set_worker_loop_size(const size_t lsz);

private:
    size_t produsers_numb_;
    size_t consumers_numb_;

    size_t max_buff_size_;
    size_t max_loop_size_;

    std::unique_ptr<MultiThreadDataServer> data_server_;

    std::unique_ptr<pthread_t []> prod_threads_;
    std::unique_ptr<pthread_t []> cons_threads_;
};

#endif // _PC_SIMULATOR_H_
