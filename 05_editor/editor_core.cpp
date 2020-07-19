#include "editor_core.h"
#include "document_parameters.h"
#include <iostream>
#include <fstream>

namespace GraphicalEditorCore {

template <typename T>
EditorCore<T>::EditorCore():
up_doc_writer_(nullptr),
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
void EditorCore<T>::reset_writer(std::unique_ptr<DocumentWriterBase> && doc_writer) {
    up_doc_writer_ = std::move(doc_writer);
}

template <typename T>
void EditorCore<T>::save(const std::string & file) {

    if (nullptr == up_doc_writer_) {throw std::runtime_error("Nullptr writing engine.");}
    up_doc_writer_->set_storage_name(file);
    up_doc_writer_->prepare();

    // For each document in container append document data to the file
    up_document_->append(*up_doc_writer_);

    up_doc_writer_->close();
}


template class EditorCore<float>;
template class EditorCore<double>;

} // End of namespace GraphicalEditorCore.

// End of the file
