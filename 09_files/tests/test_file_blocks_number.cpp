#include "fs_comparator_options.h"
#include "fs_blocks_number_proxy.h"
#include "fs_file_block_proxy.h"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <cstdio>

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
    const std::string test_file_01("fs_test_blocks_number.txt");
    std::ofstream ofs;
    ofs.open(test_file_01, std::ofstream::out);
    // 97 bytes
    ofs << "+This file contains several block numbers." << std::endl;
    ofs << "And explicit blocks number depends on the block size " << std::endl;
    ofs.close();

    FsBlocksNumberProxy blocks_number(test_file_01, fs_optns);
    const size_t first_request_number  = blocks_number.get();
    const size_t second_request_number = blocks_number.get();
    EXPECT_EQ(first_request_number,  33);
    EXPECT_EQ(second_request_number, 33);

    // Remove temporary file.
    std::remove(test_file_01.c_str());

    // Free memory for command line input simulation.
    for (int k = 0; k < argc; ++k)
        delete[] argv[k];
    delete[] argv;
}

TEST(test_file_proxy, basic) {

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
    const std::string test_file_02("fs_test_block_hash.txt");
    std::ofstream ofs;
    ofs.open(test_file_02, std::ofstream::out);
    // 95 bytes
    ofs << "+This file contains several block numbers." << std::endl;
    ofs << "And explicit blocks number depends on the block size";// << std::endl;
    ofs.close();

    constexpr size_t offset = 5; //31;
    FsFileBlockProxy fs_block_proxy(test_file_02, fs_optns, offset);

    std::cout << " from test: " << fs_block_proxy.get_hash() << std::endl;


    //const size_t first_request_number  = blocks_number.get();
    //const size_t second_request_number = blocks_number.get();
    //EXPECT_EQ(first_request_number,  33);
    //EXPECT_EQ(second_request_number, 33);

    // Remove temporary file.
    std::remove(test_file_02.c_str());

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
