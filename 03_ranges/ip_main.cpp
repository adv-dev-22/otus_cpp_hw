#include "ip_processor.h"
#include <iostream>
#include <memory>

using  std::unique_ptr;
using  std::make_unique;

int main(int argc, char * argv []) {

    auto up_ip_proc = make_unique<IpProcessor>();
    up_ip_proc->run(std::cin, std::cout);

    return 0;
}

