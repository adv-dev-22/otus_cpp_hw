#ifndef _MULTI_PROC_DATA_SERVER_H_
#define _MULTI_PROC_DATA_SERVER_H_

#include <string>
#include <pthread.h>

class MultiThreadDataServer {
public:
    MultiThreadDataServer();
    virtual ~MultiThreadDataServer();

    void set_buffer_size(const size_t bsz);
    void set_worker_loop_size(const size_t lsz);

    size_t worker_loop_size() const;

    void push(const std::string msg, const size_t ms);
    void pop (const std::string msg, const size_t ms);

private:
    int ibuffer_;

    size_t max_buff_size_;
    size_t max_loop_size_;

    pthread_mutex_t mtx_lock_;

    pthread_cond_t  consumer_cond_;
    pthread_cond_t  producer_cond_;
};

#endif // _MULTI_PROC_DATA_SERVER_H_

// End of the file
