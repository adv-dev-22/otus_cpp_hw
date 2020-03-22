#ifndef _CUSTOM_ALLOCATOR_H_
#define _CUSTOM_ALLOCATOR_H_

#include <cstddef>
#include <iostream>

template <typename T>
struct custom_allocator {

    using value_type = T;

    using pointer = T *;
    using const_pointer = const T * ;
    using reference = T &;
    using const_reference = const T & ;
    using size_type = std::size_t;

    custom_allocator() = default;
    ~custom_allocator() = default;

    T * allocate(const size_t n);
    void deallocate(T * ptr, const size_t n);

    template <typename U, typename ... Args>
    void construct(U * ptr, Args && ... args);

    template <typename U>
    void destroy(U * ptr);


};

template <typename T>
T * custom_allocator<T>::allocate(const size_t n) {

    auto ptr = std::malloc(n * sizeof(T));
    if (!ptr) throw std::bad_alloc();

    std::cout << "allocated at " << ptr << " " << n * sizeof(T) << " bytes" << std::endl;

    return reinterpret_cast<T *>(ptr);
}

template <typename T>
void custom_allocator<T>::deallocate(T * ptr, const size_t n) {

    std::free(ptr);
    std::cout << "deallocated: " << ptr << std::endl;
}

template <typename T>
template <typename U, typename ... Args>
void custom_allocator<T>::construct(U * ptr, Args && ... args) {

    new ((void *) ptr) U(std::forward<Args>(args) ...);
}

template <typename T>
template <typename U>
void custom_allocator<T>::destroy(U * ptr) {

    std::cout << "destroy called for ptr = " << ptr <<std::endl;
    ptr->~U();
}



#endif   // _CUSTOM_ALLOCATOR_H_

// End of the file

