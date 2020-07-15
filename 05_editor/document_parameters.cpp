#include "document_parameters.h"
#include "default.h"
#include <iostream>

namespace GraphicalEditorCore {

template <typename T>
DocumentParameters<T>::DocumentParameters():
DocumentParametersInterface(),
width_(Default::Document::width()),
height_(Default::Document::height()),
uptr_color_engine_(std::make_unique<T>()) {

    std::cout << "DocumentParameters ctor" << std::endl;
}

template <typename T>
DocumentParameters<T>::DocumentParameters(const DocumentParameters<T> & rhs):
width_(rhs.width_),
height_(rhs.height_),
uptr_color_engine_(std::make_unique<T>(*rhs.uptr_color_engine_)) {

    std::cout << "DocumentParameters copy ctor" << std::endl;
}

template <typename T>
DocumentParameters<T>::DocumentParameters(DocumentParameters<T> && rhs):
width_(rhs.width_),
height_(rhs.height_),
uptr_color_engine_(std::make_unique<T>(*rhs.uptr_color_engine_)) {

    std::cout << "DocumentParameters move ctor" << std::endl;
}

template <typename T>
DocumentParameters<T> & DocumentParameters<T>::operator= (const DocumentParameters<T> & rhs) {

    std::cout << "DocumentParameters copy = " << std::endl;

    if (&rhs != this) {
        width_ = rhs.width_;
        height_ = rhs.height_;
        *uptr_color_engine_ = *rhs.uptr_color_engine_;
    }
    return *this;
}

template <typename T>
DocumentParameters<T> & DocumentParameters<T>::operator= (DocumentParameters<T> && rhs) {

    std::cout << "DocumentParameters move =" << std::endl;

    if (&rhs != this) {
        width_ = rhs.width_;
        height_ = rhs.height_;
        uptr_color_engine_ = std::move(rhs.uptr_color_engine_);
    }
    return *this;
}

template <typename T>
DocumentParameters<T>::~DocumentParameters() {
    std::cout << "DocumentParameters dtor" << std::endl;
}

template <typename T>
size_t DocumentParameters<T>::width() const {
    return width_;
}

template <typename T>
size_t DocumentParameters<T>::height() const {
    return height_;
}

template <typename T>
T & DocumentParameters<T>::colorEngine() const {
    return *(uptr_color_engine_.get());
}

template <typename T>
void DocumentParameters<T>::setWidth(const size_t w) {
    width_ = w;
}

template <typename T>
void DocumentParameters<T>::setHeight(const size_t h) {
    height_ = h;
}

template <typename T>
void DocumentParameters<T>::resetColorEngine(T * const ceb_ptr) {
    uptr_color_engine_.reset(ceb_ptr);
}

template class DocumentParameters<ColorEngineUniform>;
//template class DocumentParameters<ColorEngineGradient>;


} // End of namespace GraphicalEditorCore.

// End of the file
