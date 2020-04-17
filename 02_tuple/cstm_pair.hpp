#ifndef _CUSTOM_PAIR_H_
#define _CUSTOM_PAIR_H_

#include <algorithm>
#include <iostream>
#include <type_traits>

///////////////////////////////////////////////////////////////////////////////

template <typename T1, typename U2>
class CustomPair {

    friend class CustomPair<T1 & , U2 &>;

    template <size_t n, typename arg1, typename arg2>
    friend typename std::enable_if<n == 0, arg1>::type & get(CustomPair<arg1, arg2> & );

    template <size_t n, typename arg1, typename arg2>
    friend typename std::enable_if<n == 1, arg2>::type & get(CustomPair<arg1, arg2> & );

public:
    CustomPair();
    CustomPair(const T1 & f, const U2 & s);
    CustomPair(T1 && f, U2 && s);
    CustomPair(const CustomPair & rhs);
    CustomPair(CustomPair && rhs);

    CustomPair & operator = (const CustomPair & );
    CustomPair & operator = (CustomPair && );

    ~CustomPair();

    void operator >> (std::ostream & os) const;

    CustomPair make_custom_pair(T1 f, U2 s);

private:
    T1 first_;
    U2 second_;
};

template <typename T1, typename U2>
std::ostream & operator << (std::ostream & os, const CustomPair<T1, U2> & rhs_pr);

template <std::size_t n, typename T1, typename U2>
typename std::enable_if<n == 0, T1>::type & get(CustomPair<T1, U2> & cstm_pair);

template <std::size_t n, typename T1, typename U2>
typename std::enable_if<n == 1, U2>::type & get(CustomPair<T1, U2> & cstm_pair);

///////////////////////////////////////////////////////////////////////////////

template <typename T1, typename U2>
class CustomPair<T1 &, U2 &> {
public:
    CustomPair(T1 & f, U2 & s);
    CustomPair(const CustomPair & rhs);

    CustomPair & operator = (const CustomPair & rhs);

    template <typename Arg1, typename Arg2>
    CustomPair & operator = (const CustomPair<Arg1, Arg2> & rhs);

    ~CustomPair();

    void operator >> (std::ostream & os) const;

private:
    T1 & first_;
    U2 & second_;
};

template <typename T1, typename U2>
std::ostream & operator << (std::ostream & os, const CustomPair<T1 &, U2 &> & rhs_pr);

template <typename T1, typename U2>
CustomPair<T1 & , U2 &> custom_tie(T1 & f, U2 & s);

///////////////////////////////////////////////////////////////////////////////

template <typename T1, typename U2>
CustomPair<T1, U2>::CustomPair():
first_(),
second_() {

}

template <typename T1, typename U2>
CustomPair<T1, U2>::CustomPair(const T1 & first, const U2 & second):
first_(first),
second_(second) {

}

template <typename T1, typename U2>
CustomPair<T1, U2>::CustomPair(T1 && first, U2 && second):
first_(first),
second_(second) {

}

template <typename T1, typename U2>
CustomPair<T1, U2>::CustomPair(const CustomPair & rhs):
first_(rhs.first_),
second_(rhs.second_) {

}

template <typename T1, typename U2>
CustomPair<T1, U2>::CustomPair(CustomPair && rhs):
first_(std::move(rhs.first_)),
second_(std::move(rhs.second_)) {

}

template <typename T1, typename U2>
CustomPair<T1, U2> & CustomPair<T1, U2>::operator = (const CustomPair & rhs) {

    if (&rhs != this) {
        first_ = rhs.first_;
        second_ = rhs.second_;
    }
    return *this;
}

template <typename T1, typename U2>
CustomPair<T1, U2> & CustomPair<T1, U2>::operator = (CustomPair && rhs) {

    if (&rhs != this) {
        first_ = std::move(rhs.first_);
        second_ = std::move(rhs.second_);
    }
    return *this;
}

template <typename T1, typename U2>
CustomPair<T1, U2>::~CustomPair() {

}

template <typename T1, typename U2>
void CustomPair<T1, U2>::operator >> (std::ostream & os) const {
    os << "(" << first_ << ", " << second_ << ")";
}


template <typename T1, typename U2>
CustomPair<T1, U2> make_custom_pair(T1 f, U2 s) {
    return CustomPair<T1, U2>(f, s);
}

template <typename T1, typename U2>
std::ostream & operator << (std::ostream & os, const CustomPair<T1, U2> & rhs_pr) {
    rhs_pr >> os;
    return os;
}

template <std::size_t n, typename T1, typename U2>
typename std::enable_if<n == 0, T1>::type & get(CustomPair<T1, U2> & cstm_pair) {
    return cstm_pair.first_;
}

template <std::size_t n, typename T1, typename U2>
typename std::enable_if<n == 1, U2>::type & get(CustomPair<T1, U2> & cstm_pair) {
    return cstm_pair.second_;
}

///////////////////////////////////////////////////////////////////////////////

template <typename T1, typename U2>
CustomPair<T1 &, U2 &>::CustomPair(T1 & f, U2 & s):
first_(f),
second_(s) {

}

template <typename T1, typename U2>
CustomPair<T1 &, U2 &>::CustomPair(const CustomPair<T1 &, U2 &> & rhs):
first_(rhs.first_),
second_(rhs.second_) {

}

template <typename T1, typename U2>
CustomPair<T1 &, U2 &> &
CustomPair<T1 &, U2 &>::operator = (const CustomPair<T1 &, U2 &> & rhs) {

    if (&rhs != this) {
        first_ = rhs.first_;
        second_ = rhs.second_;
    }
    return *this;
}

template <typename T1, typename U2>
template <typename Arg1, typename Arg2>
CustomPair<T1 &, U2 &> &
CustomPair<T1 &, U2 &>::operator = (const CustomPair<Arg1, Arg2> & rhs) {

    first_ = rhs.first_;
    second_ = rhs.second_;

    return *this;
}

template <typename T1, typename U2>
CustomPair<T1 &, U2 &>::~CustomPair() {

}

template <typename T1, typename U2>
void CustomPair<T1 & , U2 & >::operator >> (std::ostream & os) const {
    os << "(" << first_ << ", " << second_ << ")";
}

template <typename T1, typename U2>
std::ostream & operator << (std::ostream & os, const CustomPair<T1&, U2&> & rhs_pr) {
    rhs_pr >> os;
    return os;
}

template <typename T1, typename U2>
CustomPair<T1 & , U2 &> custom_tie(T1 & f, U2 & s) {
    return CustomPair<T1 & , U2 &>(f, s);
}

///////////////////////////////////////////////////////////////////////////////


#endif // _CUSTOM_PAIR_H_

// End of the file

