#ifndef _CELL_OBSERVER_H_
#define _CELL_OBSERVER_H_

#include <cstddef>

// Forward declaration
template <typename T, T DefaultValue> class InfiniteRow;

template <typename T, T DefaultValue>
class CellObserver final {
public:
    CellObserver();
    ~CellObserver() = default;

    /*! Saves index of cell for a corresponding row. */
    void set_index(const size_t index);

    void bind(InfiniteRow<T, DefaultValue> * const host_row);

    /*! Return T value when it is in the right hand side position. */
    operator T() const;

    /*! Operator is used for cells assignment:
     *  it calls update value of row if and only if
     *  it does not coincide with the default value. */
    CellObserver & operator= (const T & rhs_value);

private:
    size_t index_;
    InfiniteRow<T, DefaultValue> * host_row_;

    CellObserver(const CellObserver & ) = delete;
    CellObserver(CellObserver && )      = delete;
    CellObserver & operator= (const CellObserver & ) = delete;
    CellObserver & operator= (CellObserver && )      = delete;
};


template <typename T, T DefaultValue>
bool operator== (const CellObserver<T, DefaultValue> & lhs, const T & rhs);

template <typename T, T DefaultValue>
bool operator== (const T & lhs, const CellObserver<T, DefaultValue> & rhs);


// Necessary for separate template implementation.
#include "cell_observer.cpp"

#endif  // _CELL_OBSERVER_H_

// End of the file
