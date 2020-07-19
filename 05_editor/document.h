#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include "document_parameters.h"
#include "shapes_2d.h"
#include <memory>
#include <map>
#include <fstream>

namespace GraphicalEditorCore {

class DocumentWriterBase;

template <typename T = double>
class Document {
public:
    Document(std::shared_ptr<DocumentParametersInterface> shp_dpi);
    virtual ~Document();

    void add_shape(std::unique_ptr<BaseShape2D<T>> && shape_2d);
    void remove_shape(const size_t id);

    void append(DocumentWriterBase & );

private:
    std::weak_ptr<DocumentParametersInterface> wp_doc_params_;
    Shape2DContainer<T> shapes_2d_;

private:
    Document(const Document & ) = delete;
    Document(Document && )      = delete;
    Document & operator = (const Document & ) = delete;
    Document & operator = (Document && )      = delete;
};

} // End of namespace

#endif  // _DOCUMENT_H_

// End of the file

