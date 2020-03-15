#ifndef _IP_DATA_LOADER_H_
#define _IP_DATA_LOADER_H_

#include <vector>
#include <string>
#include <cstdint>

using  std::vector;
using  std::string;
using  vec_ui8 = vector<uint8_t>;

class IpDataLoader {
public:
    IpDataLoader();
    virtual ~IpDataLoader() = default;

    void  read_from_stdin();
    vector<vec_ui8>  take_ip_pool() noexcept;

private:
    vector<vec_ui8>  vvs_ip_pool_;
};

#endif  // _IP_DATA_LOADER_H_

// End of the file

