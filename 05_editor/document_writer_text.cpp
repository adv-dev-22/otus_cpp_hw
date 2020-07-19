#include "document_writer.h"
#include <fstream>

namespace GraphicalEditorCore {

DocumentWriterText::DocumentWriterText():
DocumentWriterBase(),
ofs_() {

}

DocumentWriterText::~DocumentWriterText() {
}

//virtual
void DocumentWriterText::prepare() {
    ofs_.open(this->storage_name_, std::ofstream::out | std::ofstream::out);
}

void DocumentWriterText::close() {

    // TODO: check if it is open

    ofs_.close();
}

void DocumentWriterText::append(const std::string & msg) {
    ofs_ << msg;
}

}  // End of namespace GraphicalEditorCore.

// End of the file
