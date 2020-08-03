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
    for (const auto & item : rows_) {
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

template <typename T, T DefaultValue>
typename InfiniteMatrix<T, DefaultValue>::Iterator InfiniteMatrix<T, DefaultValue>::begin() {

    InfiniteMatrix<T, DefaultValue>::Iterator tmp_itr;

    tmp_itr.rows_itr_ = rows_.begin();
    tmp_itr.cell_itr_ = rows_.begin()->second->begin();

    return tmp_itr;
}

template <typename T, T DefaultValue>
typename InfiniteMatrix<T, DefaultValue>::Iterator InfiniteMatrix<T, DefaultValue>::end() {

    InfiniteMatrix<T, DefaultValue>::Iterator tmp_itr;

    tmp_itr.rows_itr_ = rows_.end();

    return tmp_itr;
}

// End of the file
