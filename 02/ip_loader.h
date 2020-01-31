#ifndef _IP_DATA_LOADER_H_
#define _IP_DATA_LOADER_H_

#include <vector>
#include <string>

using  std::vector;
using  std::string;
using  vec_str = vector<string>;

class IpDataLoader {
public:
    IpDataLoader();
    virtual ~IpDataLoader() = default;

    void  read_from_stdin();

    vector<vec_str>  get_ip_pool() noexcept;

private:
    vector<vec_str>  vvs_ip_pool_;
};

#endif  // _IP_DATA_LOADER_H_

// End of the file

