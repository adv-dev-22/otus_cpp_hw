#ifndef _CUSTOM_ALLOCATOR_H_
#define _CUSTOM_ALLOCATOR_H_

#include <cstddef>
#include <iostream>
#include <vector>
#include <memory>
#include <list>

///////////////////////////////////////////////////////////////////////////////

template <typename T>
class contigious_block final {
public:
    contigious_block(const size_t);
    contigious_block(contigious_block && );

    ~contigious_block();

    const size_t size() const;
    T * base_address();
    const T * base_address() const;

private:
    std::vector<T> mem_block_;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T>
class elementwise_block_allocator {
public:
    using value_type = T;

    using pointer = T *;
    using const_pointer = const T * ;
    using reference = T &;
    using const_reference = const T & ;
    using size_type = std::size_t;

    elementwise_block_allocator();
    virtual ~elementwise_block_allocator() = default;

    T * allocate(const size_t n);
    void deallocate(T * ptr, const size_t n);

    template <typename U, typename ... Args>
    void construct(U * ptr, Args && ... args);

    template <typename U>
    void destroy(U * ptr);

private:
    std::list<contigious_block<T>> memory_blocks_;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T>
contigious_block<T>::contigious_block(const size_t size):
mem_block_(size, T()) {

    std::cout << "contigious_block<T> created = " << std::endl;
    std::cout << " address = " << mem_block_.data() << std::endl;
}

template <typename T>
contigious_block<T>::contigious_block(contigious_block<T> && rhs):
mem_block_(std::move(rhs.mem_block_)) {
    std::cout << "move-constructor with block addr = " << mem_block_.data() << std::endl;
}

template <typename T>
contigious_block<T>::~contigious_block() {

    std::cout << "contigious_block<T> deleted = " << std::endl;
    std::cout << " address = " << mem_block_.data() << std::endl;
}

template <typename T>
const size_t contigious_block<T>::size() const {
    return mem_block_.size();
}

template <typename T>
T * contigious_block<T>::base_address() {
    return mem_block_.data();
}

template <typename T>
const T * contigious_block<T>::base_address() const {
    return mem_block_.data();
}

///////////////////////////////////////////////////////////////////////////////

template <typename T>
elementwise_block_allocator<T>::elementwise_block_allocator():
memory_blocks_() {

}

template <typename T>
T * elementwise_block_allocator<T>::allocate(const size_t n_ext) {

    contigious_block<T>  cblock(n_ext);
    memory_blocks_.push_back(std::move(cblock));

    return memory_blocks_.back().base_address();
}

template <typename T>
void elementwise_block_allocator<T>::deallocate(T * ptr, const size_t n) {

    auto is_block_with_base_address = [ptr](const contigious_block<T> & item) -> bool {
        if (item.base_address() == ptr) return true;
        return false;
    };

    memory_blocks_.remove_if(is_block_with_base_address);
}

template <typename T>
template <typename U, typename ... Args>
void elementwise_block_allocator<T>::construct(U * ptr, Args && ... args) {

    std::cout << "construct at " << ptr << std::endl;
    new ((void *) ptr) U(std::forward<Args>(args) ...);
}

template <typename T>
template <typename U>
void elementwise_block_allocator<T>::destroy(U * ptr) {

    std::cout << "destroy called for ptr = " << ptr <<std::endl;
    ptr->~U();
}

#endif   // _CUSTOM_ALLOCATOR_H_

// End of the file
