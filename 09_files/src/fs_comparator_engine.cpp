#include "fs_comparator_engine.h"
#include "fs_block_files_holder.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <numeric>

FsComparatorEngine::FsComparatorEngine():
lls_duplicates_()
{

}

void FsComparatorEngine::find_duplicates(const std::vector<std::string> & fnames_vec)
{
    std::vector<std::string> test{"aa", "cc", "aa", "bb",
                                  "aa", "bb", "cc", "aa",
                                  "bb", "aa", "cc", "aa",
                                  "bb", "aa", "cc", "bb"};

    // Temporary list of equal pairs
    auto equiv_lst = make_equiv_list_(test);

//    // Fill up llist with duplicates.
//    lls_duplicates_.clear();
//    if (pairs_lst.empty()) return;

    for (auto & item : equiv_lst)
    {
        for (auto i : item)
        {
            std::cout << test.at(i) << " ";
        }
        std::cout << std::endl;
    }

}

std::list<std::list<size_t>> FsComparatorEngine::make_equiv_list_(const std::vector<std::string> & fnames_vec)
{
    // Holds duplicates indexes.
    // The aim of this subroutine is to initialize this list.
    std::list<std::list<size_t>> equiv_lst;

    // Holder of Block file proxies. BlockFileProxy contain hashed blocks
    // (in case those blocks have been required).
    FsBlockFilesHolder bpf_holder;
    bpf_holder.init(fnames_vec);

    std::vector<size_t> fnames_idx(fnames_vec.size());
    std::iota(fnames_idx.begin(), fnames_idx.end(), 0);

    // Comapre files content for equality.
    struct ComparatorIdx final
    {
        FsBlockFilesHolder * ptr_bfs_holder;
        std::vector<size_t>::iterator itr_1;

        bool operator()(const size_t index_to_compare) {
                return ptr_bfs_holder->are_equal(*itr_1, index_to_compare);
        }
    };

    ComparatorIdx cmpr;
    cmpr.ptr_bfs_holder = &bpf_holder;
    cmpr.itr_1 = fnames_idx.begin();

    std::vector<size_t>::iterator itr_2 = cmpr.itr_1 + 1;
    bool new_chain = true;
    while (cmpr.itr_1 + 1 != fnames_idx.end()) {

        auto prev_itr_2 = itr_2;
        itr_2 = find_if(itr_2, fnames_idx.end(), cmpr);

        // Similar found
        if (fnames_idx.end() != itr_2)
        {
            if (new_chain)
            {
                equiv_lst.emplace_back(std::list<size_t>());
                equiv_lst.back().emplace_back(*cmpr.itr_1);
                new_chain = false;
            }
            equiv_lst.back().emplace_back(*itr_2);
            std::swap(*(++cmpr.itr_1), *itr_2);

            if (prev_itr_2 == itr_2) ++itr_2;
        }
        else {
            itr_2 = ++cmpr.itr_1 + 1;
            new_chain = true;
        }
    }

    return std::move(equiv_lst);
}

const std::list<std::list<std::string>> & FsComparatorEngine::ll_duplicates() const noexcept
{
    return lls_duplicates_;
}

// End of the file



//    std::vector<size_t>::iterator itr_1 = fnames_idx.begin();
//    std::vector<size_t>::iterator itr_2 = itr_1 + 1;

//    ComparatorIdx cmpr;
//    comparator_idx.ptr_bfs_holder = &bpf_holder;
//    comparator_idx.itr_1 = fnames_idx.begin();

//    std::vector<size_t>::iterator itr_2 = cmpr.itr_1 + 1;

//    while (itr_1 + 1 != fnames_idx.end()) {

//        itr_2 = find_if(itr_2, fnames_idx.end(), comparator_idx);
//        if (fnames_idx.end() != itr_2)
//        {
//            pairs_lst.emplace_back(*itr_1, *itr_2);
//            std::swap(*(++itr_1), *itr_2);
//            comparator_idx.itr_1 = itr_1;
//        }
//        else {
//            ++itr_1;
//            itr_2 = itr_1 + 1;
//        }
//    }
//}


// It is definitely not empty. Insert first element (a) of first (a,b) pair.
//    lls_duplicates_.emplace_back(std::list<std::string>);
//    lls_duplicates_.front().emplace_back(fnames_vec.at(pairs_lst.front().first));

//    for (size_t i = 0; i + 1 < fnames_vec.size(); ++i)
//    {
//        for (size_t j = i + 1; j < fnames_vec.size(); ++j)
//        {
//            if (bpf_holder.are_equal(i, j)) pairs_lst.emplace_back(i, j);
//        }
//    }


//    {
//        if (i0_prev != item.first)
//        {
//            i0_prev = item.first;

//            lls_duplicates_.emplace_back(std::list<std::string>());
//            lls_duplicates_.back().emplace_back(fnames_vec.at(item.first));

//            //std::cout << "---------------" << std::endl;
//        }
//        lls_duplicates_.back().emplace_back(fnames_vec.at(item.second));

//        std::cout << item.first << " " << item.second << std::endl;
//    }
