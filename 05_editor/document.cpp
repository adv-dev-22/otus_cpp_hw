#include "document.h"
#include "document_writer.h"
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

template <typename T>
void Document<T>::append(DocumentWriterBase & wr_eng) {

    // For several documents write first the number of documents
    // and for each doc to write its ID.
    // We proceed in a text format just to validate results directly

    // Currently only one document is supported.
    // \n is added only for human readability.
    wr_eng.append("1\n");

    // Write document parameters data
    auto tmp_shp_params = wp_doc_params_.lock();
    if (tmp_shp_params) {
        tmp_shp_params->append(wr_eng);
    }
    else {
        throw std::bad_weak_ptr();
    }

    // Write shapes info.
    shapes_2d_.append(wr_eng);
}

template class Document<float>;
template class Document<double>;

}  // End of namespace GraphicalEditorCore.

// End of the file
