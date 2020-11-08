#pragma once

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace asio_bulk_12
{

class Server
{
public:
    Server(boost::asio::io_context& io_context, int port, int bulk_size);
    ~Server() = default;

private:
    tcp::acceptor acceptor_;

    void do_accept_();
};

}

// End of the file
