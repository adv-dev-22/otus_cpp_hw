#include "fs_lazy_files_holder.h"
#include <iostream>

FsLazyFilesHolder::FsLazyFilesHolder():
vec_lazy_files_()
{
}

void FsLazyFilesHolder::init(const std::vector<std::string> & fnames_vec,
                             const FsComparatorOptions & cmpr_options)
{
    vec_lazy_files_.clear();
    vec_lazy_files_.reserve(fnames_vec.size());

    for (const std::string & item : fnames_vec)
    {
        vec_lazy_files_.emplace_back(std::make_unique<FsLazyFile>(item, cmpr_options));
    }
}

bool FsLazyFilesHolder::are_equal(const size_t i, const size_t j)
{
    const FsLazyFile & ref_lazy_file_i = *vec_lazy_files_.at(i);
    const FsLazyFile & ref_lazy_file_j = *vec_lazy_files_.at(j);

    return ref_lazy_file_i == ref_lazy_file_j;
}

// End of the file
