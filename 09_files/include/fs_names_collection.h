#ifndef _FS_NAMES_COLLECTION_H_
#define _FS_NAMES_COLLECTION_H_

#include "fs_comparator_options.h"
#include <boost/filesystem.hpp>
#include <list>
#include <string>
#include <vector>

namespace bfs = boost::filesystem;

class IFsNamesCollection
{
public:
    IFsNamesCollection();
    virtual ~IFsNamesCollection() = default;

    const std::vector<std::string> & fnames_vec() const noexcept;

    virtual void extract_file_names(const FsComparatorOptions & ) = 0;

protected:
    /*! Internal temporary variable used while collecting files. */
    std::list<std::string> fnames_list_;

    /*! Once list is ready */
    std::vector<std::string> fnames_vec_;

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
