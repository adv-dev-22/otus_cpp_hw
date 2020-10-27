#include "async_interface.h"
#include <iostream>

int main(int, char *[])
{
    const std::size_t bulk_sz = 5;

    auto h  = async::connect(bulk_sz);
//    auto h2 = async::connect(bulk_sz);

    async::receive(h, "1", 1);
//    async::receive(h2, "1\n", 2);

    async::receive(h, "\n2\n3\n4\n5\n6\n{\na\n", 15);
    async::receive(h, "b\nc\nd\n}\n89\n", 11);

//    async::disconnect(h);
//    async::disconnect(h2);

    return 0;
}
