#include "ip_processor.h"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <memory>

char ** my_argv;

TEST(test_all_results, ip) {

    const string full_file_name(my_argv[1]);
    std::cout << "full file name: " << full_file_name << std::endl;

    std::ifstream ifs;
    ifs.open(full_file_name, std::ifstream::in);

    EXPECT_TRUE(ifs.is_open());

    auto up_ip_proc = std::make_unique<IpProcessor>();
    up_ip_proc->run(ifs);

    ifs.close();
}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);

    my_argv = argv;

    return RUN_ALL_TESTS();
}


