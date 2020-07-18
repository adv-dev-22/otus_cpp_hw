#include "shapes_2d.h"

namespace GraphicalEditorCore {


template <typename T>
CompositeShape2D<T>::CompositeShape2D(const size_t id):
BaseShape2D<T>(id),
shapes_2d_() {

}

template <typename T>
CompositeShape2D<T>::~CompositeShape2D() {

}

template <typename T>
void CompositeShape2D<T>::add(std::unique_ptr<CompositeShape2D<T>> && shape_composite_2d) {

    const size_t id_sh = shape_composite_2d->id();

    using pair_size_shape = std::pair<size_t, std::unique_ptr<CompositeShape2D<T>>>;
    shapes_2d_.insert(pair_size_shape(id_sh, std::move(shape_composite_2d)));
}

template <typename T>
void CompositeShape2D<T>::rotate(const T clockwise_angle) {

    for (auto shape_item = shapes_2d_.begin(); shape_item != shapes_2d_.end(); ++shape_item) {
        shape_item->second->rotate(clockwise_angle);
    }
}

template <typename T>
void CompositeShape2D<T>::moveCenter(const T dx, const T dy) {

    for (auto shape_item = shapes_2d_.begin(); shape_item != shapes_2d_.end(); ++shape_item) {
        shape_item->second->moveCenter(dx, dy);
    }
}

template <typename T>
void CompositeShape2D<T>::moveVertex(const T dx, const T dy, const size_t index) {
    // TODO:
}

template <typename T>
void CompositeShape2D<T>::scale(const T factor) {
    // TODO:
}


template class CompositeShape2D<float>;
template class CompositeShape2D<double>;

}  // End of the namespace GraphicalEditorCore

// End of the file
