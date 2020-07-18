#include "shapes_2d.h"

namespace GraphicalEditorCore {

template <typename T>
TriangleShape2D<T>::TriangleShape2D(const size_t id):
BaseShape2D<T>(id),
points_2d_() {
    points_2d_.fill(Point2D(T(0),T(0)));
}

template <typename T>
TriangleShape2D<T>::~TriangleShape2D() {

}

template <typename T>
void TriangleShape2D<T>::rotate(const T clockwise_angle) {

    for (auto point : points_2d_) {
        point.x() = 0.; // sin_a * x +/- cos_a y
        // y = ...
    }
}

template <typename T>
void TriangleShape2D<T>::moveCenter(const T dx, const T dy) {
    // TODO:
}

template <typename T>
void TriangleShape2D<T>::moveVertex(const T dx, const T dy, const size_t index) {

    if (index >= 3) throw std::out_of_range("Attempt to get access to >= 3 triangle points");

    // TODO:
}

template <typename T>
void TriangleShape2D<T>::scale(const T factor) {
    // TODO:
}


template class TriangleShape2D<float>;
template class TriangleShape2D<double>;

}  // End of namespace GraphicalEditorCore

// End of the file
