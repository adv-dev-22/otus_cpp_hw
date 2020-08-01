// This file is included in the very bottom of infinite_matrix.h

template <typename T, T DefaultValue>
InfiniteMatrix<T, DefaultValue>::InfiniteMatrix():
rows_() {

}

template <typename T, T DefaultValue>
InfiniteMatrix<T, DefaultValue>::~InfiniteMatrix() {

}

template <typename T, T DefaultValue>
size_t InfiniteMatrix<T, DefaultValue>::size() const {

    size_t sum_size = 0;
    for (auto & item : rows_) {
        sum_size += item.second->size();
    }
    return sum_size;
}

template <typename T, T DefaultValue>
InfiniteRow<T, DefaultValue> & InfiniteMatrix<T, DefaultValue>::operator[](const size_t index) {

    auto itr = rows_.find(index);
    if (itr != rows_.end()) {
        return *itr->second.get();
    } else {
        auto pair_rez = rows_.emplace(index, std::make_shared<InfiniteRow<T, DefaultValue>>());
        return *pair_rez.first->second.get();
        // TODO: set index
    }
}

// End of the file
