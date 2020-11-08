#include "asio_bulk_session.h"
#include <iostream>

namespace asio_bulk_12
{

std::string get_ip_port_id(tcp::socket socket1)
{
    auto ep = socket1.remote_endpoint();
    auto x = ep.address().to_string() + std::string(":") + std::to_string(ep.port());
    return x;
}


Session::Session(tcp::socket socket, Redirector & redirector):
socket_(std::move(socket)),
redirector_(redirector)
{
}

void Session::start()
{
    //redirect_.add_epoint(x);

    read_socket_();
}

void Session::read_socket_()
{
    auto self(shared_from_this());

    auto callback_repeat = [this, self](boost::system::error_code ec, std::size_t length) -> void
    {
        if (ec) return;

        // mtx lock
        // redirect set active

        //redirect_(std::string);
        std::cout << "receive " << length << " =" << std::string{data_, length} << std::endl;
        // mtx unlock

        read_socket_();
    };

    socket_.async_read_some(boost::asio::buffer(data_, max_length_), callback_repeat);
}

void Session::redirect_()
{


}

}

// End of the file
