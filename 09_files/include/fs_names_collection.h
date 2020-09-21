#ifndef _FS_NAMES_COLLECTION_H_
#define _FS_NAMES_COLLECTION_H_

#include "fs_comparator_options.h"
#include <boost/filesystem.hpp>
#include <list>
#include <string>

namespace bfs = boost::filesystem;

class IFsNamesCollection
{
public:
    IFsNamesCollection();
    virtual ~IFsNamesCollection() = default;

    const std::list<std::string> & fnames_list() const noexcept;

    virtual void extract_file_names(const FsComparatorOptions & ) = 0;

protected:
    std::list<std::string> fnames_list_;

    void collect_files_for_path_(bfs::path pth, const FsComparatorOptions & rhs);
};


class FsNamesCollectionStd final : public IFsNamesCollection
{
public:
    FsNamesCollectionStd();
    virtual ~FsNamesCollectionStd() = default;

    virtual void extract_file_names(const FsComparatorOptions & );
};


class FsNamesCollectionBoost final : public IFsNamesCollection
{
public:
    FsNamesCollectionBoost();
    virtual ~FsNamesCollectionBoost() = default;

    virtual void extract_file_names(const FsComparatorOptions & );
};

#endif  // _FS_NAMES_COLLECTION_H_

// End of the file
