#include "shapes_2d.h"

namespace GraphicalEditorCore {

template <typename T>
CircleShape2D<T>::CircleShape2D(const size_t id):
BaseShape2D<T>(id),
center_2d_{T(0), T(0)},
radius_(T(0)) {

}

template <typename T>
CircleShape2D<T>::~CircleShape2D() {

}

template <typename T>
void CircleShape2D<T>::rotate(const T clockwise_angle) {
    // Skip rotation for circle
}

template <typename T>
void CircleShape2D<T>::moveCenter(const T dx, const T dy) {
// TODO:
}

template <typename T>
void CircleShape2D<T>::moveVertex(const T dx, const T dy, const size_t index) {
// TODO:
}

template <typename T>
void CircleShape2D<T>::scale(const T factor) {
// TODO:
}


template class CircleShape2D<float>;
template class CircleShape2D<double>;

}  // End of namespace GraphicalEditorCore

// End of the file
