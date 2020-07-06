#include "editor_core.h"
#include <iostream>

namespace GraphicalEditorCore {

EditorCore::EditorCore() {
    std::cout << "EditorCore ctor" << std::endl;
}

//virtual
EditorCore::~EditorCore() {
    std::cout << "EditorCore dtor" << std::endl;
}

} // End of namespace GraphicalEditorCore.

// End of the file
