#ifndef _ROW_OBSERVER_H_
#define _ROW_OBSERVER_H_

template <typename T, T DefaultValue>
class RowObserver {
public:
    RowObserver();
    virtual ~RowObserver();

    CellObserver & operator[] (const size_t index);


private:

    RowObserver(const RowObserver & ) = delete;
    RowObserver(RowObserver && )      = delete;
    RowObserver & operator= (const RowObserver & ) = delete;
    RowObserver & operator= (RowObserver && )      = delete;
};

/*! RowObserver depends on numerical type (second parameter).
 *  That is why we can not use explicit instantiation
 *  like "template class RowObserver<unsigned int, 1234567>"
 *  because of many possible use cases.
 */
#include "row_observer.cpp"

#endif  // _ROW_OBSERVER_H_
