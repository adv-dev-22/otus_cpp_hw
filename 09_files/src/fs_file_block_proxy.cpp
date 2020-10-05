#include "fs_file_block_proxy.h"
#include <fstream>


FsFileBlockProxy::FsFileBlockProxy(const std::string & full_name,
                                   const FsComparatorOptions & cmpr_options,
                                   const size_t index_offset):
FsBaseFileProxy(full_name, cmpr_options),
idx_offset_(index_offset),
hash_()
{
}

char FsFileBlockProxy::get_hash() const
{
    if (!this->is_initialized_)
    {
        std::vector<char> vec_buffer;

        //vec_buffer_.resize(ref_cmpr_optns_.block_size());

        std::ifstream fin(ref_fname_, std::ifstream::binary);
        //fin

        // ..

        this->is_initialized_ = true;
    }

    return hash_;
}

// End of the file
