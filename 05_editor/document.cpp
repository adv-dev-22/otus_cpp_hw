#include "document.h"
#include <iostream>

namespace GraphicalEditorCore {

Document::Document(std::shared_ptr<DocumentParametersInterface> shp_dpi):
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
Document::~Document() {
    std::cout << "Document dtor" << std::endl;
}





}  // End of namespace GraphicalEditorCore.

// End of the file
