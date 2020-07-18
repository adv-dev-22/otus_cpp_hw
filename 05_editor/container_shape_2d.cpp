#include "shapes_2d.h"

namespace GraphicalEditorCore {

template <typename T>
Shape2DContainer<T>::Shape2DContainer():
shapes_2d_() {

}

template <typename T>
Shape2DContainer<T>::~Shape2DContainer() {

}

template <typename T>
void Shape2DContainer<T>::add(std::unique_ptr<BaseShape2D<T>> && bshape_2d) {

    const size_t id_bsh = bshape_2d->id();

    using pair_size_shape = std::pair<size_t, std::unique_ptr<BaseShape2D<T>>>;
    shapes_2d_.insert(pair_size_shape(id_bsh, std::move(bshape_2d)));
}

template <typename T>
void Shape2DContainer<T>::remove(const size_t id) {

    auto item_itr = shapes_2d_.find(id);
    shapes_2d_.erase(item_itr);
}

template <typename T>
BaseShape2D<T> & Shape2DContainer<T>::find(const size_t id) {
    auto item = shapes_2d_.find(id);
    return *(item->second);
}


template class Shape2DContainer<float>;
template class Shape2DContainer<double>;

} // End of the namespace GraphicalEditorCore

// End of the file
