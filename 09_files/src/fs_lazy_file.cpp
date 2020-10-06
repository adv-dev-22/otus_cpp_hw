#include "fs_lazy_file.h"
#include <iostream>

FsLazyFile::FsLazyFile(const std::string & fname,
                       const FsComparatorOptions & cmpr_options):
up_blocks_number_proxy_(std::make_unique<FsBlocksNumberProxy>(fname, cmpr_options)),
vec_fblocks_proxy_(0)
{
    vec_fblocks_proxy_.resize(up_blocks_number_proxy_->get());

    for (size_t k = 0; k < up_blocks_number_proxy_->get(); ++k)
    {
        vec_fblocks_proxy_[k] = std::make_unique<FsFileBlockProxy>(fname, cmpr_options, k);
    }
}

size_t FsLazyFile::blocks_number() const noexcept
{
    return up_blocks_number_proxy_->get();
}

const std::string & FsLazyFile::block_hash(const size_t index) const
{
    const FsFileBlockProxy & ref_file_block = *vec_fblocks_proxy_.at(index);
    return ref_file_block.get_hash();
}

bool operator == (const FsLazyFile & lhs_01, const FsLazyFile & rhs_02)
{
    // Lazy size estimation. Second and further attempts use proxy.
    if (lhs_01.blocks_number() != rhs_02.blocks_number()) return false;

    for (size_t k = 0; k < lhs_01.blocks_number(); ++k)
    {
        // Block provides lazy reading from HD. Second and further attempts use proxy.
        if (lhs_01.block_hash(k) != rhs_02.block_hash(k)) return false;
    }

    // Files are similar by hash criterion.
    return true;
}

// End of the file
