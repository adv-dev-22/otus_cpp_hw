#include "fixed_sz_allocator.hpp"
#include <gtest/gtest.h>
#include <iostream>


TEST(allocator, base_operations) {

    using T = double;
    constexpr size_t n = 15;

    reserve_allocator<T, n> fxd_alloc;

    // Elements can be allocates just one per request
    for (size_t i = 2; i < n; ++i) {
        EXPECT_THROW(fxd_alloc.allocate(i), std::out_of_range);
    }

    // The number of allocated elements can not exceed n
    for (size_t i = 0; i < n; ++i) {
        EXPECT_NO_THROW(fxd_alloc.allocate(1));
    }

    // One more allocation should fail
    EXPECT_THROW(fxd_alloc.allocate(1), std::out_of_range);
}

TEST(allocator, insert_operations) {

    using T = double;
    constexpr size_t n = 15;

    reserve_allocator<T, n> fxd_alloc;

    T * base_addr = fxd_alloc.allocate(1);

    for (size_t i = 1; i < n; ++i) {
        T * next_addr = fxd_alloc.allocate(1);
        EXPECT_EQ((next_addr - base_addr), n - i);
    }
}

TEST(allocator, remove_operations) {

    using T = int;
    constexpr size_t n = 10;

    reserve_allocator<T, n> fxd_alloc;

    // 0123456789| <-- free
    T * addr0 = fxd_alloc.allocate(1); // 0
    // 912345678|0
    T * addr1 = fxd_alloc.allocate(1); // 9
    // 81234567|90
    T * addr2 = fxd_alloc.allocate(1); // 8
    // 7123456|890
    T * addr3 = fxd_alloc.allocate(1); // 7
    // 612345|7890
    T * addr4 = fxd_alloc.allocate(1); // 6
    // 51234|67890
    T * addr5 = fxd_alloc.allocate(1); // 5
    // 4123|567890

    fxd_alloc.construct(addr4, 33);
    EXPECT_EQ(*addr4, 33);

    fxd_alloc.destroy(addr4);
    // 4123|567890
    fxd_alloc.deallocate(addr4, 1); // addr4 == 6
    addr4 = nullptr;
    // 41236|67890
    fxd_alloc.deallocate(addr2, 1); // addr2 == 8
    addr2 = nullptr;
    // 412368|7890

    // 412368|7890
    T * addr6 = fxd_alloc.allocate(1); // 4
    // 81236|47890
    T * addr7 = fxd_alloc.allocate(1); // 8
    // 6123|847890
    T * addr8 = fxd_alloc.allocate(1); // 6
    // 312|6847890

    EXPECT_EQ(addr6 - addr0, 4);
    EXPECT_EQ(addr7 - addr0, 8);
    EXPECT_EQ(addr8 - addr0, 6);
}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// End of the file

