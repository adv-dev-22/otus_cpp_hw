#ifndef _DOCUMENT_WRITER_H_
#define _DOCUMENT_WRITER_H_

#include <string>
#include <fstream>

namespace GraphicalEditorCore {

class DocumentWriterBase {
public:
    DocumentWriterBase();
    virtual ~DocumentWriterBase();

    virtual void set_storage_name(const std::string st_name);

    virtual void prepare() = 0;
    virtual void close() = 0;

    virtual void append(const std::string & ) = 0;

protected:
    std::string storage_name_;

private:
    DocumentWriterBase(const DocumentWriterBase & ) = delete;
    DocumentWriterBase(DocumentWriterBase && )      = delete;
    DocumentWriterBase & operator= (const DocumentWriterBase & ) = delete;
    DocumentWriterBase & operator= (DocumentWriterBase && )      = delete;
};


class DocumentWriterText : public DocumentWriterBase {
public:
    DocumentWriterText();
    virtual ~DocumentWriterText();

    virtual void prepare() override;
    virtual void close() override;

    virtual void append(const std::string & ) override;

private:
    std::ofstream ofs_;

private:
    DocumentWriterText(const DocumentWriterText & ) = delete;
    DocumentWriterText(DocumentWriterText && )      = delete;
    DocumentWriterText & operator= (const DocumentWriterText & ) = delete;
    DocumentWriterText & operator= (DocumentWriterText && )      = delete;
};

class DocumentWriterBinary : public DocumentWriterBase {
public:

private:

};


class DocumentWriterNetworkDb : public DocumentWriterBase {
};


} // End of namespace GraphicalEditorCore

#endif // _DOCUMENT_WRITER_H_

// End of the file
