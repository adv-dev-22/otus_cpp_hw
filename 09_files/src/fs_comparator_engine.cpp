#include "fs_comparator_engine.h"
#include "fs_block_files_holder.h"
#include <iostream>
#include <limits>

FsComparatorEngine::FsComparatorEngine():
lls_duplicates_()
{

}

void FsComparatorEngine::find_duplicates(const std::vector<std::string> & fnames_vec)
{
    // Holder of Block file proxies. BlockFileProxy contain hashed blocks
    // (in case those blocks have been required).
    FsBlockFilesHolder bpf_holder;
    bpf_holder.init(fnames_vec);

    // Temporary list of equal pairs
    std::list<std::pair<size_t, size_t>> pairs_lst;

    for (size_t i = 0; i + 1 < fnames_vec.size(); ++i)
    {
        for (size_t j = i + 1; j < fnames_vec.size(); ++j)
        {
            if (bpf_holder.are_equal(i, j)) pairs_lst.emplace_back(i, j);
        }
    }

    // Fill up llist with duplicates.
    lls_duplicates_.clear();
    if (pairs_lst.empty()) return;

    size_t i0_prev = std::numeric_limits<size_t>::max();
    for (auto item : pairs_lst)
    {
        if (i0_prev != item.first)
        {
            i0_prev = item.first;

            lls_duplicates_.emplace_back(std::list<std::string>());
            lls_duplicates_.back().emplace_back(fnames_vec.at(item.first));

            //std::cout << "---------------" << std::endl;
        }
        lls_duplicates_.back().emplace_back(fnames_vec.at(item.second));

        //std::cout << item.first << " " << item.second << std::endl;
    }
}

const std::list<std::list<std::string>> & FsComparatorEngine::ll_duplicates() const noexcept
{
    return lls_duplicates_;
}

// End of the file


// It is definitely not empty. Insert first element (a) of first (a,b) pair.
//    lls_duplicates_.emplace_back(std::list<std::string>);
//    lls_duplicates_.front().emplace_back(fnames_vec.at(pairs_lst.front().first));

