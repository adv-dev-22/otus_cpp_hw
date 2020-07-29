#ifndef _EFFECTIVE_CELL_H_
#define _EFFECTIVE_CELL_H_

#include <cstddef>

// Forward declaration
template <typename T, T DefaultValue> class InfiniteRow;

template <typename T, T DefaultValue>
class EffectiveCell final {
public:
    EffectiveCell();
    ~EffectiveCell() = default;

    /*! Saves index of cell for a corresponding row. */
    void set_index(const size_t index);

    void bind(InfiniteRow<T, DefaultValue> * const host_row);

    /*! Return T value when it is in the right hand side position. */
    operator T() const;

    /*! Operator is used for cells assignment:
     *  it calls update value of row if and only if
     *  it does not coincide with the default value. */
    EffectiveCell & operator= (const T & rhs_value);

private:
    size_t index_;
    InfiniteRow<T, DefaultValue> * host_row_;

private:
    EffectiveCell(const EffectiveCell & ) = delete;
    EffectiveCell(EffectiveCell && )      = delete;
    EffectiveCell & operator= (const EffectiveCell & ) = delete;
    EffectiveCell & operator= (EffectiveCell && )      = delete;
};


template <typename T, T DefaultValue>
bool operator== (const EffectiveCell<T, DefaultValue> & lhs, const T & rhs);

template <typename T, T DefaultValue>
bool operator== (const T & lhs, const EffectiveCell<T, DefaultValue> & rhs);


// Necessary for separate template implementation.
#include "effective_cell.cpp"

#endif  // _EFFECTIVE_CELL_H_

// End of the file
