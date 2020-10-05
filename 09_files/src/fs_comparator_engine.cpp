#include "fs_comparator_engine.h"
#include "fs_lazy_files_holder.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <numeric>

FsComparatorEngine::FsComparatorEngine():
lli_duplicates_()
{

}

void FsComparatorEngine::find_duplicates(const std::vector<std::string> & fnames_vec,
                                         const FsComparatorOptions & cmpr_options)
{
    std::vector<std::string> test{"aa", "cc", "aa", "bb",
                                  "aa", "bb", "cc", "aa",
                                  "bb", "aa", "cc", "aa",
                                  "bb", "aa", "cc", "bb"};

    // Build list of repeated files.
    make_equiv_list_(test, cmpr_options);

//    // Fill up llist with duplicates.
//    lls_duplicates_.clear();
//    if (pairs_lst.empty()) return;

    for (auto & item : lli_duplicates_)
    {
        for (auto i : item)
        {
            std::cout << test.at(i) << " ";
        }
        std::cout << std::endl;
    }
}

void FsComparatorEngine::make_equiv_list_(const std::vector<std::string> & fnames_vec,
                                          const FsComparatorOptions & cmpr_options)
{
    // The aim of this subroutine is to initialize this list
    // lli_duplicates_ which holds duplicates.
    lli_duplicates_.clear();

    // Holder of Block file proxies. BlockFileProxy contain hashed blocks
    // (in case those blocks have been required).
    FsLazyFilesHolder bpf_holder;
    bpf_holder.init(fnames_vec, cmpr_options);

    std::vector<size_t> fnames_idx(fnames_vec.size());
    std::iota(fnames_idx.begin(), fnames_idx.end(), 0);

    // Comapre files content for equality.
    struct ComparatorIdx final
    {
        FsLazyFilesHolder * ptr_bfs_holder;
        std::vector<size_t>::iterator itr_1;

        bool operator()(const size_t index_to_compare) {
                return ptr_bfs_holder->are_equal(*itr_1, index_to_compare);
        }
    };

    ComparatorIdx cmpr;
    cmpr.ptr_bfs_holder = &bpf_holder;
    cmpr.itr_1 = fnames_idx.begin();

    // Pass by the elements. For each element search for repeated ones.
    // put them in one (the same) list.
    // Each list corresponds to a certain similar content.
    std::vector<size_t>::iterator itr_2 = cmpr.itr_1 + 1;
    bool new_chain = true;
    while (cmpr.itr_1 + 1 != fnames_idx.end()) {

        auto prev_itr_2 = itr_2;
        itr_2 = find_if(itr_2, fnames_idx.end(), cmpr);

        // Similar found
        if (fnames_idx.end() != itr_2)
        {
            // Insert very first item opening new chain of similar elements
            if (new_chain)
            {
                lli_duplicates_.emplace_back(std::list<size_t>());
                lli_duplicates_.back().emplace_back(*cmpr.itr_1);
                new_chain = false;
            }
            // Push back second and others similar elements
            lli_duplicates_.back().emplace_back(*itr_2);
            std::swap(*(++cmpr.itr_1), *itr_2);

            // New found element is right after the reference one: ???a|a????
            // In this case the iterator was not incremented,
            // so it needs to be propagated manually.
            if (prev_itr_2 == itr_2) ++itr_2;
        }
        else {
            // For a given reference there are no any coincidence.
            itr_2 = ++cmpr.itr_1 + 1;
            new_chain = true;
        }
    }
}

const std::list<std::list<size_t>> & FsComparatorEngine::lli_duplicates() const noexcept
{
    return lli_duplicates_;
}

// End of the file
