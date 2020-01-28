#include <gtest/gtest.h>
#include "vers_lib.h"

TEST(test_vers_gtest, valid_versions) {

    EXPECT_GT(version_patch(), 0);
    EXPECT_GE(version_minor(), 0);
    EXPECT_GE(version_major(), 0);
}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// End of the file
