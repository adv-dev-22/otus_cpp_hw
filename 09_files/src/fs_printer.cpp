#include "fs_printer.h"
#include <iostream>

FsPrinter::FsPrinter()
{

}

void FsPrinter::put_out(const std::list<std::list<std::string>> & ll_duplicates)
{
    if (ll_duplicates.empty())
    {
        std::cout << "no duplicates were found.." << std::endl;
        return;
    }

    for (const auto & lst : ll_duplicates)
    {
        for (const auto & item : lst)
        {
            std::cout << item << std::endl;
        }
        std::cout << std::endl;
    }
}

// End of the file
