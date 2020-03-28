#include "fixed_sz_allocator.hpp"
#include <gtest/gtest.h>
#include <iostream>


TEST(reverse_allocator, base_operations) {

    using T = double;
    constexpr size_t n = 15;

   // reserve_allocator<T, n> allc_n;

//    T * data_0 = allc_n.allocate(4);
//    EXPECT_NE(data, nullptr);

//    T * data_1 = allc_n.allocate(10);
//    EXPECT_NE(data_1)





//    allc_n
//    allc_n.deallocate(data_0, 4);


}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// End of the file

