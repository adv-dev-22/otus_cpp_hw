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

/*! String type deduction for SFINAE */
template <typename T>
struct is_std_string {
};

template <>
struct is_std_string<std::string> {
    static constexpr bool value = true;
};

///////////////////////////////////////////////////////////////////////////////

/*! Container type deduction for SFINAE */
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

/*! Declaration of the same variadic types. */
template <typename ... Args>
struct are_types_same {
    static constexpr bool value = false;
};

/*! Specialization for empty parameter case. */
template <>
struct are_types_same<> {
    static constexpr bool value = true;
};

template <typename T>
struct are_types_same<T> {
    static constexpr bool value = true;
};

template <typename T, typename U, typename ... Args>
struct are_types_same<T, U, Args ...> {
    static constexpr bool value = std::is_same<T, U>::value && are_types_same<Args ...>::value;
};

template <typename T>
struct is_uniform_args_tuple {
    static constexpr bool value = false;
};

template <typename... Args>
struct is_uniform_args_tuple<std::tuple<Args...>> {
    static constexpr bool value = are_types_same<Args ...>::value;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T>
void print_item(const std::string & msg, const T item) {
    std::cout << msg;
    std::cout << static_cast<unsigned int>(item);
};

template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type print_ip(T value) {

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

    return value;
}

template <typename T>
typename std::enable_if<is_std_string<T>::value, T>::type print_ip(T value) {
    std::cout << value << std::endl;
    return value;
}

template <typename T>
typename std::enable_if<is_std_container<T>::value, T>::type print_ip(T value) {

    auto itr = value.begin();
    print_item("", *itr);
    ++itr;
    for ( ; itr != value.end(); ++itr) {
        print_item(".", *itr);
    }
    std::cout << std::endl;
    return value;
}

///////////////////////////////////////////////////////////////////////////////

/*! Prints tuple of any size. */
template <class Tuple, size_t n>
struct tupple_printer {
    static void print(const Tuple & t, const std::string & delimeter_str = ", ") {
        tupple_printer<Tuple, n - 1>::print(t, delimeter_str);
        std::cout << delimeter_str << std::get<n - 1>(t);
    }
};

template <class Tuple>
struct tupple_printer <Tuple, 1> {
    static void print(const Tuple & t, const std::string & ) {
        std::cout << std::get<0>(t);
    }
};

template <typename T>
typename std::enable_if<is_uniform_args_tuple<T>::value, T>::type print_ip(T value) {

    tupple_printer<T, std::tuple_size<T>::value>::print(value, std::string("."));
    std::cout << std::endl;
}

#endif // _PRINT_IP_04_H_

// End of the file


