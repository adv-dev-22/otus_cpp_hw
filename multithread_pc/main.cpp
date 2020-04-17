#include "prod_cons_simulator.h"
#include <memory>
#include <iostream>

void print_help() {

    std::cout << "4 input parameters are required:" << std::endl;
    std::cout << "producers number (int)" << std::endl;
    std::cout << "consumers number (int)" << std::endl;
    std::cout << "maximal buffer size (int)" << std::endl;
    std::cout << "number of producer/consumer steps in the loop (int)" << std::endl;
}

int main(int argc, char * argv []) {

    if (argc != 5) {
        print_help();
        return 0;
    }

    auto up_pcsimulator = std::make_unique<ProdConsSimulator>();

    up_pcsimulator->set_producer_number(std::stoi(std::string(argv[1])));
    up_pcsimulator->set_consumer_number(std::stoi(std::string(argv[2])));
    up_pcsimulator->set_buffer_size(std::stoi(std::string(argv[3])));
    up_pcsimulator->set_worker_loop_size(std::stoi(std::string(argv[4])));

    up_pcsimulator->run();

    return 0;
}


// End of the file

