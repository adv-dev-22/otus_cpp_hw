#include "async_interface.h"
#include <iostream>
#include <sstream>

namespace async {

handle_t connect(std::size_t bulk)
{
    //static std::map<size_t,  > ;

    // TODO:

    return nullptr;
}

void receive(handle_t handle, const char * data, std::size_t size)
{
    std::stringstream ss;
    ss << data;

    std::string buffer;
    while (std::getline(ss, buffer))
    {
        std::cout << buffer << std::endl;
    }

}

void disconnect(handle_t handle)
{

    // TODO:

}

}
