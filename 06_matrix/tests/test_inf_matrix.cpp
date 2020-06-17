#include "../cell_observer.h"
#include "../infinite_row.h"
#include "../infinite_matrix.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

template <typename T, T DefaultValue>
void test_cell_observer() {

   // CellObserver<T, DefaultValue> cell_observer;


    // ..
}

template <typename T, T DefaultValue>
void test_infinite_row() {

    InfiniteRow<T, DefaultValue> inf_row;
    EXPECT_EQ(inf_row.size(), 0);

    // It should return default value and it should not increase the size.
    T a = inf_row[337];
    EXPECT_EQ(a, DefaultValue);
    EXPECT_EQ(inf_row.size(), 0);

    inf_row[23456] = 777;
    T b = inf_row[23456];
    EXPECT_EQ(b, 777);
    EXPECT_EQ(inf_row.size(), 1);

    EXPECT_EQ(inf_row[23456], 777);
    EXPECT_EQ(inf_row.size(), 1);

    EXPECT_EQ(777, inf_row[23456]);
    EXPECT_EQ(inf_row.size(), 1);


    // ..
}

//template <typename T, T DefaultValue>
//void test_infinite_matrix() {

//    InfiniteMatrix<T, DefaultValue> inf_matrix;
//    EXPECT_EQ(inf_matrix.size(), 0);

//}

TEST(test_cell_observer, basic) {
    test_cell_observer<int, 172>();
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



//    const T value = static_cast<const InfiniteRow<T, DefaultValue> *>(&inf_row)->operator[](222);
//    EXPECT_EQ(value, DefaultValue);
//    EXPECT_EQ(inf_row.size(), 0);
