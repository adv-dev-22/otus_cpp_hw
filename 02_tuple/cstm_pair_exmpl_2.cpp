#include "cstm_pair_2.hpp"
#include <iostream>
#include <string>

using  std::string;
using  std::cout;
using  std::endl;

auto getPerson() {
    const std::size_t age = 23;
    const std::string secondName = "Ivanoff";
    return make_custom_pair(age, secondName);
}

int main(int argc, char * argv []) {

    CustomPair2<int, string> simple_pr(117, "valued");
    cout << simple_pr << endl;

    CustomPair2<int, string> simple_pr2(1234567890, "simple = simple");
    simple_pr = simple_pr2;
    cout << simple_pr << endl;

    cout << (get<0>(simple_pr) = 337) << " - ";
    cout << (get<1>(simple_pr) = string("from_get<1>")) << endl;

    int a1 = 5;
    string s2("initial references");
    CustomPair2<int &, string&> r_cpr(a1, s2);
    cout << r_cpr << endl;

    r_cpr = simple_pr;
    cout << r_cpr << endl;

    a1 = 225;
    s2 = "own = works!";
    CustomPair2<int & , string & > r_cpr2(a1, s2);
    r_cpr = r_cpr2;
    cout << r_cpr << endl;

    int b1 = 444;
    string q2("custom_tie works");

    auto cpt = custom_pair_tie(b1, q2);
    cout << cpt << endl;
    b1 = 3333;
    cout << cpt << endl;

    custom_pair_tie(b1, q2) = simple_pr;
    cout << b1 << " " << q2 << endl;

    size_t d1;
    custom_pair_tie(d1, q2) = getPerson();
    cout << d1 << " " << q2 << endl;

    return 0;
}

// End of the file



//template <typename T>
//class A {
//public:
//    A(const T & ai): a_(ai) {
//        cout << __PRETTY_FUNCTION__ << endl;
//    }

//    void print() {cout << a_ << endl;}

//private:
//    T a_;
//};


//int main(int argc, char * argv []) {

//    int v = 337;
//    A<int &> a(v);
//    a.print();
//    v = 444;
//    a.print();

