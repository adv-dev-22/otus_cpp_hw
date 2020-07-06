#ifndef _DOCUMENT_PARAMETERS_H_
#define _DOCUMENT_PARAMETERS_H_

#include <cstddef>

namespace GraphicalEditorCore {

class DocumentParametersInterface {
public:
    DocumentParametersInterface() = default;

    DocumentParametersInterface(const DocumentParametersInterface & ) = default;
    DocumentParametersInterface(DocumentParametersInterface && ) = default;

    DocumentParametersInterface & operator = (const DocumentParametersInterface & ) = default;
    DocumentParametersInterface & operator = (DocumentParametersInterface && ) = default;

    virtual ~DocumentParametersInterface() = default;

    virtual size_t width()  const = 0;
    virtual size_t height() const = 0;
    virtual size_t colorDepth() const = 0;

    // ..

private:
};

class DocumentParameters : public DocumentParametersInterface {
public:
    DocumentParameters();
    DocumentParameters(const DocumentParameters & );
    DocumentParameters(DocumentParameters && );

    DocumentParameters & operator = (const DocumentParameters & );
    DocumentParameters & operator = (DocumentParameters && );

    virtual ~DocumentParameters();

    virtual size_t width()  const;
    virtual size_t height() const;
    virtual size_t colorDepth() const;

    // ..

private:
    size_t width_;
    size_t height_;
    size_t color_depth_;

    // ..
};

}

#endif  // _DOCUMENT_PARAMETERS_H_

// End of the file
