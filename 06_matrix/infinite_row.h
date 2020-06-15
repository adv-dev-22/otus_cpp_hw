#ifndef _INIFINITE_ROW_H_
#define _INIFINITE_ROW_H_

#include <vector>

template <typename T, T DefaultValue>
class InfiniteRow final {
public:
    InfiniteRow();
    InfiniteRow(const InfiniteRow & );
    InfiniteRow(InfiniteRow && );

    InfiniteRow & operator = (const InfiniteRow & );
    InfiniteRow & operator = (InfiniteRow && );

    ~InfiniteRow();

    const T & operator[] (const size_t index) const;
    T & operator[] (const size_t index);

    /*! \return position in row.
     *  For row {..., zero_position, x, 1, 2, x, 3, x, 4, x, x, 5, ...}
     *  position(0) == 2,
     *  position(1) == 3,
     *  position(2) == 5,
     *  position(3) == 7,
     *  position(4) == 10
     */
    size_t position(const size_t index) const;

    size_t size() const;

private:
    std::vector<size_t> positions_;
    std::vector<T> values_;
};


/*! InfiniteRow depends on numerical type (second parameter).
 *  That is why we can not use explicit instantiation
 *  like "template class InfiniteRow<double, -100.0>"
 *  because of many possible use cases.
 */
#include "infinite_row.cpp"

#endif // _INIFINITE_MATRIX_H_
