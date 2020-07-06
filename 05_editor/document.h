#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

namespace GraphicalEditorCore {

class Document {
public:
    Document();
    virtual ~Document();



private:

    Document(const Document & ) = delete;
    Document(Document && )      = delete;
    Document & operator = (const Document & ) = delete;
    Document & operator = (Document && )      = delete;
};

} // End of namespace

#endif  // _DOCUMENT_H_

// End of the file

