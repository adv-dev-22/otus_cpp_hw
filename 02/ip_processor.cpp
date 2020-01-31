#include "ip_processor.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ostream>

using  std::cout;
using  std::endl;
using  std::make_unique;
using  std::ostream;

using namespace std;

///////////////////////////////////////////////////////////////////////////////

namespace std {
std::ostream & operator<< (std::ostream & os, const std::vector<std::string> & vs) {

    os << vs.front();
    std::for_each(vs.cbegin() + 1, vs.cend(), [& os](const string & s1){os << "." << s1;});
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




// Garbage

//void IpProcessor::print_first_byte_eq_1_() {

//    print_any_condition(ip_pool_, [](const vec_str & item) {
//                             if (1 == std::stoi(item.at(0))) return true;
//                                return false;
//                          });

////    std::copy_if(ip_pool_.cbegin(),
////                 ip_pool_.cend(),
////                 std::ostream_iterator<vec_str>(std::cout),
////                 [](const vec_str & item) {
////                     if (1 == std::stoi(item.at(0))) return true;
////                     return false;
////                  });
//}


//void IpProcessor::print_standard_all_() {

//    for (auto ip = ip_pool_.cbegin(); ip != ip_pool_.cend(); ++ip) {
//        for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part) {

//            if (ip_part != ip->cbegin()) {
//                std::cout << ".";
//            }
//            std::cout << *ip_part;
//        }
//        std::cout << std::endl;
//    }
//}


//    vector<int> abc(10, 2);
//    std::copy(abc.begin(), abc.end(), std::ostream_iterator<int>(std::cout, " "));

//    vector<string> qqq(10, "234567");
//    std::copy(qqq.begin(), qqq.end(), std::ostream_iterator<string>(std::cout, "\n"));

//    cout << qqq;

//    std::ostream_iterator<vector<string>>  vs_itr(std::cout, "\n");
//    vs_itr = qqq;


//    vector<vector<string>> vvs;
//    std::copy(vvs.begin(), vvs.end(),
//              std::ostream_iterator<vector<string>>(std::cout, "\n"));

//struct Elem {

//    int data;

//    Elem(int inp = 0):data(inp) {cout << "Elem ctor: " << data << endl;}

//    ~Elem() {cout << "Elem dtor: " << data << endl;}

//    Elem(const Elem & rhs):
//    data(rhs.data){
//        cout << " Elem Copy constructor" << endl;
//    }

//    Elem(Elem && rhs):
//    data(rhs.data){
//        cout << " Elem move constructor" << endl;
//    }

//    Elem & operator= (const Elem & rhs) {

//        cout << "Elem operator=(const Elem &) " << endl;

//        if (&rhs == this) return *this;

//        data = rhs.data;
//        return *this;
//    }

//    Elem & operator= (Elem && rhs) {

//        cout << "Elem move operator=(Elem &&) " << endl;

//        if (&rhs == this) return *this;

//        data = rhs.data;
//        return *this;
//    }
//};

//class B;
//class A {
//public:
//    A():ve(0){cout << "ctor A" << endl;}
//    ~A(){cout << "dtor A" << endl;}

//    void setup(const size_t n) {
//        cout << "resize:" << endl;
//        ve.resize(n);

//        cout << endl << " init loop: " << endl;
//        for (size_t k = 0; k < n; ++k) {
//            ve[k] = std::move(Elem(k + 1));
//        }
//        cout << " loop done" << endl;
//    }

//    void print() {
//        cout << "A data: " << endl;

//        for (size_t k = 0; k < ve.size(); ++k) {
//            cout << ve[k].data << " ";
//        }
//        cout << endl;
//    }

//private:
//    vector<Elem> ve;
//    friend class B;
//};

//class B {
//public:
//    B():ve(0){cout << "ctor B" << endl;}
//    ~B() {cout << "dtor B" << endl;}


//    B& operator = (const A & rhs) {
//        cout << "B = A (const &)" << endl;
//        ve = rhs.ve;
//        return *this;
//    }

//    B& operator = (A && rhs) {
//        cout << "B = move A (&&)" << endl;
//        ve = std::move(rhs.ve);
//        return *this;
//    }

//    void print() {
//        cout << "B data: " << endl;
//        for (size_t k = 0; k < ve.size(); ++k) {
//            cout << ve[k].data << " ";
//        }
//        cout << endl;
//    }

//    vector<Elem> get_vec() {
//        cout << "move vector from B" << endl;
//        return std::move(ve);
//    }

//private:
//    vector<Elem> ve;
//};


//A a;
//B b;
//a.setup(10);
////a.print();
////b.print();

////cout << "--------------------" << endl;
////b = a;
////a.print();
////b.print();

//b = std::move(a);
//a.print();
//b.print();

//vector<Elem> && b_pool = b.get_vec();

//b.print();

//cout << " + " << b_pool[2].data << endl;

