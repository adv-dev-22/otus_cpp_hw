#include "fs_printer.h"
#include <iostream>

FsPrinter::FsPrinter()
{

}

void FsPrinter::put_out(const std::list<std::list<size_t>> & lli_duplicates)
{
    if (lli_duplicates.empty())
    {
        std::cout << "no duplicates were found.." << std::endl;
        return;
    }

    for (const auto & lst : lli_duplicates)
    {
        for (const auto & item : lst)
        {
            std::cout << item << std::endl;
        }
        std::cout << std::endl;
    }
}

// End of the file
