#ifndef _FS_LAZY_FILES_HOLDER_H_
#define _FS_LAZY_FILES_HOLDER_H_

#include "fs_lazy_file.h"
#include "fs_comparator_options.h"
#include <vector>
#include <string>
#include <map>
#include <memory>

class FsLazyFilesHolder
{
public:
    FsLazyFilesHolder();
    ~FsLazyFilesHolder() = default;

    /*! Initialize map with all keys and BlockFileProxy (which are empty) at start. */
    void init(const std::vector<std::string> & fnames_vec,
              const FsComparatorOptions & cmpr_options);

    /*! Apply optimal comparision by blocks.
     *  Read necessary data from disk in case next unreaded block is needed.
     */
    bool are_equal(const size_t i, const size_t j);

private:
    std::vector<std::unique_ptr<FsLazyFile>> vec_lazy_files_;

private:
    FsLazyFilesHolder(const FsLazyFilesHolder & ) = delete;
    FsLazyFilesHolder(FsLazyFilesHolder && ) = delete;

    FsLazyFilesHolder & operator= (const FsLazyFilesHolder & ) = delete;
    FsLazyFilesHolder & operator= (FsLazyFilesHolder && ) = delete;
};

#endif // _FS_LAZY_FILES_HOLDER_H_

// End of the file
