#pragma once

#include <memory>

namespace asio_bulk_12
{

class Session : public std::enable_shared_from_this<Session>
{
public:
    Session();
    ~Session() = default;

private:


//    tcp::socket socket_;
//    enum  { max_length = 1024 };
//    char data_[max_length];

};

}

// End of the file
