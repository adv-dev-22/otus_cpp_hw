#include "fs_printer.h"
#include <iostream>

FsPrinter::FsPrinter()
{
}

void FsPrinter::put_out(const std::vector<std::string> & fnames,
                        const std::list<std::list<size_t>> & lli_duplicates)
{
    if (lli_duplicates.empty())
    {
        std::cout << "no duplicates were found.." << std::endl;
        return;
    }

    for (const auto & list_with_same_elems : lli_duplicates)
    {
        for (const auto & index : list_with_same_elems)
        {
            std::cout << fnames.at(index) << std::endl;
        }
        std::cout << std::endl;
    }
}

// End of the file
