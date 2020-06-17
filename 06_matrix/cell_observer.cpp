// This file is included in "cell_observer.h"

#include <map>

template <typename T, T DefaultValue>
CellObserver<T, DefaultValue>::CellObserver():
index_(0),
host_row_(nullptr) {

}

template <typename T, T DefaultValue>
void CellObserver<T, DefaultValue>::set_index(const size_t index) {
    index_ = index;
}

template <typename T, T DefaultValue>
void CellObserver<T, DefaultValue>::bind(InfiniteRow<T, DefaultValue> * const host_row) {
    host_row_ = host_row;
}

template <typename T, T DefaultValue>
CellObserver<T, DefaultValue>::operator T() const {

    typename std::map<size_t, T>::iterator itr = host_row_->find(index_);
    if (itr != host_row_->end()) {
        return itr->second;
    }
    return DefaultValue;
}

template <typename T, T DefaultValue>
CellObserver<T, DefaultValue> & CellObserver<T, DefaultValue>::operator= (const T & rhs_value) {

    if (nullptr == host_row_)
        throw std::logic_error("CellObserver and InfiniteRow are not binded");

    if (DefaultValue != rhs_value) {
        host_row_->insert(index_, rhs_value);
        return *this;
    }

    if (DefaultValue == rhs_value) {
//        //host_row_->set_value_(index_for_update_, rhs_value);
//        // remove value
    }

    return *this;
}

template <typename T, T DefaultValue>
bool operator== (const CellObserver<T, DefaultValue> & lhs, const T & rhs) {
    T value = lhs;
    return (value == rhs);
}

template <typename T, T DefaultValue>
bool operator== (const T & lhs, const CellObserver<T, DefaultValue> & rhs) {
    T value = rhs;
    return (lhs == value);
}

// End of the file
