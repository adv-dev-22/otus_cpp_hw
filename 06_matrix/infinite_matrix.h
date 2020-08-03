#ifndef _INIFINITE_MATRIX_H_
#define _INIFINITE_MATRIX_H_

#include <map>
#include <memory>

template <typename T, T DefaultValue> class InfiniteRow;

template <typename T, T DefaultValue>
class InfiniteMatrix {
public:

    class Iterator {
    public:

        friend class InfiniteMatrix;

        Iterator operator++ (int ) {

            if (cell_itr_ == rows_itr_->second->end()) {
                ++rows_itr_;
                cell_itr_ = rows_itr_->second->begin();
            }
            else {
                ++cell_itr_;
            }
            return *this;
        }

        Iterator operator++ () {

            Iterator buffer = *this;

            if (cell_itr_ == rows_itr_->second->end()) {
                ++rows_itr_;
                cell_itr_ = rows_itr_->second->begin();
            }
            else {
                ++cell_itr_;
            }
            return buffer;
        }

        bool operator!= (const Iterator) {

            return false;
        }

//        EffectiveCell & operator* (Iterator) {
//            return cell_itr_->;
//        }

    private:
        typename std::map<size_t, std::shared_ptr<InfiniteRow<T, DefaultValue>>>::iterator rows_itr_;
        typename std::map<size_t, T>::iterator cell_itr_;
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
