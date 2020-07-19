#include "shapes_2d.h"
#include "document_writer.h"
#include <iostream>
#include <string>

namespace GraphicalEditorCore {

template <typename T>
BaseShape2D<T>::BaseShape2D(const size_t id):
id_(id),
uptr_color_engine_(nullptr) {

}

template <typename T>
BaseShape2D<T>::~BaseShape2D() {

}

template <typename T>
void BaseShape2D<T>::resetColorEngine(ColorEngineBase * color_engine) {
    uptr_color_engine_.reset(color_engine);
}

template <typename T>
const ColorEngineBase & BaseShape2D<T>::colorEngine() const {
    return *uptr_color_engine_;
}

template <typename T>
const size_t BaseShape2D<T>::id() const noexcept {
    return id_;
}

template <typename T>
void BaseShape2D<T>::debug_print() {
    std::cout << "--------------" << std::endl;
}

template <typename T>
void BaseShape2D<T>::append(DocumentWriterBase & wr_eng) const {

    wr_eng.append(std::to_string(this->id()));
    wr_eng.append(" ");

    //uptr_color_engine_->append(wr_eng);
}


template class BaseShape2D<float>;
template class BaseShape2D<double>;

} // End of the namespace GraphicalEditorCore

// End of the file
