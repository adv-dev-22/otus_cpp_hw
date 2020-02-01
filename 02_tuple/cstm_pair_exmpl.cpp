#include "cstm_pair.hpp"
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

    CustomPair<int, string> simple_pr(117, "valued");
    cout << simple_pr << endl;

    cout << (get<0>(simple_pr) = 337) << " - ";
    cout << (get<1>(simple_pr) = string("from_get<1>")) << endl;

    int a1 = 5;
    string s2("initial references");
    CustomPair<int &, string&> r_cpr(a1, s2);
    cout << r_cpr << endl;

    r_cpr = simple_pr;
    cout << r_cpr << endl;

    a1 = 225;
    s2 = "own = works!";
    CustomPair<int & , string & > r_cpr2(a1, s2);
    r_cpr = r_cpr2;
    cout << r_cpr << endl;

    int b1 = 444;
    string q2("custom_tie works");

    custom_tie(b1, q2) = simple_pr;
    cout << b1 << " " << q2 << endl;

    size_t d1;
    custom_tie(d1, q2) = getPerson();
    cout << d1 << " " << q2 << endl;

    return 0;
}

// End of the file
