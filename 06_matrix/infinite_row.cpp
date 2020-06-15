// This file is included in the very bottom of infinite_row.h

template <typename T, T DefaultValue>
InfiniteRow<T, DefaultValue>::InfiniteRow():
values_() {

}


//    InfiniteRow(const InfiniteRow & );
//    InfiniteRow(InfiniteRow && );

//    InfiniteRow & operator = (const InfiniteRow & );
//    InfiniteRow & operator = (InfiniteRow && );

template <typename T, T DefaultValue>
InfiniteRow<T, DefaultValue>::~InfiniteRow() {

}

template <typename T, T DefaultValue>
const T InfiniteRow<T, DefaultValue>::operator[] (const size_t index) const {

std::cout << "1: " << index << std::endl;
    auto itr_idx = values_.find(index);
    if (values_.end() != itr_idx) return itr_idx->second;

    return DefaultValue;
}

template <typename T, T DefaultValue>
T& InfiniteRow<T, DefaultValue>::operator[] (const size_t index) {

std::cout << "2: " << index << std::endl;
    using map_sz_T_itr = typename std::map<size_t, T>::iterator;
    std::pair<map_sz_T_itr, bool> result = values_.insert(std::pair(index, DefaultValue));

    // Item with such an index exists or default value will be inserted
    return result.first->second;
}

template <typename T, T DefaultValue>
size_t InfiniteRow<T, DefaultValue>::size() const {
    return values_.size();
}

//friend bool operator == (const InfiniteRow & inf_row_1, const InfiniteRow & inf_row_2);


// End of the file


