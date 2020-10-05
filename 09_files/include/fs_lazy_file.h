#ifndef _FS_LAZY_FILE_H_
#define _FS_LAZY_FILE_H_

#include "fs_comparator_options.h"
#include <string>

class FsLazyFile final
{
public:
    FsLazyFile(const std::string & full_name,
               const FsComparatorOptions & cmpr_options);

    ~FsLazyFile() = default;

//    static void set_block_size(const size_t block_size);

    const std::string & fname() const noexcept;

    size_t blocks_number() const noexcept;
    const std::string & block(const size_t index) const;

private:
//    static size_t block_size_;

    std::string fname_;
//    size_t blocks_number_;

//    mutable std::string hashed_blocks_;
//    mutable size_t block_position_;
};

bool operator == (const FsLazyFile & lhs_01, const FsLazyFile & rhs_02);

#endif // _FS_LAZY_FILE_H_

// End of the file
