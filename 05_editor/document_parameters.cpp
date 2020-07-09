#include "document_parameters.h"
#include <iostream>

namespace GraphicalEditorCore {

DocumentParameters::DocumentParameters():
DocumentParametersInterface() {
    std::cout << "DocumentParameters ctor" << std::endl;
}

DocumentParameters::DocumentParameters(const DocumentParameters & ) {

}

DocumentParameters::DocumentParameters(DocumentParameters && ) {

}

DocumentParameters & DocumentParameters::operator = (const DocumentParameters & ) {
    return *this;
}

DocumentParameters & DocumentParameters::operator = (DocumentParameters && ) {
    return *this;
}

DocumentParameters::~DocumentParameters() {
    std::cout << "DocumentParameters dtor" << std::endl;
}

size_t DocumentParameters::width() const {
    return width_;
}

size_t DocumentParameters::height() const {
    return height_;
}

//size_t DocumentParameters::colorDepth() const {
//    return color_depth_;
//}

} // End of namespace GraphicalEditorCore.

// End of the file
