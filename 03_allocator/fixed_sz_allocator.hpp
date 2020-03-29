#ifndef _FIXED_SIZE_ALLOCATOR_H_
#define _FIXED_SIZE_ALLOCATOR_H_

#include <array>
#include <string>
#include <exception>

///////////////////////////////////////////////////////////////////////////////

template <typename T, size_t n>
class reserve_allocator {
public:
    using value_type = T;

    using pointer = T *;
    using const_pointer = const T * ;
    using reference = T &;
    using const_reference = const T & ;
    using size_type = std::size_t;

    template<typename U>
    struct rebind {
        using other = reserve_allocator<U, n>;
    };

    reserve_allocator();
    virtual ~reserve_allocator() = default;

    T * allocate(const size_t m);
    void deallocate(T * ptr, const size_t m);

    template <typename U, typename ... Args>
    void construct(U * ptr, Args && ... args);

    template <typename U>
    void destroy(U * ptr);

private:
    std::array<T, n> mem_block_;
    size_t index_;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T, size_t n>
reserve_allocator<T, n>::reserve_allocator():
index_(0) {

}

template <typename T, size_t n>
T * reserve_allocator<T, n>::allocate(const size_t m) {

    if (m > 1) throw std::out_of_range("Can allocate only 1 item at each request");

    if (index_ + m > n)
        throw std::out_of_range(std::string("Can not allocate block bigger then n ") + std::to_string(n));

    return mem_block_.data() + index_++;
}

template <typename T, size_t n>
void reserve_allocator<T, n>::deallocate(T * /*unused*/, const size_t /*unused*/) {
    // Keep holding (reserved) array.
    if (index_ > 0) --index_;
    else throw std::runtime_error("Everything is deallocated already!");
}

template <typename T, size_t n>
template <typename U, typename ... Args>
void reserve_allocator<T, n>::construct(U * ptr, Args && ... args) {
    new(ptr) U(std::forward<Args>(args) ...);
}

template <typename T, size_t n>
template <typename U>
void reserve_allocator<T, n>::destroy(U * ptr) {
    ptr->~U();
}

///////////////////////////////////////////////////////////////////////////////


#endif  // _FIXED_SIZE_ALLOCATOR_H_

// End of the file


//    const T * base_address() const;
//    fixed_sz_block(fixed_sz_block && );
//template <typename T, size_t n>
//fixed_sz_block<T, n>::fixed_sz_block(fixed_sz_block && rhs) {

//}


//template <typename T, size_t n>
//class fixed_sz_block final {
//public:
//    fixed_sz_block();
//    ~fixed_sz_block() = default;

//    T * base_address();
//private:
//    std::array<T, n> mem_block_;
//};



//template <typename T, size_t n>
//fixed_sz_block<T, n>::fixed_sz_block():
//index_(0) {

//}

//template <typename T, size_t n>
//T * fixed_sz_block<T, n>::base_address() {
//    return mem_block_.data();
//}

//template <typename T, size_t n>
//const size_t fixed_sz_block<T, n>::index() const {
//    return index_;
//}
