#include "ip_loader.h"
#include <iostream>
#include <vector>
#include <string>
#include <meta/meta.hpp>
#include <range/v3/algorithm/sort.hpp>
#include <range/v3/all.hpp>
#include <range/v3/algorithm.hpp>
#include <range/v3/iterator.hpp>
#include <range/v3/view/split.hpp>


IpDataLoader::IpDataLoader():
vvs_ip_pool_(0) {
}

void IpDataLoader::read_from_stdin() {

    try {
        for (string line; std::getline(std::cin, line); ) {

            auto words = line | ranges::views::split('\t') | ranges::to<std::vector<std::string>>();

            auto str_digits = words.at(0) | ranges::views::split('.') | ranges::to<std::vector<string>>();

            vec_ui8 ui8_digits = str_digits |
                                 ranges::views::transform([](const string s) {
                                    return static_cast<uint8_t>(std::stoi(s));}) |
                                 ranges::to<vec_ui8>();

            vvs_ip_pool_.push_back(std::move(ui8_digits));
        }
    }
    catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}

vector<vec_ui8> IpDataLoader::take_ip_pool() noexcept {
    return std::move(vvs_ip_pool_);
}

// End of the file
