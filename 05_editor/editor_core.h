#ifndef _EDITOR_CORE_H_
#define _EDITOR_CORE_H_

namespace GraphicalEditorCore {

class EditorCore {
public:
    EditorCore();
    virtual ~EditorCore();

    void create_document(/*Parameters .. */);

private:
    // map of already created documents
    // ..


private:
    EditorCore(const EditorCore & ) = delete;
    EditorCore(EditorCore && )      = delete;
    EditorCore & operator = (const EditorCore & ) = delete;
    EditorCore & operator = (EditorCore && )      = delete;
};

} // End of namespace GraphicalEditorCore.

#endif  // _EDITOR_CORE_H_

// End of the file
