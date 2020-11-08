#pragma once

#include <memory>
#include <string>
#include <boost/asio.hpp>
#include "asio_bulk_redirector.h"

using boost::asio::ip::tcp;

namespace asio_bulk_12
{

std::string get_ip_port_id(tcp::socket);

class Session : public std::enable_shared_from_this<Session>
{
public:
    Session(tcp::socket socket, Redirector & redirector);
    ~Session() = default;

    void start();

private:
    tcp::socket socket_;
    Redirector & redirector_;

    static constexpr size_t max_length_ = 2048;
    char data_[max_length_];

    void read_socket_();
    void redirect_();
};

}

// End of the file
