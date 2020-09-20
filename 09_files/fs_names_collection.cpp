#include "fs_names_collection.h"
#include <iostream>

IFsNamesCollection::IFsNamesCollection():
fnames_list_()
{
}

const std::list<std::string> & IFsNamesCollection::fnames_list() const noexcept
{
    return fnames_list_;
}


FsNamesCollectionStd::FsNamesCollectionStd():
IFsNamesCollection()
{
}

void FsNamesCollectionStd::extract_file_names(const FsComparatorOptions & rhs)
{
    std::cout << "Empty initializtion std" << std::endl;
}


FsNamesCollectionBoost::FsNamesCollectionBoost():
IFsNamesCollection()
{
}

void FsNamesCollectionBoost::extract_file_names(const FsComparatorOptions & rhs)
{
    std::cout << "Empty initializtion Boost" << std::endl;
}

// End of the file
