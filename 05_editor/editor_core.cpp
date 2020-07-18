#include "editor_core.h"
#include "document_parameters.h"
#include <iostream>

namespace GraphicalEditorCore {

template <typename T>
EditorCore<T>::EditorCore():
up_document_(nullptr) {
    std::cout << "EditorCore ctor" << std::endl;
}

//virtual
template <typename T>
EditorCore<T>::~EditorCore() {
    std::cout << "EditorCore dtor" << std::endl;
}

template <typename T>
Document<T> & EditorCore<T>::create_document(std::shared_ptr<DocumentParametersInterface> shp_dpi) {

    up_document_ = std::make_unique<Document<T>>(shp_dpi);
    return *up_document_;
}

template <typename T>
void EditorCore<T>::save(const std::string & file) {

    // open fstream

    // For each document in container
    // append document data to the file

    // close fstream
}


template class EditorCore<float>;
template class EditorCore<double>;

} // End of namespace GraphicalEditorCore.

// End of the file
