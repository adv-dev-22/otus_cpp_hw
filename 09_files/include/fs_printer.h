#ifndef _FS_PRINTER_H_
#define _FS_PRINTER_H_

#include <list>
#include <string>

class FsPrinter final
{
public:
    FsPrinter();
    ~FsPrinter() = default;

    void put_out(const std::list<std::list<std::string>> & ll_duplicates);

private:

};

#endif // _FS_PRINTER_H_

// End of the file
