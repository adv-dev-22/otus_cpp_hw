#ifndef _IP_PROCESSOR_H_
#define _IP_PROCESSOR_H_

#include "ip_loader.h"
#include <memory>
#include <vector>
#include <string>

using  std::unique_ptr;

/*! Manager class */
class IpProcessor {
public:
    IpProcessor();
    ~IpProcessor() = default;

    void run();

private:
    unique_ptr<IpDataLoader> up_ip_loader_;
    vector<vec_ui8> ip_pool_;

    void allocate_data_();
    void read_ippool_from_stdin_();
    void reverse_sort_();
};

#endif  //_IP_PROCESSOR_H_

// End of the file

