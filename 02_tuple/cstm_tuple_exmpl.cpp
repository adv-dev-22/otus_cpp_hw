#include "cstm_tuple.hpp"
#include <string>

using  std::endl;
using  std::cout;

auto getPerson() {

    const std::string name = "Petia";
    const std::string secondName = "Ivanoff";
    const std::size_t age = 23;
    const std::string department = "Sale";

    return make_custom_tuple(name, secondName, age, department);
}

auto getPerson1() {
    const std::string secondName = "Ivanoff";
    return make_custom_tuple(secondName);
}


int main(int argc, char** argv) {

    // 1
    custom_tuple<double, uint64_t, const char* > t1(12.2, 42, "big");

    std::cout << "0th elem is " << get<0>(t1) << "\n";
    std::cout << "1th elem is " << get<1>(t1) << "\n";
    std::cout << "2th elem is " << get<2>(t1) << "\n";

    get<1>(t1) = 103;

    std::cout << "1th elem is " << get<1>(t1) << "\n";

    typename elem_type_holder<1, custom_tuple<double, int, const char*>>::type foo;
    std::cout << typeid(foo).name() << "\n";

    // 2
    auto && mct = make_custom_tuple(123, 14, 3.f, std::string("abc"), true);
    std::cout << get<0>(mct) << endl;

    // 3
    std::string name, secondName, department;
    std::size_t age;

//    custom_tie(secondName) = getPerson1();
//    cout << "secondName = " << secondName << endl;

    custom_tie(name, secondName, age, department) = getPerson();
    cout << "==============" << endl;
    cout << name << endl;
    cout << secondName << endl;
    cout << age << endl;
    cout << department << endl;

    assert(name == "Petia");
    assert(secondName == "Ivanoff");
    assert(age == 23);
    assert(department == "Sale");

    return 0;
}

// End of the file

