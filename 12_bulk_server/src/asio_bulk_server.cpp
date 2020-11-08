#include "asio_bulk_server.h"
#include "asio_bulk_session.h"

namespace asio_bulk_12
{

Server::Server(boost::asio::io_context& io_context, int port, int bulk_size):
acceptor_(io_context, tcp::endpoint(tcp::v4(), port)),
redirector_()
{
    do_accept_();
}

void Server::Server::do_accept_()
{
    auto accept_lambda = [this](boost::system::error_code ec, tcp::socket socket)
    {
        if (ec) return;

        std::make_shared<Session>(std::move(socket), redirector_)->start();
        do_accept_();
    };

    acceptor_.async_accept(accept_lambda);
}

}

// End of the file
