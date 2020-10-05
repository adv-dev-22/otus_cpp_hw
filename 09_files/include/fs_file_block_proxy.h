#ifndef _FS_FILE_BLOCK_PROXY_H_
#define _FS_FILE_BLOCK_PROXY_H_

#include "fs_base_file_proxy.h"

class FsFileBlockProxy : public FsBaseFileProxy
{
public:
    FsFileBlockProxy(const std::string & full_name,
                     const FsComparatorOptions & cmpr_options,
                     const size_t index_offset);

    ~FsFileBlockProxy() = default;

    char get_hash() const;

private:
    /*! Offset in whole file. */
    const size_t idx_offset_;

    /*! Hashed value of several contigious blocks. */
    mutable char hash_;
};

#endif // _FS_FILE_BLOCK_PROXY_H_

// End of the file
