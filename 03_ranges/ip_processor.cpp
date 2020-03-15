#include "ip_processor.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ostream>
#include <range/v3/all.hpp>
#include <range/v3/algorithm/sort.hpp>

using  std::cout;
using  std::endl;
using  std::make_unique;
using  std::ostream;

///////////////////////////////////////////////////////////////////////////////

namespace std {
std::ostream & operator<< (std::ostream & os, const vec_ui8 & vs) {

    os << (unsigned int) vs.front();
    ranges::for_each(ranges::views::counted(ranges::begin(vs) + 1, 3),
                     [& os](const uint8_t & s1) {os << "." << (unsigned int) s1;});
    os << endl;

    return os;
}
}

void print(const vector<vec_ui8> & ippool) {
    std::copy(ippool.cbegin(), ippool.cend(), std::ostream_iterator<vec_ui8>(std::cout));
}

///////////////////////////////////////////////////////////////////////////////

IpProcessor::IpProcessor():
up_ip_loader_(nullptr),
ip_pool_(0) {

}

void IpProcessor::run() {

    allocate_data_();
    read_ippool_from_stdin_();

    reverse_sort_();

    // *.*.*.*
    print(ip_pool_);

    // 1.*.*.*
    auto filtered_1_x_x_x = ip_pool_ |
                            ranges::views::filter([](const vec_ui8 & item) {
                                if (1 == item.at(0)) return true;
                                return false;}) |
                            ranges::to<std::vector<vec_ui8>>();
    print(filtered_1_x_x_x);

    // 46.70.*.*
    auto filtered_46_70_x_x = ip_pool_ |
                              ranges::views::filter([](const vec_ui8 & item) {
                                  if (46 == item.at(0) && 70 == item.at(1)) return true;
                                  return false;}) |
                              ranges::to<std::vector<vec_ui8>>();
    print(filtered_46_70_x_x);

    // 46 is at least at one of the (*) in ip *.*.*.*
    auto filtered_any_46 = ip_pool_ |
                           ranges::views::filter([](const vec_ui8 & item) {
                               return item.cend() != std::find(item.cbegin(), item.cend(),46);}) |
                           ranges::to<std::vector<vec_ui8>>();
    print(filtered_any_46);
}

void IpProcessor::allocate_data_() {
    up_ip_loader_ = make_unique<IpDataLoader>();
}

void IpProcessor::read_ippool_from_stdin_() {

    up_ip_loader_->read_from_stdin();
    ip_pool_ = up_ip_loader_->take_ip_pool();
}

static bool ccomparator(const vec_ui8 & left_vs,
                        const vec_ui8 & right_vs,
                        std::size_t counter = 0) {

    if (4 == counter) return false;

    const uint8_t left_byte_k  = left_vs.at(counter);
    const uint8_t right_byte_k = right_vs.at(counter);

    if (left_byte_k > right_byte_k) return true;

    if (left_byte_k == right_byte_k) return ccomparator(left_vs, right_vs, counter + 1);

    return false;
}

void IpProcessor::reverse_sort_() {

    // Reverse lexicographically sort
    ranges::sort(ip_pool_, [](const vec_ui8 & left_item, const vec_ui8 & right_item) {
                                return ccomparator(left_item, right_item);});
}

// End of the file
