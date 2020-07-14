#include "document_parameters.h"
#include "default.h"
#include <iostream>

namespace GraphicalEditorCore {

DocumentParameters::DocumentParameters():
DocumentParametersInterface(),
width_(Default::Document::width()),
height_(Default::Document::height()),
uptr_color_engine_(std::make_unique<Default::ColorEngine_t<ColorEngineUniform>::Type>()) {
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

ColorEngineBase & DocumentParameters::colorEngine() const {
    return *(uptr_color_engine_.get());
}

void DocumentParameters::setColorEngine(ColorEngineBase * const ceb_ptr) {

}

} // End of namespace GraphicalEditorCore.

// End of the file
