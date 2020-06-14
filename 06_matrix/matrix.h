#ifndef _INIFINITE_MATRIX_H_
#define _INIFINITE_MATRIX_H_

#include <vector>

template <typename T, T value>
class InfiniteMatrixRow final {
public:
    InfiniteMatrixRow();
    InfiniteMatrixRow(const InfiniteMatrixRow & );
    InfiniteMatrixRow(InfiniteMatrixRow && );

    InfiniteMatrixRow & operator = (const InfiniteMatrixRow & );
    InfiniteMatrixRow & operator = (InfiniteMatrixRow && );

    ~InfiniteMatrixRow();

    const T & operator[] (const size_t) const;
    T & operator[] (const size_t index);

    /*! \return position in row.
     *  For row {x,x,1,2,x,3,x,4,x,x,5}
     *  position(0) == 2,
     *  position(1) == 3,
     *  position(2) == 5,
     *  position(3) == 7,
     *  position(4) == 10
     */
    size_t position(const size_t index) const;

    size_t size() const;

private:
    std::vector<size_t> position_;
    std::vector<T> value_;
};



template <typename T, T value>
class InfiniteMatrix {
public:

    size_t size() const;

private:

    std::vector<T> values_;
    std::vector<T> rows_;
    std::vector<T> cols_;

    // cols_;

};


#endif // _INIFINITE_MATRIX_H_
