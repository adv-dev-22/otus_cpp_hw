#ifndef _CUSTOM_ALLOCATOR_H_
#define _CUSTOM_ALLOCATOR_H_

#include <cstddef>
#include <iostream>
#include <array>
#include <memory>
#include <list>

template <typename T>
class anysize_contigious_block {
public:
    virtual size_t size() const = 0;

    /*! Initial (base) address of contigious block */
    virtual T * base_address() = 0;

    /*! Index of first unoccupied cell. A
     *  All cells with i <  index() are already in use.
     *  All cells with i >= index() are free. */
    virtual size_t index() const = 0;
};


template <typename T, size_t m>
class fixedsize_contigious_block : public anysize_contigious_block<T> {
public:
    fixedsize_contigious_block();
    ~fixedsize_contigious_block() = default;

    virtual size_t size() const;

    virtual T * base_address();

    virtual size_t index() const;

private:
    std::array<T, m> mem_block_;
    size_t index_;
};


template <typename T, size_t m>
class reserve_allocator final {
public:
    using value_type = T;

    using pointer = T *;
    using const_pointer = const T * ;
    using reference = T &;
    using const_reference = const T & ;
    using size_type = std::size_t;

    reserve_allocator();
    ~reserve_allocator() = default;

//    T * allocate(const size_t n);
//    void deallocate(T * ptr, const size_t n);

    //size_t remaining_contigious_size() const;

//    template <typename U, typename ... Args>
//    void construct(U * ptr, Args && ... args);

//    template <typename U>
//    void destroy(U * ptr);

private:
    std::list<anysize_contigious_block<T>> memory_blocks_;
};


//template <typename T, size_t m>
//memory_contigious_block<T, m>::memory_contigious_block():
//index(0) {

//}

//template <typename T, size_t m>
//reserve_allocator<T, m>::reserve_allocator():
//memory_blocks_(0) {

//}

//template <typename T, size_t m>
//T * reserve_allocator<T, m>::allocate(const size_t n) {

//    if (std::empty(memory_blocks_)) {
//        memory_blocks_.push_back(std::make_shared<memory_contigious_block<T, m>>());
//    }

//    std::make_shared<memory_contigious_block<T, m>> last_block = memory_blocks_.back();

//    if (n <= m) {

//        //last_block->index;

//    }
//    else {
//        last_block->index = m;

//        memory_blocks_.push_back(std::make_shared<memory_contigious_block<T, m>>());
//        allocate(n - m);
//    }


//    //const size_t memory_blocks_.back().index;

//    //if (index_ + m > memory_.size()) {
//        //throw std::invalid_argument("Required memory exceeds reserved amount");

//    //}

//    //index_ += m;

//    //std::cout << "allocated at " << &memory_[0] << "  with shift ";
//    //std::cout << index_ - m << " - " << index_ << std::endl;

//    //return &memory_[index_ - m];

//    return nullptr;
//}

//template <typename T, size_t m>
//void reserve_allocator<T, m>::deallocate(T * ptr, const size_t n) {

////    if (index_ < m ) {
////        throw std::invalid_argument("Can not free more memory then reserved amount");
////    }

////    index_ -= m;

////    std::cout << "deallocated at base " << &memory_[0] << "  in the range ";
////    std::cout << index_ << " - " << index_ + m << std::endl;
//}

//template <typename T>
//template <typename U, typename ... Args>
//void custom_allocator<T>::construct(U * ptr, Args && ... args) {

//    new ((void *) ptr) U(std::forward<Args>(args) ...);
//}

//template <typename T>
//template <typename U>
//void custom_allocator<T>::destroy(U * ptr) {

//    std::cout << "destroy called for ptr = " << ptr <<std::endl;
//    ptr->~U();
//}



#endif   // _CUSTOM_ALLOCATOR_H_

// End of the file

