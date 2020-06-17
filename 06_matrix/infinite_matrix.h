#ifndef _INIFINITE_MATRIX_H_
#define _INIFINITE_MATRIX_H_

#include <map>

template <typename T, T DefaultValue> class InfiniteRow;
template <typename T, T DefaultValue> class RowObserver;


template <typename T, T DefaultValue>
class InfiniteMatrix {
public:
    InfiniteMatrix();
    ~InfiniteMatrix();

    size_t size() const;

    //const InfiniteRow<T, DefaultValue> & operator[](const size_t index) const;

    //MatrixObserver<T, DefaultValue> & operator[](const size_t index);

private:

//    std::map<size_t, >   rows_;

    //rows also will be observers when whole the row is zero.



    InfiniteMatrix(const InfiniteMatrix & ) = delete;
    InfiniteMatrix(InfiniteMatrix && )      = delete;
    InfiniteMatrix & operator= (const InfiniteMatrix & ) = delete;
    InfiniteMatrix & operator= (InfiniteMatrix && )      = delete;
};

#include "infinite_matrix.cpp"

#endif // _INIFINITE_MATRIX_H_
