#ifndef _INIFINITE_ROW_H_
#define _INIFINITE_ROW_H_

#include <map>
#include <memory>

template <typename T, T DefaultValue> class EffectiveCell;

/*! Indexing starts from 0 and ends at infinity. */
template <typename T, T DefaultValue>
class InfiniteRow {
public:
    InfiniteRow();
    virtual ~InfiniteRow();

    EffectiveCell<T, DefaultValue> & operator[] (const size_t index);

    size_t size() const;

    typename std::map<size_t, T>::iterator find(const size_t index);
    typename std::map<size_t, T>::iterator begin();
    typename std::map<size_t, T>::iterator end();

    void insert(const size_t index, const T& value);
    void remove(const size_t index);

private:
    /*! According to problem statement, we do not implement internal
     *  data structures to achive fastest performance.
     *  We do not assume the matrix (and row) class will be used in
     *  fastest computations. Otherwise more tricky data structures are required.
     *  (with O(1) access).
     */
    std::map<size_t, T> values_;

    /*! One observer for the whole row. It is not thread safety for elements
     *  inside one row and it is thread safety for different rows.
     */
    std::unique_ptr<EffectiveCell<T, DefaultValue>> up_effective_cell_;

private:
    InfiniteRow(const InfiniteRow & ) = delete;
    InfiniteRow(InfiniteRow && )      = delete;
    InfiniteRow & operator = (const InfiniteRow & ) = delete;
    InfiniteRow & operator = (InfiniteRow && )      = delete;
};

/*! InfiniteRow depends on numerical type (second parameter).
 *  That is why we can not use explicit instantiation
 *  like "template class InfiniteRow<double, -100.0>"
 *  because of many possible use cases.
 */
#include <iostream>
#include "infinite_row.cpp"

#endif // _INIFINITE_MATRIX_H_


