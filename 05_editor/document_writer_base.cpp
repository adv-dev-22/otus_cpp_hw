#include "document_writer.h"

namespace GraphicalEditorCore {

DocumentWriterBase::DocumentWriterBase():
storage_name_("undefined") {

}

DocumentWriterBase::~DocumentWriterBase() {
}

void DocumentWriterBase::set_storage_name(const std::string st_name) {
    storage_name_ = st_name;
}

}  // End of namespace GraphicalEditorCore.

// End of the file
