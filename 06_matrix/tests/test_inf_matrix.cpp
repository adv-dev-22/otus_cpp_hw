#include "../infinite_row.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

template <typename T, T DefaultValue>
void  test_infinite_row() {

    InfiniteRow<T, DefaultValue> inf_row;
    EXPECT_EQ(inf_row.size(), 0);

    const T value = static_cast<const InfiniteRow<T, DefaultValue> *>(&inf_row)->operator[](222);
    EXPECT_EQ(value, DefaultValue);
    EXPECT_EQ(inf_row.size(), 0);


    inf_row[23456] = 777;
    EXPECT_EQ(inf_row[23456], 777);
    EXPECT_EQ(inf_row[222], DefaultValue);

    // ..
}

TEST(test_infinite_row, basic) {

    test_infinite_row<int, 25>();
    //test_infinite_row<char, '.'>();
}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// End of the file

