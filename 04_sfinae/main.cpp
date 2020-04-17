#include <iostream>
#include <string>
#include <map>
#include "print_ip_04.hpp"

int main(int argc, char *argv[]) {

    print_ip(1234);
    print_ip(char(-1));
    print_ip(short(0));
    print_ip(int(2130706433));
    print_ip(8875824491850138409ll);

    print_ip(std::string("221.23.45.210"));

    print_ip(std::vector<uint8_t>({129, 15, 0, 36}));
    print_ip(std::vector<uint8_t>({1}));
    print_ip(std::vector<uint8_t>({22, 33}));

    print_ip(std::list<uint8_t>({9, 0, 80, 10}));
    print_ip(std::list<uint8_t>({81}));
    print_ip(std::list<uint8_t>({5, 6, 7, 8, 9, 0, 11}));

    print_ip(std::make_tuple(0, 1, 2, 3));
    print_ip(std::make_tuple(233, 11, 2, 15, 49, 101, 223));
    print_ip(std::make_tuple(221));

    return 0;
}

