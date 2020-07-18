#ifndef _EDITOR_CORE_H_
#define _EDITOR_CORE_H_

#include "document.h"
#include <memory>

namespace GraphicalEditorCore {

class DocumentParametersInterface;

class EditorCore {
public:
    EditorCore();
    virtual ~EditorCore();

    Document & create_document(std::shared_ptr<DocumentParametersInterface> shp_dpi);

    void save(const std::string & file);

//    void load(const std::string & file);

    // May be added in future versions:  iterators
    // TODO: next_document();

private:
    std::unique_ptr<Document> up_document_;
    // TODO: May be changed to container (map) of documents have been already created

private:
    EditorCore(const EditorCore & ) = delete;
    EditorCore(EditorCore && )      = delete;
    EditorCore & operator = (const EditorCore & ) = delete;
    EditorCore & operator = (EditorCore && )      = delete;
};

} // End of namespace GraphicalEditorCore.

#endif  // _EDITOR_CORE_H_

// End of the file
