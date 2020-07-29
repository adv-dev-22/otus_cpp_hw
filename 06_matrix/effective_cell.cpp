// This file is included in "cell_observer.h"

#include <map>

template <typename T, T DefaultValue>
EffectiveCell<T, DefaultValue>::EffectiveCell():
index_(0),
host_row_(nullptr) {

}

template <typename T, T DefaultValue>
void EffectiveCell<T, DefaultValue>::set_index(const size_t index) {
    index_ = index;
}

template <typename T, T DefaultValue>
void EffectiveCell<T, DefaultValue>::bind(InfiniteRow<T, DefaultValue> * const host_row) {
    host_row_ = host_row;
}

template <typename T, T DefaultValue>
EffectiveCell<T, DefaultValue>::operator T() const {

    typename std::map<size_t, T>::iterator itr = host_row_->find(index_);
    if (itr != host_row_->end()) {
        return itr->second;
    }
    return DefaultValue;
}

template <typename T, T DefaultValue>
EffectiveCell<T, DefaultValue> & EffectiveCell<T, DefaultValue>::operator= (const T & rhs_value) {

    if (nullptr == host_row_)
        throw std::logic_error("EffectiveCell and InfiniteRow are not binded");

    if (DefaultValue != rhs_value) {

        auto itr = host_row_->find(index_); //, rhs_value);
        if (host_row_->end() != itr) {
            itr->second = rhs_value;
        } else {
            host_row_->insert(index_, rhs_value);
        }

    } else if (DefaultValue == rhs_value) {
        // check if it exists, then remove
        host_row_->remove(index_);
    }

    return *this;
}

template <typename T, T DefaultValue>
bool operator== (const EffectiveCell<T, DefaultValue> & lhs, const T & rhs) {
    T value = lhs;
    return (value == rhs);
}

template <typename T, T DefaultValue>
bool operator== (const T & lhs, const EffectiveCell<T, DefaultValue> & rhs) {
    T value = rhs;
    return (lhs == value);
}

// End of the file
