#pragma once

#include <boost/asio.hpp>
#include "asio_bulk_redirector.h"

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
    Redirector redirector_;

    void do_accept_();
};

}

// End of the file
