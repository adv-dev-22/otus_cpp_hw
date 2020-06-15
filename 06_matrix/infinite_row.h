#ifndef _INIFINITE_ROW_H_
#define _INIFINITE_ROW_H_

#include <map>

template <typename T, T DefaultValue>
class CellObserver;

/*! Indexing starts from 0 and ends at infinity. */
template <typename T, T DefaultValue>
class InfiniteRow {
public:
    InfiniteRow();
    virtual ~InfiniteRow();

    void set_cell_observer(CellObserver<T, DefaultValue> * const cell_observer);

    //const T operator[] (const size_t index) const;
    CellObserver<T, DefaultValue> & operator[] (const size_t index);

    size_t size() const;

    //friend bool operator == (const InfiniteRow & inf_row_1, const InfiniteRow & inf_row_2);

private:
    /*! According to problem statement, we do not implement internal
     *  data structures to achive fastest performance.
     *  We do not assume the matrix (and row) class will be used in
     *  fastest computations. Otherwise more tricky data structures are required.
     *  (with O(1) access).
     */
    std::map<size_t, T> values_;

    CellObserver<T, DefaultValue> * cell_observer_;

    /*! Observer updates private fields. */
    friend CellObserver<T, DefaultValue>;
    void set_value_(const size_t index, const T & value);

private:
    InfiniteRow(const InfiniteRow & ) = delete;
    InfiniteRow(InfiniteRow && )      = delete;
    InfiniteRow & operator = (const InfiniteRow & ) = delete;
    InfiniteRow & operator = (InfiniteRow && )      = delete;
};

/*! Class is introduced for tests only.
 *  It uses auxiliary API to validate internal state.
 */
template <typename T, T DefaultValue>
class InfiniteRow_Debug : public InfiniteRow<T, DefaultValue> {
public:
    InfiniteRow_Debug();
    virtual ~InfiniteRow_Debug();

    bool is_cell_observer_valid() const;

private:


};



/*! InfiniteRow depends on numerical type (second parameter).
 *  That is why we can not use explicit instantiation
 *  like "template class InfiniteRow<double, -100.0>"
 *  because of many possible use cases.
 */
#include <iostream>
#include "infinite_row.cpp"

#endif // _INIFINITE_MATRIX_H_
