#include "flexible_allocator.hpp"
#include "fixed_sz_allocator.hpp"
#include "custom_container.hpp"
#include "reserved_container.hpp"
#include <iostream>
#include <map>

int main(int argc, char * argv []) {

    // 0. Preliminary demo API
    {
    elementwise_block_allocator<double> alloc;

    double * darr0 = alloc.allocate(2);
    double * darr1 = alloc.allocate(1);
    double * darr2 = alloc.allocate(13);

    alloc.construct(darr0,     2.0);
    alloc.construct(darr0 + 1, 3.0);
    //std::cout << darr0[0] << std::endl;
    //std::cout << darr0[1] << std::endl;
    alloc.destroy(darr0 + 1);
    alloc.destroy(darr0);

    alloc.construct(darr2 + 12, -42.);
    //std::cout << darr2[12] << std::endl;
    alloc.destroy(darr2 + 12);

    alloc.deallocate(darr2, 0);
    alloc.deallocate(darr1, 0);
    alloc.deallocate(darr0, 0);
    }

    // 1. Create std::map
    {
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
    }

    // 2. Create std::map with custom (flexible) allocator
    {
    std::cout << std::endl << "start std::map with custom allocator" << std::endl;
    std::map<int, int, std::less<int>,
             elementwise_block_allocator<std::pair<const int, int>>> cstm_map;

    const size_t n = 10;
    int value = 1;
    cstm_map.emplace(0, value);

    for (int i = 1; i < n; ++i) {
        value *= i;
        cstm_map.emplace(i, value);
    }
    for (auto item : cstm_map) {
        std::cout << item.first << " x-> " << item.second << std::endl;
    }
    }

    // 3. Create std::map with custom (fixed size, fast) allocator
    {
    constexpr size_t n = 10;
    std::cout << std::endl << "start std::map with reserving allocator" << std::endl;
    std::map<int, int, std::less<int>,
             reserve_allocator<std::pair<const int, int>, n> > rsrv_map;

    int value = 1;
    rsrv_map.emplace(0, value);

    for (int i = 1; i < n; ++i) {
        value *= i;
        rsrv_map.emplace(i, value);
    }
    for (auto item : rsrv_map) {
        std::cout << item.first << " -+> " << item.second << std::endl;
    }
    }

    // 4. Create custom container with std::allocator
    {
    const size_t n = 10;
    CustomContainer<int> cont_std_alc;
    for (size_t i = 0; i < n; ++i) {
        cont_std_alc.push_back(i);
    }

    cont_std_alc.to_begin();
    std::cout << cont_std_alc.current_item() << std::endl;
    for ( ; cont_std_alc.next(); ) {
        std::cout << cont_std_alc.current_item() << std::endl;
    }
    }

    // 5. Create custom container with (fixed size) allocator
    {
    std::cout << std::endl << "start custom container with reserving allocator" << std::endl;

    constexpr size_t n = 10;
    ReservedContainer<int, n> cont_reserved_alc;

    for (size_t i = 0; i < n; ++i) {
        cont_reserved_alc.push_back(i);
    }

    cont_reserved_alc.to_begin();
    std::cout << cont_reserved_alc.current_item() << std::endl;
    for ( ; cont_reserved_alc.next(); ) {
        std::cout << cont_reserved_alc.current_item() << std::endl;
    }
    }

    return 0;
}

// End of the file

