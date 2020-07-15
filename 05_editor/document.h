#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include "document_parameters.h"
#include <memory>

namespace GraphicalEditorCore {

class Document {
public:
    Document(std::shared_ptr<DocumentParametersInterface> shp_dpi);
    virtual ~Document();

    //void add_shape(BaseShape2D * const );
    //void remove_shape(const BaseShape2D * const );

private:
    std::weak_ptr<DocumentParametersInterface> wp_doc_params_;

    // TODO: std::map<BaseShape2D>

private:
    Document(const Document & ) = delete;
    Document(Document && )      = delete;
    Document & operator = (const Document & ) = delete;
    Document & operator = (Document && )      = delete;
};

} // End of namespace

#endif  // _DOCUMENT_H_

// End of the file

