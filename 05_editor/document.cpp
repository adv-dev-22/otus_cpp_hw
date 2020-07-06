#include "document.h"
#include <iostream>

namespace GraphicalEditorCore {

Document::Document() {
    std::cout << "Document ctor" << std::endl;
}

//virtual
Document::~Document() {
    std::cout << "Document dtor" << std::endl;
}

}  // End of namespace GraphicalEditorCore.

// End of the file
