#ifndef _FS_LAZY_FILE_H_
#define _FS_LAZY_FILE_H_

#include "fs_comparator_options.h"
#include "fs_blocks_number_proxy.h"
#include "fs_file_block_proxy.h"
#include <string>
#include <memory>
#include <vector>

class FsLazyFile final
{
public:
    FsLazyFile(const std::string & full_name,
               const FsComparatorOptions & cmpr_options);

    ~FsLazyFile() = default;

    const std::string & fname() const noexcept;

    size_t blocks_number() const noexcept;

    const std::string & block_hash(const size_t index) const;

private:
    std::unique_ptr<FsBlocksNumberProxy> up_blocks_number_proxy_;

    std::vector<std::unique_ptr<FsFileBlockProxy>> vec_fblocks_proxy_;

private:
    FsLazyFile(const FsLazyFile & ) = delete;
    FsLazyFile(FsLazyFile && ) = delete;

    FsLazyFile & operator= (const FsLazyFile & ) = delete;
    FsLazyFile & operator= (FsLazyFile && ) = delete;
};


bool operator == (const FsLazyFile & lhs_01, const FsLazyFile & rhs_02);

#endif // _FS_LAZY_FILE_H_

// End of the file
