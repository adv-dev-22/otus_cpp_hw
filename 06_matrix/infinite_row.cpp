// This file is included in the very bottom of infinite_row.h

#include <iostream>
#include <map>

template <typename T, T DefaultValue>
InfiniteRow<T, DefaultValue>::InfiniteRow():
values_(),
up_cell_observer_(nullptr) {

}

template <typename T, T DefaultValue>
InfiniteRow<T, DefaultValue>::~InfiniteRow() {

}

//template <typename T, T DefaultValue>
//const T InfiniteRow<T, DefaultValue>::operator[] (const size_t index) const {

//std::cout << "1: " << index << std::endl;
//    auto itr_idx = values_.find(index);
//    if (values_.end() != itr_idx) return itr_idx->second;

//    return DefaultValue;
//}

template <typename T, T DefaultValue>
CellObserver<T, DefaultValue> & InfiniteRow<T, DefaultValue>::operator[] (const size_t index) {

    // Lazy initialization
    if (nullptr == up_cell_observer_) {
        up_cell_observer_ = std::make_unique<CellObserver<T, DefaultValue>>();
        up_cell_observer_->bind(this);
    }

    up_cell_observer_->set_index(index);

    return *up_cell_observer_;
}

template <typename T, T DefaultValue>
size_t InfiniteRow<T, DefaultValue>::size() const {
    return values_.size();
}

template <typename T, T DefaultValue>
typename std::map<size_t, T>::iterator
InfiniteRow<T, DefaultValue>::find(const size_t index) {
    return values_.find(index);
}

template <typename T, T DefaultValue>
typename std::map<size_t, T>::iterator
InfiniteRow<T, DefaultValue>::end() {
    return values_.end();
}

template <typename T, T DefaultValue>
void InfiniteRow<T, DefaultValue>::insert(const size_t index, const T& value) {

    std::pair<typename std::map<size_t, T>::iterator, bool> result;
    result = values_.insert(std::pair<size_t, T>(index, value));

    // An element at the index position already exists
    if (!result.second) {
        // first  denotes iterator to existing node with id = index
        // second denotes value in pair
        result.first->second = value;
    }
}






//template <typename T, T DefaultValue>
//void InfiniteRow<T, DefaultValue>::set_value_(const size_t index, const T & value) {

//    //..
//}

//friend bool operator == (const InfiniteRow & inf_row_1, const InfiniteRow & inf_row_2);

//template <typename T, T DefaultValue>
//InfiniteRow_Debug<T, DefaultValue>::InfiniteRow_Debug():
//InfiniteRow<T, DefaultValue>() {

//}

//template <typename T, T DefaultValue>
//InfiniteRow_Debug<T, DefaultValue>::~InfiniteRow_Debug() {

//}

// End of the file

//    InfiniteRow(const InfiniteRow & );
//    InfiniteRow(InfiniteRow && );

//    InfiniteRow & operator = (const InfiniteRow & );
//    InfiniteRow & operator = (InfiniteRow && );

//std::cout << "2: " << index << std::endl;
    //using map_sz_T_itr = typename std::map<size_t, T>::iterator;
    //std::pair<map_sz_T_itr, bool> result = values_.insert(std::pair(index, DefaultValue));

    // Item with such an index exists or default value will be inserted
    //return result.first->second;
