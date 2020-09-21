#include "fs_names_collection.h"
#include <iostream>
#include <iomanip>


IFsNamesCollection::IFsNamesCollection():
fnames_list_()
{
}

const std::list<std::string> & IFsNamesCollection::fnames_list() const noexcept
{
    return fnames_list_;
}

bool is_dir_excluded(bfs::path pth, const FsComparatorOptions & opts)
{
    const std::set<std::string> & skipdirs_set = opts.skip_dirs();

    const auto itr = skipdirs_set.find(pth.string());

    if (itr != skipdirs_set.end()) return true;
    return false;
}

void IFsNamesCollection::collect_files_for_path_(bfs::path pth, const FsComparatorOptions & opts)
{
    bfs::directory_iterator ditr{pth};
    while (ditr != bfs::directory_iterator{})
    {
        if (bfs::is_directory(ditr->path()))
        {
            std::cout << "directory: " << ditr->path() << std::endl;
            if (opts.level() == ScanLevel::AllSubfolders)
            {
                if (!is_dir_excluded(ditr->path(), opts))
                {
                    collect_files_for_path_(ditr->path(), opts);
                }
            }
        }
        else if (bfs::is_regular_file(ditr->path()))
        {
            //std::cout << std::setw(10) << bfs::file_size(ditr->path());
            //std::cout << ditr->path().string() << std::endl;

            if (0)
            {
                //names_list_
            }
        }
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
        collect_files_for_path_(pth, rhs);
    }
}

// End of the file



////            bfs::directory_iterator itr{pth};

//while (ditr != dir_iterator{})
//{
//    if (bfs::is_regular_file(ditr->path()))
//    {
//        std::cout << std::setw(10) << bfs::file_size(ditr->path()/*.string().c_str()*/);
//        std::cout << "file " << ditr->path().string() << std::endl;
//    } else {
//        std::cout << "dir  " << ditr->path().string() << std::endl;
//    }
//    //names_list_
//    ++ditr;
//}



////        if (ScanLevel::ZeroLayer == rhs.level())
////        {
////            bfs::directory_iterator itr{pth};
////            this->collect_file_names_(itr);
////        }
////        else if (ScanLevel::AllSubfolders == rhs.level())
////        {
////            bfs::recursive_directory_iterator itr{pth};
////            this->collect_file_names_(itr);
////        }

//        if (bfs::is_regular_file(ditr->path()))
//        {
//            std::cout << std::setw(10) << bfs::file_size(ditr->path()/*.string().c_str()*/);
//            std::cout << "file " << ditr->path().string() << std::endl;
//        } else {
//            std::cout << "dir  " << ditr->path().string() << std::endl;
//        }


//template <typename dir_iterator>
//void IFsNamesCollection::collect_file_names_(dir_iterator ditr)
//{
//    // TODO
//    // 1. file size
//    // 2. regexp
//    // 3. !is dir excluded

//    while (ditr != dir_iterator{})
//    {
//        if (bfs::is_regular_file(ditr->path()))
//        {
//            std::cout << std::setw(10) << bfs::file_size(ditr->path()/*.string().c_str()*/);
//            std::cout << "file " << ditr->path().string() << std::endl;
//        } else {
//            std::cout << "dir  " << ditr->path().string() << std::endl;
//        }

//        //names_list_


//        ++ditr;
//    }
//}
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
