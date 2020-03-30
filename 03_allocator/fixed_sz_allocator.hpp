#ifndef _FIXED_SIZE_ALLOCATOR_H_
#define _FIXED_SIZE_ALLOCATOR_H_

#include <array>
#include <string>
#include <exception>
#include <iostream>

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
    /*! Raw memory to be used. */
    std::array<T, n> mem_block_;

    /*! Size of rest available cells in contigious block. */
    size_t avail_size_;

    /*! Indexes of available cells in contigious block. Can be shuffled. */
    std::array<size_t, n> avail_index_;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T, size_t n>
reserve_allocator<T, n>::reserve_allocator():
avail_size_(n) {

    // At start all cells are unoccupied
    for (size_t i = 0; i < n; ++i) {
        avail_index_[i] = i;
    }
    avail_size_ = n;
}

template <typename T, size_t n>
T * reserve_allocator<T, n>::allocate(const size_t m) {

    if (m > 1) throw std::out_of_range("Can allocate only 1 item at each request");

    if (0 == avail_size_)
        throw std::out_of_range("Not enough memory: block is totally occupied.");

    // First unoccupied address
    T * address = mem_block_.data() + avail_index_[0];

    std::swap(avail_index_[0], avail_index_[--avail_size_]);

    return address;
}

template <typename T, size_t n>
void reserve_allocator<T, n>::deallocate(T * ptr, const size_t /*unused*/) {

    size_t shift = ptr - mem_block_.data();
    avail_index_[avail_size_++] = shift;
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
