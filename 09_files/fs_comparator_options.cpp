#include "fs_comparator_options.h"
#include "fs_option_labels.h"
#include <boost/program_options.hpp>
#include <string>
#include <iostream>

namespace bpo = boost::program_options;

namespace std
{
std::ostream & operator<< (std::ostream & os, const std::vector<std::string> &vec)
{
    for (auto item : vec) {os << item << " ";}
    return os;
}
}

FsComparatorOptions::FsComparatorOptions():
scan_dirs_(),
skip_dirs_(),
level_(ScanLevel::Undefined),
min_file_size_(1),
masks_(),
block_size_(0),
hash_alg_(HashingAlgorithm::Undefined)
{
}

void FsComparatorOptions::parse(int argc, char * argv [])
{
    // Options description
    bpo::options_description descr("FsOptions");

    descr.add_options()(OptionLabels::help().c_str(), "Help message");

    descr.add_options()(OptionLabels::scandirs().c_str(),
                        bpo::value<std::vector<std::string>>()->multitoken()
                        ->default_value(std::vector<std::string>{"./"}),
                        "Setup directories for scan");

    descr.add_options()(OptionLabels::skipdirs().c_str(),
                        bpo::value<std::vector<std::string>>()->multitoken()
                        ->default_value(std::vector<std::string>{}),
                        "Exclude directories from scan");

    descr.add_options()(OptionLabels::level().c_str(),
                        bpo::value<size_t>()->default_value(1),
                        "Scan level: 0 - no recursive subfolder, 1 - all subfolders");

    descr.add_options()(OptionLabels::minfilesz().c_str(),
                        bpo::value<size_t>()->default_value(1),
                        "Minimal file size in bytes");

    descr.add_options()(OptionLabels::masks().c_str(),
                        bpo::value<std::vector<std::string>>()->multitoken()
                        ->default_value(std::vector<std::string>{}),
                        "File masks");

    descr.add_options()(OptionLabels::blocksize().c_str(),
                        bpo::value<size_t>()->default_value(4),
                        "Size of one block in bytes");

    descr.add_options()(OptionLabels::hashalg().c_str(),
                        bpo::value<std::string>()->default_value("md5"),
                        "Hashing algorithm");

    // Variable map
    bpo::variables_map vars_map;

    // Parsing routine
    bpo::store(bpo::parse_command_line(argc, argv, descr), vars_map);

    if (vars_map.count("help")) std::cout << descr << std::endl;

    // Now pass boost program options to internal data (options).
    // ..

//    std::vector<std::string> scan_dirs_;

//    std::vector<std::string> skip_dirs_;

//    ScanLevel level_;

    min_file_size_ = vars_map[OptionLabels::minfilesz()].as<size_t>();

//    std::vector<std::string> masks_;

//    size_t block_size_;

//    HashingAlgorithm hash_alg_;


}

const std::vector<std::string> & FsComparatorOptions::scan_dirs() const
{
    return scan_dirs_;
}

const std::vector<std::string> & FsComparatorOptions::skip_dirs() const
{
    return skip_dirs_;
}

ScanLevel FsComparatorOptions::level() const noexcept
{
    return level_;
}

size_t FsComparatorOptions::min_file_size() const noexcept
{
    return min_file_size_;
}

const std::vector<std::string> & FsComparatorOptions::masks() const
{
    return masks_;
}

size_t FsComparatorOptions::block_size() const noexcept
{
    return block_size_;
}

HashingAlgorithm FsComparatorOptions::hash_alg() const noexcept
{
    return hash_alg_;
}

// End of the file
