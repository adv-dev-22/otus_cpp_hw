#include "shapes_2d.h"
#include <cmath>
#include <iostream>

namespace GraphicalEditorCore {

template <typename T>
CircleShape2D<T>::CircleShape2D(const size_t id):
BaseShape2D<T>(id),
center_2d_{T(0), T(0)},
radius_(T(0)) {
    std::cout << " Empty Circle ctor" << std::endl;
}

template <typename T>
CircleShape2D<T>::~CircleShape2D() {
    std::cout << " Circle dtor" << std::endl;
}

template <typename T>
void CircleShape2D<T>::rotate(const T clockwise_angle) {
    // Skip rotation for circle
}

template <typename T>
void CircleShape2D<T>::moveCenter(const T dx, const T dy) {
    center_2d_.x() += dx;
    center_2d_.y() += dy;
}

template <typename T>
void CircleShape2D<T>::moveVertex(const T dx, const T dy, const size_t index) {
    radius_ += sqrt(dx * dx + dy * dy); // can be redefined.
}

template <typename T>
void CircleShape2D<T>::scale(const T factor) {
// TODO:
}

template <typename T>
void CircleShape2D<T>::append(DocumentWriterBase & wr_eng) const {

    // TODO:
}

template class CircleShape2D<float>;
template class CircleShape2D<double>;

}  // End of namespace GraphicalEditorCore

// End of the file
