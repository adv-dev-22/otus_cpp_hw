#include "asio_bulk_controller.h"
#include <iostream>

namespace asio_bulk_12
{

int Controller::run(int argc, char * argv [])
{
    try
    {
        if (argc != 3)
        {
            std::cerr << "Wrong number of arguments." << std::endl;
            std::cerr << "run_asio_server <port> <bulk_size>" << std::endl;
            return 1;
        }

        //boost::asio::io_context io_context;

        //server server(io_context, std::atoi(argv[1]));

        //io_context.run();
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
}

}

// End of the file
