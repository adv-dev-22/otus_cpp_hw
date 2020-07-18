#include "document.h"
#include <iostream>
#include <memory>

namespace GraphicalEditorCore {

template <typename T>
Document<T>::Document(std::shared_ptr<DocumentParametersInterface> shp_dpi):
wp_doc_params_(shp_dpi) {

    std::cout << "Document ctor" << std::endl;

    auto tmp_shp_params = wp_doc_params_.lock();
    if (tmp_shp_params) {
        std::cout << "document created with: ";
        std::cout << "width  = " << tmp_shp_params->width() ;
        std::cout << ", height = " << tmp_shp_params->height();
        std::cout << std::endl;
    }
    else {
        throw std::bad_weak_ptr();
    }
}

//virtual
template <typename T>
Document<T>::~Document() {
    std::cout << "Document dtor" << std::endl;
}

template <typename T>
void Document<T>::add_shape(std::unique_ptr<BaseShape2D<T>> && shape_2d) {
    shapes_2d_.add(std::move(shape_2d));
}

template <typename T>
void Document<T>::remove_shape(const size_t id) {

}


template class Document<float>;
template class Document<double>;

}  // End of namespace GraphicalEditorCore.

// End of the file
