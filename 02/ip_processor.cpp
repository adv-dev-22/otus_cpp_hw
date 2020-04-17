#include "ip_processor.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ostream>

using  std::cout;
using  std::endl;
using  std::make_unique;
using  std::ostream;

///////////////////////////////////////////////////////////////////////////////

namespace std {
std::ostream & operator<< (std::ostream & os, const std::vector<std::string> & vs) {

    os << vs.front();
    std::for_each(vs.cbegin() + 1, vs.cend(), [& os](const string & s1) {os << "." << s1;});
    os << endl;

    return os;
}
}

template <typename Predicate>
void print_any_condition(const vector<vec_str> & ippool, Predicate P1) {

    std::copy_if(ippool.cbegin(),
                 ippool.cend(),
                 std::ostream_iterator<vec_str>(std::cout),
                 P1);
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
    print_any_condition(ip_pool_,
                        [](const vec_str & ){return true;});
    // 1.*.*.*
    print_any_condition(ip_pool_,
                        [](const vec_str & item) {
                            if (1 == std::stoi(item.at(0))) return true;
                            return false;
                        });
    // 46.70.*.*
    print_any_condition(ip_pool_,
                        [](const vec_str & item) {
                            if (46 == std::stoi(item.at(0)) &&
                                70 == std::stoi(item.at(1))) return true;
                            return false;
                        });

    // 46 is at least at one of the (*) in ip *.*.*.*
    print_any_condition(ip_pool_,
                        [](const vec_str & item) {
                            return item.cend() != std::find(item.cbegin(),
                                                            item.cend(),
                                                            string("46"));
                        });
}

void IpProcessor::allocate_data_() {
    up_ip_loader_ = make_unique<IpDataLoader>();
}

void IpProcessor::read_ippool_from_stdin_() {

    up_ip_loader_->read_from_stdin();
    ip_pool_ = up_ip_loader_->get_ip_pool();
}

static bool ccomparator(const vec_str & left_vs,
                            const vec_str & right_vs,
                            std::size_t counter = 0) {

    if (4 == counter) return false;

    const size_t left_byte_k  = std::stoi(left_vs.at(counter));
    const size_t right_byte_k = std::stoi(right_vs.at(counter));

    if (left_byte_k > right_byte_k) {
        return true;
    }

    if (left_byte_k == right_byte_k) {
        return ccomparator(left_vs, right_vs, counter + 1);
    }

    return false;
}

void IpProcessor::reverse_sort_() {

    // Reverse lexicographically sort
    std::sort(ip_pool_.begin(),
              ip_pool_.end(),
              [](const vec_str & left_item, const vec_str & right_item) {
                  return ccomparator(left_item, right_item);
              });
}

// End of the file

