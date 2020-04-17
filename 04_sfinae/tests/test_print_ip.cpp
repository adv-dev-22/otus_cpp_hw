#include "../print_ip_04.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

template <typename T>
void test_print_ip(T value, std::string ref_result) {

    testing::internal::CaptureStdout();
    print_ip(value);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, ref_result);
}

TEST(test_all_results, ip) {

    test_print_ip(1234, "0.0.4.210\n");
    test_print_ip(char(-1), "255\n");
    test_print_ip(short(0), "0.0\n");
    test_print_ip(int(2130706433), "127.0.0.1\n");
    test_print_ip(8875824491850138409ll, "123.45.67.89.101.112.131.41\n");

    test_print_ip(std::string("221.23.45.210"), "221.23.45.210\n");

    test_print_ip(std::vector<uint8_t>({1}), "1\n");
    test_print_ip(std::vector<uint8_t>({22, 33}), "22.33\n");
    test_print_ip(std::vector<uint8_t>({129, 15, 0, 36}),"129.15.0.36\n");

    test_print_ip(std::list<uint8_t>({9, 0, 80, 10}), "9.0.80.10\n");
    test_print_ip(std::list<uint8_t>({81}), "81\n");
    test_print_ip(std::list<uint8_t>({5, 6, 7, 8, 9, 0, 11}), "5.6.7.8.9.0.11\n");

    test_print_ip(std::make_tuple(0, 1, 2, 3), "0.1.2.3\n");
    test_print_ip(std::make_tuple(233, 11, 2, 15, 49, 101, 223), "233.11.2.15.49.101.223\n");
    test_print_ip(std::make_tuple(221), "221\n");
}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

