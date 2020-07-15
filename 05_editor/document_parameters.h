#ifndef _DOCUMENT_PARAMETERS_H_
#define _DOCUMENT_PARAMETERS_H_

#include "color_engine.h"
#include <cstddef>
#include <memory>

namespace GraphicalEditorCore {

class DocumentParametersInterface {
public:
    DocumentParametersInterface() = default;
    virtual ~DocumentParametersInterface() = default;

    virtual size_t width()  const = 0;
    virtual size_t height() const = 0;
    virtual ColorEngineBase & colorEngine() const = 0;

private:
    DocumentParametersInterface(const DocumentParametersInterface & ) = delete;
    DocumentParametersInterface(DocumentParametersInterface && ) = delete;
    DocumentParametersInterface & operator = (const DocumentParametersInterface & ) = delete;
    DocumentParametersInterface & operator = (DocumentParametersInterface && ) = delete;
};

template <typename T = ColorEngineUniform>
class DocumentParameters : public DocumentParametersInterface {
public:
    DocumentParameters();
    DocumentParameters(const DocumentParameters & );
    DocumentParameters(DocumentParameters && );

    DocumentParameters & operator = (const DocumentParameters & );
    DocumentParameters & operator = (DocumentParameters && );

    virtual ~DocumentParameters();

    virtual size_t width()    const override;
    virtual size_t height()   const override;
    virtual T & colorEngine() const override;

    void setWidth(const size_t w);
    void setHeight(const size_t h);
    void resetColorEngine(T * const ptr_clr_eng);

private:
    size_t width_;
    size_t height_;
    std::unique_ptr<T> uptr_color_engine_;

    // ..
};

}

#endif  // _DOCUMENT_PARAMETERS_H_

// End of the file



