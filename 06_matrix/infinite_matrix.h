#ifndef _INIFINITE_MATRIX_H_
#define _INIFINITE_MATRIX_H_

#include <map>
#include <memory>

template <typename T, T DefaultValue> class InfiniteRow;

template <typename T, T DefaultValue>
class InfiniteMatrix {
public:
    InfiniteMatrix();
    ~InfiniteMatrix();

    size_t size() const;

    InfiniteRow<T, DefaultValue> & operator[](const size_t index);

private:
    /*! Matrix rows. Not empty. */
    std::map<size_t, std::shared_ptr<InfiniteRow<T, DefaultValue>>> rows_;

private:
    InfiniteMatrix(const InfiniteMatrix & ) = delete;
    InfiniteMatrix(InfiniteMatrix && )      = delete;
    InfiniteMatrix & operator= (const InfiniteMatrix & ) = delete;
    InfiniteMatrix & operator= (InfiniteMatrix && )      = delete;
};

#include "infinite_matrix.cpp"

#endif // _INIFINITE_MATRIX_H_
