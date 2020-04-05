#include <QCoreApplication>
#include <iostream>
#include <string>
#include "print_ip_04.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    print_ip<int>(1234);
    print_ip<char>(-1);
    print_ip<short>(0);
    print_ip<int>(2130706433);
    print_ip<long long>(8875824491850138409);
    print_ip<std::string>("221.23.45.210");
    print_ip<std::vector<uint8_t>>({129, 15, 0, 36});
    print_ip<std::list<uint8_t>>({9, 0, 80, 10});
    //print_ip<std::tuple<int, int, int, int>>(std::make_tuple(0,1,2,3));

    return a.exec();
}
