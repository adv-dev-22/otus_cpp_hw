#include "../effective_cell.h"
#include "../infinite_row.h"
//#include "../infinite_matrix.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

template <typename T, T DefaultValue>
void test_effective_cell() {

   // CellObserver<T, DefaultValue> cell_observer;


    // ..
}

template <typename T, T DefaultValue>
void test_infinite_row() {

    InfiniteRow<T, DefaultValue> inf_row;
    EXPECT_EQ(inf_row.size(), 0);

    // Set default value. Cell keeps to be free.
    const T v0 = DefaultValue;
    inf_row[225] = v0;
    T b0 = inf_row[255];
    EXPECT_EQ(b0, v0);
    EXPECT_EQ(inf_row.size(), 0);

    // It should return default value and it should not increase the size.
    T a = inf_row[337];
    EXPECT_EQ(a, DefaultValue);
    EXPECT_EQ(inf_row.size(), 0);

    // Initial insert increase the size and change the value
    inf_row[23456] = 777;
    T b = inf_row[23456];
    EXPECT_EQ(b, 777);
    EXPECT_EQ(inf_row.size(), 1);

    // Set in the same place. Value is changed, size
    const T v2 = 555;
    inf_row[23456] = v2;
    T b2 = inf_row[23456];
    EXPECT_EQ(b2, v2);
    EXPECT_EQ(inf_row.size(), 1);

    // Set in the same place default value. Cell becomes free.
    const T v3 = DefaultValue;
    inf_row[23456] = v3;
    T b3 = inf_row[23456];
    EXPECT_EQ(b3, v3);
    EXPECT_EQ(inf_row.size(), 0);
}

//template <typename T, T DefaultValue>
//void test_infinite_matrix() {

//    InfiniteMatrix<T, DefaultValue> inf_matrix;
//    EXPECT_EQ(inf_matrix.size(), 0);

//}

TEST(test_effective_cell, basic) {
    test_effective_cell<int, 172>();
}

TEST(test_infinite_row, basic) {
    test_infinite_row<int, 25>();
}

//TEST(test_infinite_matrix, basic) {
//    test_infinite_matrix<int, 99>();
//}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// End of the file
