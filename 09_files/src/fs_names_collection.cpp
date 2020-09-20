#include "fs_names_collection.h"
#include <boost/filesystem.hpp>
#include <iostream>

namespace bfs = boost::filesystem;

IFsNamesCollection::IFsNamesCollection():
fnames_list_()
{
}

const std::list<std::string> & IFsNamesCollection::fnames_list() const noexcept
{
    return fnames_list_;
}

template <typename dir_iterator>
void IFsNamesCollection::collect_file_names_(dir_iterator ditr)
{
    // TODO
    // 1. file size
    // 2. regexp
    // 3. !is dir excluded

    while (ditr != dir_iterator{})
    {
        std::cout << ditr->path().string() << std::endl;
        ++ditr;
    }
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
    const std::vector<std::string> & scandirs = rhs.scan_dirs();
    for (const auto & item : scandirs)
    {
        bfs::path pth(item);

        if (ScanLevel::ZeroLayer == rhs.level())
        {
            bfs::directory_iterator itr{pth};
            this->collect_file_names_(itr);
        }
        else if (ScanLevel::AllSubfolders == rhs.level())
        {
            bfs::recursive_directory_iterator itr{pth};
            this->collect_file_names_(itr);
        }
    }
}

// End of the file


//    bfs::path pth("./");
//    bfs::directory_iterator itr{pth};
//    bfs::recursive_directory_iterator itr{pth};

//    this->collect_file_names_(itr);

//    bfs::path pth("./");
//    bfs::directory_iterator itr{pth};
//    while (itr != bfs::directory_iterator{})
//    {
//        std::cout << itr->path().string() << std::endl;
//        ++itr;
//    }

//    bfs::recursive_directory_iterator ritr{pth};
//    while (ritr != bfs::recursive_directory_iterator{})
//    {
//        std::cout << ritr->path().string() << std::endl;
//        ++ritr;
//    }
