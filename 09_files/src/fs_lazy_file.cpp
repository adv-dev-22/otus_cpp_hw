#include "fs_lazy_file.h"


//size_t FsLazyFile::block_size_ = 0;


FsLazyFile::FsLazyFile(const std::string & fname,
                       const FsComparatorOptions & cmpr_options):
fname_(fname)//,
//blocks_number_(0),
//hashed_blocks_(""),
//block_position_(0)
{
}

//void FsLazyFile::set_block_size(const size_t block_size)
//{
//    // It is static
//    FsLazyFile::block_size_ = block_size;
//}

//const std::string & FsLazyFile::fname() const noexcept
//{
//    return fname_;
//}

//size_t FsLazyFile::blocks_number() const noexcept
//{
//    return blocks_number_;
//}

//char FsLazyFile::block(const size_t index) const
//{
//    //


//    return 'x';
//}



bool operator == (const FsLazyFile & lhs_01, const FsLazyFile & rhs_02)
{
//    // Lazy size estimation. Secnond and further attempts use proxy.
//    if (lhs_01.blocks_number() != rhs_02.blocks_number()) return false;

//    //for (size_t k = 0; k < lhs_01.blocks_size(); ++k)
//    {
//        // Block provides lazy reading from HD.
//        //if (lhs_01.block(k) != rhs_02.block(k)) return false;
//    }

    return true;
}

// End of the file
