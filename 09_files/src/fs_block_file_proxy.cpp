#include "fs_block_file_proxy.h"


size_t FsBlockFileProxy::block_size_ = 0;


FsBlockFileProxy::FsBlockFileProxy(const std::string & fname):
fname_(fname),
blocks_number_(0),
hashed_blocks_(""),
block_position_(0)
{
}

void FsBlockFileProxy::set_block_size(const size_t block_size)
{
    // It is static
    FsBlockFileProxy::block_size_ = block_size;
}

const std::string & FsBlockFileProxy::fname() const noexcept
{
    return fname_;
}

size_t FsBlockFileProxy::blocks_number() const noexcept
{
    return blocks_number_;
}

char FsBlockFileProxy::block(const size_t index) const
{
    //


    return 'x';
}



bool operator == (const FsBlockFileProxy & lhs_01, const FsBlockFileProxy & rhs_02)
{
    if (lhs_01.blocks_number() != rhs_02.blocks_number()) return false;

    //for (size_t k = 0; k < lhs_01.blocks_size(); ++k)
    {
        // Block provides lazy reading from HD.
        //if (lhs_01.block(k) != rhs_02.block(k)) return false;
    }

    return true;
}

// End of the file
