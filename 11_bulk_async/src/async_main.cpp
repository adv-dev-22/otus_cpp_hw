#include "async_interface.h"
#include <iostream>

int main(int, char *[])
{
    auto h1 = async::connect(4);
    auto h2 = async::connect(3);

    async::receive(h1, "1", 1);
    async::receive(h2, "1\n", 2);

    async::receive(h1, "\n2\n3\n4\n5\n6\n{\na\n", 15);
    async::receive(h1, "b\nc\nd\n}\n89\n", 11);

    async::disconnect(h2);
    async::disconnect(h1);

    return 0;
}
