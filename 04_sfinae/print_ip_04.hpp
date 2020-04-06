#ifndef _PRINT_IP_04_H_
#define _PRINT_IP_04_H_

#include <type_traits>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <bitset>
#include <cstdint>

///////////////////////////////////////////////////////////////////////////////

template <typename T>
struct is_std_string {
};

template <>
struct is_std_string<std::string> {
    static constexpr bool value = true;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T>
struct is_std_container {
};

template <typename T>
struct is_std_container<std::vector<T>> {
    static constexpr bool value = true;
};

template <typename T>
struct is_std_container<std::list<T>> {
    static constexpr bool value = true;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T>
struct is_std_tuple {
};

template <typename T>
struct is_std_tuple<std::tuple<T, T, T, T>> {
    static constexpr bool value = true;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T>
void print_item(const std::string & msg, const T item) {
    std::cout << msg;
    std::cout << static_cast<unsigned int>(item);
};

template <typename T>
void print_ip(typename std::enable_if<std::is_integral<T>::value, T>::type value) {

    constexpr uint8_t byte_size = 8;
    constexpr uint8_t n = sizeof (T);
    constexpr uint8_t m_bits = n * byte_size;

    std::bitset<m_bits> bit_sequence(value);

    auto get_byte_at = [&bit_sequence, &byte_size](const uint8_t i_start) -> uint8_t {

        uint8_t base_factor = 1;
        uint8_t byte_sum_8 = 0;
        for (uint8_t i = 0; i < byte_size; ++i) {

            if (bit_sequence[i + i_start])
                byte_sum_8 += base_factor;

            base_factor *= 2;
        }

        return byte_sum_8;
    };

    auto print_byte = [&byte_size, &get_byte_at](
            const std::string & msg, const uint8_t byte_index) -> void {
        print_item(msg, get_byte_at(byte_size * byte_index));
    };

    print_byte("", n - 1);
    for (size_t k = 1; k < n; ++k)
        print_byte(".", n - k - 1);

    std::cout << std::endl;
}

template <typename T>
void print_ip(typename std::enable_if<is_std_string<T>::value, T>::type value) {
    std::cout << value << std::endl;
}

template <typename T>
void print_ip(typename std::enable_if<is_std_container<T>::value, T>::type value) {

    auto itr = value.begin();
    print_item("", *itr);
    ++itr;
    for ( ; itr != value.end(); ++itr) {
        print_item(".", *itr);
    }
    std::cout << std::endl;
}

//template <typename T>
//void print_ip(typename std::enable_if<is_std_tuple<T>::value, T>::type value) {

//    print_item("", std::get<0>(value));
//    constexpr size_t t_size = std::tuple_size<T>::value;

////    for (size_t i = 1; i <= t_size; ++i) {
////        print_item(".", std::get<i>(value));
////    }
//    std::cout << std::endl;
//}

#endif // _PRINT_IP_04_H_

// End of the file


