#ifndef _CUSTOM_CONTAINER_H_
#define _CUSTOM_CONTAINER_H_

#include <memory>
#include <cstddef>
#include <iostream>

///////////////////////////////////////////////////////////////////////////////

template <typename T, typename allocator_type = std::allocator<T>>
class CustomContainer final {
public:
    CustomContainer();
    ~CustomContainer();

    void push_back(T item);

    T & current_item();

    void to_begin();
    bool next();

private:
    allocator_type alloc_;
    T * memory_;
    size_t size_;
    size_t avail_index_;
    size_t current_idx_;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T, typename allocator_type>
CustomContainer<T, allocator_type>::CustomContainer():
alloc_(),
memory_(nullptr),
size_(0),
avail_index_(0),
current_idx_(0) {

}

template <typename T, typename allocator_type>
CustomContainer<T, allocator_type>::~CustomContainer() {

    for (size_t i = 0; i < avail_index_; ++i) {
        alloc_.destroy(&memory_[i]);
    }
    avail_index_ = 0;
}

template <typename T, typename allocator_type>
void CustomContainer<T, allocator_type>::push_back(T item) {

    if (nullptr == memory_) {
        const size_t tmp_sz = 4;
        memory_ = alloc_.allocate(tmp_sz);
        size_ = tmp_sz;
        avail_index_ = 0;
    }

    if (avail_index_ >= size_) {

        T * buffer = alloc_.allocate(2 * size_);
        size_t buffer_avail_index = 0;

        for (size_t i = 0; i < avail_index_; ++i) {

            alloc_.construct(&buffer[buffer_avail_index], memory_[buffer_avail_index]);
            std::cout << " constructed (reallocated) item = " << buffer[buffer_avail_index] << std::endl;
            std::cout << " destroyed item " << memory_[buffer_avail_index] << std::endl;
            alloc_.destroy(&memory_[buffer_avail_index]);
            ++buffer_avail_index;
        }

        alloc_.deallocate(memory_, size_);

        memory_ = buffer;
        buffer = nullptr;
        size_ *= 2;
        avail_index_ = buffer_avail_index;

        std::cout << "memory reallocated.." << __PRETTY_FUNCTION__ << std::endl;
    }

    alloc_.construct(&memory_[avail_index_++], item);
    std::cout << "constructed for " << item << std::endl;
}

template <typename T, typename allocator_type>
T & CustomContainer<T, allocator_type>::current_item() {
    return memory_[current_idx_];
}

template <typename T, typename allocator_type>
void CustomContainer<T, allocator_type>::to_begin() {
    current_idx_ = 0;
}

template <typename T, typename allocator_type>
bool CustomContainer<T, allocator_type>::next() {
    return !(1 + current_idx_++ == avail_index_);
}

///////////////////////////////////////////////////////////////////////////////

#endif // _CUSTOM_CONTAINER_H_

// End of the file

