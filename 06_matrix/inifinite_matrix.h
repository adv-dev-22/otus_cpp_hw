#ifndef _INIFINITE_MATRIX_H_
#define _INIFINITE_MATRIX_H_

#include <vector>




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
