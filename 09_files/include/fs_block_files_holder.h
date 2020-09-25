#ifndef _FS_BLOCK_FILES_HOLDER_H_
#define _FS_BLOCK_FILES_HOLDER_H_

#include "fs_block_file_proxy.h"
#include <vector>
#include <string>
#include <map>
#include <memory>

class FsBlockFilesHolder
{
public:
    FsBlockFilesHolder();
    ~FsBlockFilesHolder() = default;

    /*! Initialize map with all keys and BlockFileProxy (which are empty) at start. */
    void init(const std::vector<std::string> & fnames_vec);

    /*! Apply optimal comparision by blocks.
     *  Read necessary data from disk in case next unreaded block is needed.
     */
    bool are_equal(const size_t i, const size_t j);

private:
    std::vector<std::unique_ptr<FsBlockFileProxy>> vec_bpfiles_;

    std::vector<std::string> debug_vec_;
};

#endif // End of the file

// End of the file
