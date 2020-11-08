#pragma once

#include <memory>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace asio_bulk_12
{

class Session : public std::enable_shared_from_this<Session>
{
public:
    Session(tcp::socket socket);
    ~Session() = default;

    void start();

private:
    tcp::socket socket_;
    static constexpr size_t max_length_ = 2048;
    char data_[max_length_];

    void read_socket_();
    void redirect_();
};

}

// End of the file
