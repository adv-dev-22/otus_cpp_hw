#ifndef _FS_FILE_BLOCK_PROXY_H_
#define _FS_FILE_BLOCK_PROXY_H_

#include "fs_base_file_proxy.h"
#include "fs_hash_algorithm.h"
#include <string>
#include <memory>

class FsFileBlockProxy : public FsBaseFileProxy
{
public:
    FsFileBlockProxy(const std::string & full_name,
                     const FsComparatorOptions & cmpr_options,
                     const size_t index_offset);

    ~FsFileBlockProxy() = default;

    const std::string & get_hash() const;

private:
    /*! Offset in whole file. */
    const size_t idx_offset_;

    /*! Hashed value of several contigious blocks. */
    mutable std::string hash_;

    /*! MD5, CRC32 etc. Currently only MD5 implemented. */
    std::unique_ptr<HashAlgorithmBase> up_hash_alg_;

    void setup_hashing_algorithm_();
};

#endif // _FS_FILE_BLOCK_PROXY_H_

// End of the file
