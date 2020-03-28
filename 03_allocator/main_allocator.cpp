#include "reserve_allocator.hpp"
#include <iostream>
#include <map>

int main(int argc, char * argv []) {

    // Preliminary demo API
    elementwise_block_allocator<double> alloc;

    double * darr0 = alloc.allocate(2);
    double * darr1 = alloc.allocate(1);
    double * darr2 = alloc.allocate(13);

    alloc.construct(darr0,     2.0);
    alloc.construct(darr0 + 1, 3.0);
    std::cout << darr0[0] << std::endl;
    std::cout << darr0[1] << std::endl;
    alloc.destroy(darr0 + 1);
    alloc.destroy(darr0);

    alloc.construct(darr2 + 12, -42.);
    std::cout << darr2[12] << std::endl;
    alloc.destroy(darr2 + 12);

    alloc.deallocate(darr2, 0);
    alloc.deallocate(darr1, 0);
    alloc.deallocate(darr0, 0);

    // 1. Create std::map
    std::map<int, int>  standard_map;
    const size_t n = 10;
    int value = 1;
    standard_map.emplace(0, value);

    for (int i = 1; i < n; ++i) {
        value *= i;
        standard_map.emplace(i, value);
    }

    for (auto item : standard_map) {
        std::cout << item.first << " --> " << item.second << std::endl;
    }




    return 0;
}



// End of the file

