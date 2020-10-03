#include "fs_comparator_options.h"
#include <gtest/gtest.h>

TEST(test_blocks_number, basic) {

    // Allocate memory for command line input simulation
    constexpr int argc = 3;
    char ** argv = new char * [argc];
    for (int k = 0; k < argc; ++k)
        argv[k] = new char[100];

    // Copy input values for command line
    std::strcpy(argv[0], "run_fake");
    std::strcpy(argv[1], "--blocksize");
    std::strcpy(argv[2], "3");

    // Uses boost program options
    FsComparatorOptions fs_optns;
    fs_optns.parse(argc, argv);

    // Expected value validation
    EXPECT_EQ(fs_optns.block_size(), 3);

    // Create temporary file.
    // ..


//        FsBlocksNumberProxy(const std::string & full_name,
//                            const FsComparatorOptions & cmpr_options);
//        size_t get() const;


    // Remove temporary file.
    // ..

    // Free memory for command line input simulation.
    for (int k = 0; k < argc; ++k)
        delete[] argv[k];
    delete[] argv;
}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// End of the file
