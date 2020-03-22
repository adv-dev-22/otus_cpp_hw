#include "ip_processor.h"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <cstdlib>
#include <cstdio>

char ** my_argv;

TEST(test_all_results, ip) {

    // Filenames in and out.
    const string full_file_name(my_argv[1]);
    const string  out_file_name(my_argv[2]);

    std::ifstream ifs;
    ifs.open(full_file_name, std::ifstream::in);

    std::ofstream ofs;
    ofs.open(out_file_name, std::ofstream::out);

    EXPECT_TRUE(ifs.is_open());
    EXPECT_TRUE(ofs.is_open());

    // IpProcessor in testing mode works with file i/o streams
    auto up_ip_proc = std::make_unique<IpProcessor>();
    up_ip_proc->run(ifs, ofs);

    ifs.close();
    ofs.close();

    // Run md5sum utillity
    const std::string md5_sum_file("md5_sum.txt");
    std::string command = std::string("md5sum ") + out_file_name + std::string(" > ") + md5_sum_file;
    std::system(command.c_str());

    // Read md5sum value
    std::ifstream ifs_md5;
    ifs_md5.open(md5_sum_file, std::ifstream::in);
    EXPECT_TRUE(ifs_md5.is_open());
    std::string str_sum;
    ifs_md5 >> str_sum;

    // Reference hash
    const string reference_md5("24e7a7b2270daee89c64d3ca5fb3da1a");

    EXPECT_EQ(reference_md5, str_sum);

    // Clean up
    std::remove(out_file_name.c_str());
    std::remove(md5_sum_file.c_str());
}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);

    my_argv = argv;

    return RUN_ALL_TESTS();
}

//std::cout << "full file name: " << full_file_name << std::endl;

