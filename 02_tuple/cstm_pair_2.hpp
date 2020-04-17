#ifndef _CUSTOM_PAIR_H_
#define _CUSTOM_PAIR_H_

#include <algorithm>
#include <iostream>
#include <type_traits>

///////////////////////////////////////////////////////////////////////////////

template <typename T1, typename U2>
class CustomPair2 {

    template <typename Arg1, typename Arg2>
    friend class CustomPair2;

    template <size_t n, typename arg1, typename arg2>
    friend typename std::enable_if<n == 0, arg1>::type & get(CustomPair2<arg1, arg2> & );

    template <size_t n, typename arg1, typename arg2>
    friend typename std::enable_if<n == 1, arg2>::type & get(CustomPair2<arg1, arg2> & );

public:
    CustomPair2();
    CustomPair2(const T1 & f, const U2 & s);

    CustomPair2(const CustomPair2 & rhs);

    CustomPair2 & operator = (const CustomPair2 & );
    CustomPair2 & operator = (CustomPair2 && );

    template <typename Arg1, typename Arg2>
    CustomPair2 & operator = (const CustomPair2<Arg1, Arg2> & rhs);

    ~CustomPair2();

    void operator >> (std::ostream & os) const;

    CustomPair2 make_custom_pair(T1 f, U2 s);

private:
    T1 first_;
    U2 second_;
};

template <typename T1, typename U2>
std::ostream & operator << (std::ostream & os, const CustomPair2<T1, U2> & rhs_pr);

template <typename T1, typename U2>
auto custom_pair_tie(T1 && f, U2 && s);

template <std::size_t n, typename T1, typename U2>
typename std::enable_if<n == 0, T1>::type & get(CustomPair2<T1, U2> & cstm_pair);

template <std::size_t n, typename T1, typename U2>
typename std::enable_if<n == 1, U2>::type & get(CustomPair2<T1, U2> & cstm_pair);

///////////////////////////////////////////////////////////////////////////////

template <typename T1, typename U2>
CustomPair2<T1, U2>::CustomPair2():
first_(),
second_() {

}

template <typename T1, typename U2>
CustomPair2<T1, U2>::CustomPair2(const T1 & first, const U2 & second):
first_(first),
second_(second) {

}

template <typename T1, typename U2>
CustomPair2<T1, U2>::CustomPair2(const CustomPair2 & rhs):
first_(rhs.first_),
second_(rhs.second_) {

}

template <typename T1, typename U2>
CustomPair2<T1, U2>::~CustomPair2() {

}

template <typename T1, typename U2>
CustomPair2<T1, U2> & CustomPair2<T1, U2>::operator = (const CustomPair2 & rhs) {

    if (&rhs != this) {
        first_ = rhs.first_;
        second_ = rhs.second_;
    }
    return *this;
}

template <typename T1, typename U2>
CustomPair2<T1, U2> & CustomPair2<T1, U2>::operator = (CustomPair2 && rhs) {

    if (&rhs != this) {
        first_ = std::forward(rhs.first_);
        second_ = std::forward(rhs.second_);
    }
    return *this;
}

template <typename T1, typename U2>
template <typename Arg1, typename Arg2>
CustomPair2<T1, U2> &
CustomPair2<T1, U2>::operator = (const CustomPair2<Arg1, Arg2> & rhs) {

    this->first_ = rhs.first_;
    this->second_ = rhs.second_;

    return *this;
}

template <typename T1, typename U2>
void CustomPair2<T1, U2>::operator >> (std::ostream & os) const {
    os << "(" << first_ << ", " << second_ << ")";
}


template <typename T1, typename U2>
CustomPair2<T1, U2> make_custom_pair(T1 f, U2 s) {
    return CustomPair2<T1, U2>(f, s);
}

template <typename T1, typename U2>
std::ostream & operator << (std::ostream & os, const CustomPair2<T1, U2> & rhs_pr) {
    rhs_pr >> os;
    return os;
}

template <typename T1, typename U2>
auto custom_pair_tie(T1 && f, U2 && s) {
    return std::move(CustomPair2<T1 , U2>(f, s));
}

template <std::size_t n, typename T1, typename U2>
typename std::enable_if<n == 0, T1>::type & get(CustomPair2<T1, U2> & cstm_pair) {
    return cstm_pair.first_;
}

template <std::size_t n, typename T1, typename U2>
typename std::enable_if<n == 1, U2>::type & get(CustomPair2<T1, U2> & cstm_pair) {
    return cstm_pair.second_;
}

///////////////////////////////////////////////////////////////////////////////

#endif // _CUSTOM_PAIR_H_

// End of the file
