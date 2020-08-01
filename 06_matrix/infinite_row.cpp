// This file is included in the very bottom of infinite_row.h

#include <iostream>
#include <map>

template <typename T, T DefaultValue>
InfiniteRow<T, DefaultValue>::InfiniteRow():
values_(),
up_effective_cell_(nullptr) {

}

template <typename T, T DefaultValue>
InfiniteRow<T, DefaultValue>::~InfiniteRow() {

}

template <typename T, T DefaultValue>
EffectiveCell<T, DefaultValue> & InfiniteRow<T, DefaultValue>::operator[] (const size_t index) {

    // Lazy initialization
    if (nullptr == up_effective_cell_) {
        up_effective_cell_ = std::make_unique<EffectiveCell<T, DefaultValue>>();
        up_effective_cell_->bind(this);
    }

    up_effective_cell_->set_index(index);

    return *up_effective_cell_;
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

template <typename T, T DefaultValue>
void InfiniteRow<T, DefaultValue>::remove(const size_t index) {
    values_.erase(index);
    // send message to matrix to remove empty row
}

// End of the file
