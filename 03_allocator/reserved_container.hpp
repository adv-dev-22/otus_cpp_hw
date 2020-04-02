#ifndef _RESERVED_CONTAINER_H_
#define _RESERVED_CONTAINER_H_

#include "custom_container.hpp"

///////////////////////////////////////////////////////////////////////////////

// Specialization
template <typename T, size_t n>
class CustomContainer<T, reserve_allocator<T, n>> final {
public:
    CustomContainer();
    ~CustomContainer();

    void push_back(T item);

    T & current_item();

    void to_begin();
    bool next();

private:
    reserve_allocator<T, n> alloc_;
    std::array<T * , n> memory_;
    size_t current_size_;
    size_t current_index_;
};

template <typename T, size_t n>
using ReservedContainer = CustomContainer<T, reserve_allocator<T, n>>;

///////////////////////////////////////////////////////////////////////////////

template <typename T, size_t n>
CustomContainer<T, reserve_allocator<T, n>>::CustomContainer():
current_size_(0),
current_index_() {

}

template <typename T, size_t n>
CustomContainer<T, reserve_allocator<T, n>>::~CustomContainer() {

    for (size_t i = 0; i < current_size_; ++i) {
        alloc_.destroy(memory_[i]);
    }
    current_size_ = 0;
}

template <typename T, size_t n>
void CustomContainer<T, reserve_allocator<T, n>>::push_back(T item) {

    T * ptr_1 = alloc_.allocate(1);
    alloc_.construct(ptr_1, item);

    memory_[current_size_++] = ptr_1;
}

template <typename T, size_t n>
T & CustomContainer<T, reserve_allocator<T, n>>::current_item() {
    return *memory_[current_index_];
}

template <typename T, size_t n>
void CustomContainer<T, reserve_allocator<T, n>>::to_begin() {
    current_index_ = 0;
}

template <typename T, size_t n>
bool CustomContainer<T, reserve_allocator<T, n>>::next() {
    return !(1 + current_index_++ == current_size_);
}

///////////////////////////////////////////////////////////////////////////////

#endif // _RESERVED_CONTAINER_H_

// End of the file

