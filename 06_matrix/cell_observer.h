#ifndef _CELL_OBSERVER_H_
#define _CELL_OBSERVER_H_

// Forward declaration
template <typename T, T DefaultValue>
class InfiniteRow;

template <typename T, T DefaultValue>
class CellObserver final {
public:
    CellObserver();
    ~CellObserver() = default;

    void set_index(const size_t index);

    void bind(InfiniteRow<T, DefaultValue> * const host_row);

    /*! Operator is used for cells assignment:
     *  it calls update value of row if and only if
     *  it does not coincide with the default value. */
    CellObserver & operator= (const T & rhs_value);

private:
    InfiniteRow<T, DefaultValue> * host_row_;
    size_t index_for_update_;

    CellObserver(const CellObserver & ) = delete;
    CellObserver(CellObserver && )      = delete;
    CellObserver & operator= (const CellObserver & ) = delete;
    CellObserver & operator= (CellObserver && )      = delete;
};

// Necessary for separate template implementation.
#include "cell_observer.cpp"

#endif  // _CELL_OBSERVER_H_

// End of the file
