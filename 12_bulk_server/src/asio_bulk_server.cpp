#include "asio_bulk_server.h"

namespace asio_bulk_12
{

Server::Server(boost::asio::io_context& io_context, int port):
acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
{
    do_accept_();
}

void Server::Server::do_accept_()
{
    auto accept_lambda = [this](boost::system::error_code ec, tcp::socket socket)
    {
        //if (!ec)
           // std::make_shared<session>(std::move(socket))->start();

        do_accept_();
    };

    acceptor_.async_accept(accept_lambda);
}

}

// End of the file
