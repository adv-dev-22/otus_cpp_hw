#include "fs_comparator_options.h"
#include <boost/program_options.hpp>

namespace boost_po = boost::program_options;

FsComparatorOptions::FsComparatorOptions():
scan_dirs_(),
excl_dirs_(),
block_size_(0)
{

}

void FsComparatorOptions::parse(int argc, char * argv [])
{
    boost_po::options_description descr("FsOptions");



}

const std::list<std::string> & FsComparatorOptions::scan_dirs() const
{
    return scan_dirs_;
}

const std::list<std::string> & FsComparatorOptions::excl_dirs() const
{
    return excl_dirs_;
}

size_t FsComparatorOptions::block_size() const noexcept
{
    return block_size_;
}


// End of the file
