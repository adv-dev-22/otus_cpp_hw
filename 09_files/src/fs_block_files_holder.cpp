#include "fs_block_files_holder.h"
#include <iostream>

FsBlockFilesHolder::FsBlockFilesHolder():
vec_bpfiles_()
{
}

void FsBlockFilesHolder::init(const std::vector<std::string> & fnames_vec)
{
    vec_bpfiles_.clear();
    vec_bpfiles_.resize(fnames_vec.size());

    for (const std::string & item : fnames_vec)
    {
        auto up_file_proxy = std::make_unique<FsBlockFileProxy>(item);
        vec_bpfiles_.emplace_back(std::move(up_file_proxy));
    }

    debug_vec_ = fnames_vec;
}

bool FsBlockFilesHolder::are_equal(const size_t i, const size_t j)
{
    // TODO: ..
    // size_1 == size_2


    // i -> file_i
    // j -> file_j

    // DEBUG
    return debug_vec_[i] == debug_vec_[j];



    return true;
}


// End of the file
