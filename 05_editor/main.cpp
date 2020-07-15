#include "editor_core.h"
#include "document_parameters.h"
#include <memory>
#include <string>

using namespace GraphicalEditorCore;

int main(int argc, char * argv []) {

    auto up_editor_core = std::make_unique<EditorCore>();
    auto shp_doc_params = std::make_shared<DocumentParameters<ColorEngineUniform>>();

    shp_doc_params->setWidth(22000);
    auto & document = up_editor_core->create_document(shp_doc_params);

    // create triangle
    // create circle

    //document.add();

    const std::string filename("editor_validation.ed");
    up_editor_core->save(filename);

    // create yet another editor
    // load its data from file

    auto up_editor_restore = std::make_unique<EditorCore>();
    //up_editor_restore->load(filename);

    // .. get some data;

    return 0;
}

// End of the file

