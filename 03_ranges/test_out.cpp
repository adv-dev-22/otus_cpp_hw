#include <gtest/gtest.h>

TEST(test_all_results, ip) {

    EXPECT_GT(1, 0);
}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


