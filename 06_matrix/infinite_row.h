#ifndef _INIFINITE_ROW_H_
#define _INIFINITE_ROW_H_

#include <map>

/*! Indexing starts from 0 and ends at infinity.
 */
template <typename T, T DefaultValue>
class InfiniteRow final {
public:
    InfiniteRow();
    InfiniteRow(const InfiniteRow & );
    InfiniteRow(InfiniteRow && );

    InfiniteRow & operator = (const InfiniteRow & );
    InfiniteRow & operator = (InfiniteRow && );

    ~InfiniteRow();

    const T  operator[] (const size_t index) const;
    T& operator[] (const size_t index);

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
};

#include <iostream>
/*! InfiniteRow depends on numerical type (second parameter).
 *  That is why we can not use explicit instantiation
 *  like "template class InfiniteRow<double, -100.0>"
 *  because of many possible use cases.
 */
#include "infinite_row.cpp"

#endif // _INIFINITE_MATRIX_H_
