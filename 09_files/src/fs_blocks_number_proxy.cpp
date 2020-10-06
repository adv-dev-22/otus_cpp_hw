#include "fs_blocks_number_proxy.h"
#include <boost/filesystem.hpp>

namespace bfs = boost::filesystem;

FsBlocksNumberProxy::FsBlocksNumberProxy(const std::string & full_name,
                                         const FsComparatorOptions & cmpr_options):
FsBaseFileProxy(full_name, cmpr_options),
blocks_number_(0)
{
}

size_t FsBlocksNumberProxy::get() const
{
    if (!this->is_initialized_)
    {
        // Evaluate blocks number
        const double bytes_file_size  = bfs::file_size(this->ref_fname_);
        const double bytes_block_size = ref_cmpr_optns_.block_size();

        blocks_number_ = static_cast<size_t>(std::ceil(bytes_file_size / bytes_block_size));
        this->is_initialized_ = true;
    }

    return blocks_number_;
}

// End of the file
