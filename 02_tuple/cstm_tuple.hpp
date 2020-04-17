#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>
#include <typeinfo>
#include <cstddef>

using  std::string;
using  std::cout;
using  std::endl;

template <typename ... Types>
struct custom_tuple {};

template <typename T, typename ... Types>
struct custom_tuple<T, Types ...> : public custom_tuple<Types ...> {

    custom_tuple(T t_arg, Types ... ts_args):
        custom_tuple<Types ...>(ts_args ...),
        tail(t_arg) {
        //cout << __PRETTY_FUNCTION__ << endl;
    }

    T tail;

    template <typename Arg1, typename... Args>
    custom_tuple& operator= (const custom_tuple<Arg1, Args... > &rhs);
};

template <size_t , typename > struct elem_type_holder;

template <typename T, typename ... Ts>
struct elem_type_holder<0, custom_tuple<T, Ts ... >> {
    typedef T type;
};

template <size_t k, typename T, typename ... Ts>
struct elem_type_holder<k, custom_tuple<T, Ts ...>> {
    typedef typename elem_type_holder<k - 1, custom_tuple<Ts ... >>::type type;
};

template <size_t k, typename ... Types>
typename std::enable_if_t<k == 0, typename elem_type_holder<0, custom_tuple<Types ... >>::type& >
get(custom_tuple<Types ... > & ct) {
    return ct.tail;
}

template <size_t k, typename T, typename ... Types>
typename std::enable_if_t<k != 0, typename elem_type_holder<k, custom_tuple<T, Types ... >>::type & >
get(custom_tuple<T, Types ... > & ct) {
    custom_tuple<Types ...> & base = ct;
    return get<k - 1>(base);
}

template <typename ... Types>
auto make_custom_tuple(Types ... args) {
    return custom_tuple<Types ... >(args ...);
}

template <typename ... Types>
auto custom_tie(Types & ... args) noexcept {
    return custom_tuple<Types & ...>(args ...);
}

template <typename T, typename ... Types>
template <typename Arg1, typename... Args>
custom_tuple<T, Types ... > & custom_tuple<T, Types ... >::operator= (
            const custom_tuple<Arg1, Args... > & rhs) {

    tail = rhs.tail;

    const custom_tuple<Args... > & base_rhs = rhs;
    custom_tuple<Types ...>::operator= (base_rhs);

    return *this;
}

// End of the file
