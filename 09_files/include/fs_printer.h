#ifndef _FS_PRINTER_H_
#define _FS_PRINTER_H_

#include <list>
#include <string>
#include <vector>

class FsPrinter final
{
public:
    FsPrinter();
    ~FsPrinter() = default;

    void put_out(const std::vector<std::string> & fnames,
                 const std::list<std::list<size_t>> & lli_duplicates);
};

#endif // _FS_PRINTER_H_

// End of the file
