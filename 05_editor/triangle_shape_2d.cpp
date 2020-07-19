#include "shapes_2d.h"
#include "document_writer.h"
#include <iostream>

namespace GraphicalEditorCore {

template <typename T>
TriangleShape2D<T>::TriangleShape2D(const size_t id):
BaseShape2D<T>(id),
points_2d_() {
    points_2d_.fill(Point2D(T(0),T(0)));
    std::cout << " Empty triangle ctor" << std::endl;
}

template <typename T>
TriangleShape2D<T>::TriangleShape2D(const size_t id,
                                    const Point2D<T> & p1,
                                    const Point2D<T> & p2,
                                    const Point2D<T> & p3):
BaseShape2D<T>(id),
points_2d_() {
    points_2d_[0] = p1;
    points_2d_[1] = p2;
    points_2d_[2] = p3;
}

template <typename T>
TriangleShape2D<T>::~TriangleShape2D() {
    std::cout << " Triangle dtor" << std::endl;
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

    points_2d_[index].x() += dx;
    points_2d_[index].y() += dy;
}

template <typename T>
void TriangleShape2D<T>::scale(const T factor) {
    // TODO:
}

template <typename T>
void TriangleShape2D<T>::debug_print() {

    BaseShape2D<T>::debug_print();

    for (size_t k = 0; k < 3; ++k) {
        std::cout << std::to_string(points_2d_[k].x()) << " ";
        std::cout << std::to_string(points_2d_[k].y()) << std::endl;
    }
}

template <typename T>
void TriangleShape2D<T>::append(DocumentWriterBase & wr_eng) const {

    BaseShape2D<T>::append(wr_eng);

    // write triangle type
    for (size_t k = 0; k < 3; ++k) {
        wr_eng.append(std::to_string(points_2d_[k].x()));
        wr_eng.append(" ");
        wr_eng.append(std::to_string(points_2d_[k].y()));
        wr_eng.append(" ");
    }
}

template class TriangleShape2D<float>;
template class TriangleShape2D<double>;

}  // End of namespace GraphicalEditorCore

// End of the file
