#include "point_2d.h"

namespace GraphicalEditorCore {

template <typename T>
Point2D<T>::Point2D():
x_{static_cast<T>(0)},
y_{static_cast<T>(0)} {

}

template <typename T>
Point2D<T>::Point2D(const T x, const T y):
x_{x},
y_{y} {

}

template <typename T>
Point2D<T>::~Point2D() {

}

template <typename T>
Point2D<T>::Point2D(const Point2D & rhs) noexcept:
x_{rhs.x_},
y_{rhs.y_} {

}

template <typename T>
Point2D<T>::Point2D(Point2D && rhs_data) noexcept:
x_{rhs_data.x_},
y_{rhs_data.y_} {

}

template <typename T>
Point2D<T> & Point2D<T>::operator= (const Point2D & rhs) noexcept {

    if (this != &rhs) {
        x_ = rhs.x_;
        y_ = rhs.y_;
    }

    return *this;
}

template <typename T>
Point2D<T> & Point2D<T>::operator= (Point2D && rhs_data) noexcept {

    if (this != &rhs_data) {
        x_ = rhs_data.x_;
        y_ = rhs_data.y_;
    }
    return *this;
}

template <typename T>
const T Point2D<T>::x() const noexcept {
    return x_;
}

template <typename T>
const T Point2D<T>::y() const noexcept {
    return y_;
}

template <typename T>
T & Point2D<T>::x() noexcept {
    return x_;
}

template <typename T>
T & Point2D<T>::y() noexcept {
    return y_;
}


template class Point2D<float>;
template class Point2D<double>;

} // End of namespace GraphicalEditorCore.

// End of the file
