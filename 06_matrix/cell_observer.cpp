// This file is included in "cell_observer.h"

template <typename T, T DefaultValue>
CellObserver<T, DefaultValue>::CellObserver():
host_row_(nullptr),
index_for_update_(0) {

}

template <typename T, T DefaultValue>
void CellObserver<T, DefaultValue>::set_index(const size_t index) {
    index_for_update_ = index;
}



template <typename T, T DefaultValue>
void CellObserver<T, DefaultValue>::bind(InfiniteRow<T, DefaultValue> * const host_row) {
    host_row_ = host_row;
}



template <typename T, T DefaultValue>
CellObserver<T, DefaultValue> & CellObserver<T, DefaultValue>::operator= (const T & rhs_value) {

    if (DefaultValue != rhs_value && nullptr != host_row_) {
        host_row_->set_value_(index_for_update_, rhs_value);
    }

    if (DefaultValue != rhs_value && nullptr != host_row_) {
        //host_row_->set_value_(index_for_update_, rhs_value);
        // remove value
    }

    return *this;
}


// End of the file
