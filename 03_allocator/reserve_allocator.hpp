#ifndef _CUSTOM_ALLOCATOR_H_
#define _CUSTOM_ALLOCATOR_H_

#include <cstddef>
#include <iostream>
#include <array>

template <typename T, size_t n>
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

    T * allocate(const size_t m);
    void deallocate(T * ptr, const size_t m);

//    template <typename U, typename ... Args>
//    void construct(U * ptr, Args && ... args);

//    template <typename U>
//    void destroy(U * ptr);

private:
    std::array<T, n> memory_;
    size_t index_;
};

template <typename T, size_t n>
reserve_allocator<T, n>::reserve_allocator():
index_(0) {

}

//template <typename T, size_t n>
//T * custom_allocator<T, n>::allocate(const size_t m) {

//    auto ptr = std::malloc(n * sizeof(T));
//    if (!ptr) throw std::bad_alloc();

//    std::cout << "allocated at " << ptr << " " << n * sizeof(T) << " bytes" << std::endl;

//    return reinterpret_cast<T *>(ptr);
//}

//template <typename T>
//void custom_allocator<T>::deallocate(T * ptr, const size_t n) {

//    std::free(ptr);
//    std::cout << "deallocated: " << ptr << std::endl;
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

