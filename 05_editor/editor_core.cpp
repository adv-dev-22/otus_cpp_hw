#include "editor_core.h"
#include "document_parameters.h"
#include <iostream>

namespace GraphicalEditorCore {

EditorCore::EditorCore():
up_document_(nullptr) {
    std::cout << "EditorCore ctor" << std::endl;
}

//virtual
EditorCore::~EditorCore() {
    std::cout << "EditorCore dtor" << std::endl;
}

Document & EditorCore::create_document(std::shared_ptr<DocumentParametersInterface> shp_dpi) {

    up_document_ = std::make_unique<Document>(shp_dpi);
    return *up_document_;
}

void EditorCore::save(const std::string & file) {

    // open fstream

    // For each document in container
    // append document data to the file

    // close fstream
}


} // End of namespace GraphicalEditorCore.

// End of the file
