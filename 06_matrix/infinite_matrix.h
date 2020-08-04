#ifndef _INIFINITE_MATRIX_H_
#define _INIFINITE_MATRIX_H_

#include <map>
#include <memory>
#include <iostream>

template <typename T, T DefaultValue> class InfiniteRow;

template <typename T, T DefaultValue>
class InfiniteMatrix {
public:

    class Iterator {
    public:
        friend class InfiniteMatrix;

        Iterator operator++ () {

            Iterator buffer = *this;

            ++cell_itr_;
            if (cell_itr_ == rows_itr_->second->end()) {
                ++rows_itr_;

                if (rows_itr_ != rows_itr_end_) {
                    cell_itr_ = rows_itr_->second->begin();
                }
            }
            return buffer;
        }

        bool operator!= (const Iterator rhs) {

            if (rows_itr_ != rhs.rows_itr_) return true;
            if (cell_itr_ != rhs.cell_itr_) return true;

            return false;
        }

        std::tuple<size_t, size_t, T> operator* () {

            const size_t i = rows_itr_->first;
            const size_t j = cell_itr_->first;
            const T value  = cell_itr_->second;
            return std::move(std::make_tuple(i, j, value));
        }

    private:
        typename std::map<size_t, std::shared_ptr<InfiniteRow<T, DefaultValue>>>::iterator rows_itr_;
        typename std::map<size_t, T>::iterator cell_itr_;
        typename std::map<size_t, std::shared_ptr<InfiniteRow<T, DefaultValue>>>::iterator rows_itr_end_;
    };

public:
    InfiniteMatrix();
    ~InfiniteMatrix();

    size_t size() const;

    InfiniteRow<T, DefaultValue> & operator[](const size_t index);

    Iterator begin();
    Iterator end();

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
