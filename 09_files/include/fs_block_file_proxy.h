#ifndef _FS_BLOCK_FILE_PROXY_H_
#define _FS_BLOCK_FILE_PROXY_H_

#include <string>

class FsBlockFileProxy final
{
public:
    FsBlockFileProxy(const std::string & full_name); //+ size of block
    ~FsBlockFileProxy() = default;

    static void set_block_size(const size_t block_size);

    const std::string & fname() const noexcept;

    size_t blocks_number() const noexcept;
    char block(const size_t index) const;

private:
    static size_t block_size_;

    std::string fname_;
    size_t blocks_number_;

    mutable std::string hashed_blocks_;
    mutable size_t block_position_;
};

bool operator == (const FsBlockFileProxy & lhs_01, const FsBlockFileProxy & rhs_02);

#endif // _FS_BLOCK_FILE_PROXY_H_

// End of the file
