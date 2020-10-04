#ifndef _FS_FILE_BLOCK_PROXY_H_
#define _FS_FILE_BLOCK_PROXY_H_

#include "fs_comparator_options.h"
#include <string>

class FsFileBlockProxy
{
public:
    FsFileBlockProxy(const std::string & full_name,
                     const FsComparatorOptions & cmpr_options,
                     const size_t index_offset);

    ~FsFileBlockProxy() = default;

    char get_hash() const;

private:
    /*! File name to get the size */
    const std::string & ref_fname_;

    /*! Provides block_size value. */
    const FsComparatorOptions & ref_cmpr_optns_;

    /*! Offset in whole file. */
    const size_t idx_offset_;

    std::vector<char> vec_buffer_;

    /*! Hashed value of several contigious blocks. */
    mutable char hash_;

    /*! Controls proxy workflow. */
    mutable bool is_initialized_;
};

#endif // _FS_FILE_BLOCK_PROXY_H_

// End of the file
