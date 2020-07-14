#ifndef _DOCUMENT_PARAMETERS_H_
#define _DOCUMENT_PARAMETERS_H_

#include "color_engine.h"
#include <cstddef>
#include <memory>

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
    virtual ColorEngineBase & colorEngine() const = 0;

    virtual void  setColorEngine(ColorEngineBase * const ceb_ptr) = 0;

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
    virtual ColorEngineBase & colorEngine() const;

    virtual void setColorEngine(ColorEngineBase * const ceb_ptr);

    // ..

private:
    size_t width_;
    size_t height_;
    std::unique_ptr<ColorEngineBase> uptr_color_engine_;

    // ..
};

}

#endif  // _DOCUMENT_PARAMETERS_H_

// End of the file
