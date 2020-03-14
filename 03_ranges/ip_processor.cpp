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
std::ostream & operator<< (std::ostream & os, const vec_ui8 & vs) {

    os << (unsigned int) vs.front();
    std::for_each(vs.cbegin() + 1, vs.cend(), [& os](const uint8_t & s1) {
                  os << "." << (unsigned int) s1;});
    os << endl;

    return os;
}
}

template <typename Predicate>
void print_any_condition(const vector<vec_ui8> & ippool, Predicate P1) {

    std::copy_if(ippool.cbegin(),
                 ippool.cend(),
                 std::ostream_iterator<vec_ui8>(std::cout),
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

//    reverse_sort_();


//    for (auto itr = ip_pool_.begin(); itr != ip_pool_.end(); ++itr) {
//        std::cout << (unsigned int) (*itr).at(0) << std::endl;
//    }

    // *.*.*.*
    print_any_condition(ip_pool_,
                        [](const vec_ui8 & ){return true;});
//    // 1.*.*.*
//    print_any_condition(ip_pool_,
//                        [](const vec_uchar & item) {
//                            if (1 == item.at(0)) return true;
//                            return false;
//                        });
//    // 46.70.*.*
//    print_any_condition(ip_pool_,
//                        [](const vec_uchar & item) {
//                            if (46 == item.at(0) &&
//                                70 == item.at(1)) return true;
//                            return false;
//                        });

//    // 46 is at least at one of the (*) in ip *.*.*.*
//    print_any_condition(ip_pool_,
//                        [](const vec_uchar & item) {
//                            return item.cend() != std::find(item.cbegin(),
//                                                            item.cend(),
//                                                            46);
//                        });
}

void IpProcessor::allocate_data_() {
    up_ip_loader_ = make_unique<IpDataLoader>();
}

void IpProcessor::read_ippool_from_stdin_() {

    up_ip_loader_->read_from_stdin();
    ip_pool_ = up_ip_loader_->get_ip_pool();
}

//static bool ccomparator(const vec_uchar & left_vs,
//                        const vec_uchar & right_vs,
//                        std::size_t counter = 0) {

//    if (4 == counter) return false;

//    const unsigned char left_byte_k  = left_vs.at(counter);
//    const unsigned char right_byte_k = right_vs.at(counter);

//    if (left_byte_k > right_byte_k) {
//        return true;
//    }

//    if (left_byte_k == right_byte_k) {
//        return ccomparator(left_vs, right_vs, counter + 1);
//    }

//    return false;
//}

void IpProcessor::reverse_sort_() {

//    // Reverse lexicographically sort
//    std::sort(ip_pool_.begin(),
//              ip_pool_.end(),
//              [](const vec_uchar & left_item, const vec_uchar & right_item) {
//                  return ccomparator(left_item, right_item);
//              });
}

// End of the file

