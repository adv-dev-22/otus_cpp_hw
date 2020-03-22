#include "reserve_allocator.hpp"
#include <gtest/gtest.h>
#include <iostream>


TEST(allocator, base_operations) {

    constexpr size_t n = 15;
    reserve_allocator<double, n> allc_n;





}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// End of the file

