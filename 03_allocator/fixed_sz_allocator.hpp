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

//    std::cout << "!!!!!!!!!  ";
//    std::cout << &mem_block_[1] - &mem_block_[0] << std::endl;
//    std::cout << &mem_block_[0] << std::endl;
//    std::cout << &mem_block_[1] << std::endl;
//    std::cout << "sizeof(T) = " << sizeof (T) << std::endl;
//    std::cout << &mem_block_[0] + 1 << std::endl;
}

template <typename T, size_t n>
T * reserve_allocator<T, n>::allocate(const size_t m) {

    if (m > 1) throw std::out_of_range("Can allocate only 1 item at each request");

    if (0 == avail_size_)
        throw std::out_of_range("Not enough memory: block is totally occupied.");

    //std::cout << "avail_size_ = " << avail_size_ << std::endl;

    // First unoccupied address
    T * address = mem_block_.data() + avail_index_[0];
    //std::cout << "block_data: " << mem_block_.data();
//    for (size_t i = 0; i < n; ++i) {
//        std::cout << " " << avail_index_[i];
//    }
    //std::cout << std::endl;

    //std::cout << "address =   " << address << std::endl;
    //std::cout << "size_of(T) = " << sizeof (T) << std::endl;

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
