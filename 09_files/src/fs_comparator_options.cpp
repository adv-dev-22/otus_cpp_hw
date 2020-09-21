#include "fs_comparator_options.h"
#include "fs_option_labels.h"
#include <string>
#include <iostream>

namespace std
{
std::ostream & operator<< (std::ostream & os, const std::vector<std::string> & vec)
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
    bpo::options_description descr_opt = describe_options_();

    // Variable map
    bpo::variables_map vars_map;

    // Parsing routine
    bpo::store(bpo::parse_command_line(argc, argv, descr_opt), vars_map);

    // Print out helper multiline message.
    if (vars_map.count("help")) std::cout << descr_opt << std::endl;

    // Now pass boost program options to internal data (options).
    extract_option_values_(vars_map);
}

const std::vector<std::string> & FsComparatorOptions::scan_dirs() const noexcept
{
    return scan_dirs_;
}

const std::set<std::string> & FsComparatorOptions::skip_dirs() const noexcept
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

const std::vector<std::string> & FsComparatorOptions::masks() const noexcept
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

bpo::options_description FsComparatorOptions::describe_options_()
{
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
    return descr;
}

void FsComparatorOptions::extract_option_values_(const bpo::variables_map & vars_map)
{
    // Directories for scan.
    scan_dirs_ = vars_map[OptionLabels::scandirs()].as<std::vector<std::string>>();

    // Directories to skip
    const auto & skipdirs_vec = vars_map[OptionLabels::skipdirs()].as<std::vector<std::string>>();
    skip_dirs_.clear();
    skip_dirs_.insert(skipdirs_vec.begin(), skipdirs_vec.end());

    // Scan level
    level_ = ScanLevel::Undefined;
    const size_t opt_level = vars_map[OptionLabels::level()].as<size_t>();
    if (0 == opt_level)      level_ = ScanLevel::ZeroLayer;
    else if (1 == opt_level) level_ = ScanLevel::AllSubfolders;

    // Files lesser then min_file_size are ignored.
    min_file_size_ = vars_map[OptionLabels::minfilesz()].as<size_t>();

    // Regexpr pattern
    masks_ = vars_map[OptionLabels::masks()].as<std::vector<std::string>>();

//    size_t block_size_;

//    HashingAlgorithm hash_alg_;

}

// End of the file



//    descr.add_options()(OptionLabels::help().c_str(), "Help message");

//    descr.add_options()(OptionLabels::scandirs().c_str(),
//                        bpo::value<std::vector<std::string>>()->multitoken()
//                        ->default_value(std::vector<std::string>{"./"}),
//                        "Setup directories for scan");

//    descr.add_options()(OptionLabels::skipdirs().c_str(),
//                        bpo::value<std::vector<std::string>>()->multitoken()
//                        ->default_value(std::vector<std::string>{}),
//                        "Exclude directories from scan");

//    descr.add_options()(OptionLabels::level().c_str(),
//                        bpo::value<size_t>()->default_value(1),
//                        "Scan level: 0 - no recursive subfolder, 1 - all subfolders");

//    descr.add_options()(OptionLabels::minfilesz().c_str(),
//                        bpo::value<size_t>()->default_value(1),
//                        "Minimal file size in bytes");

//    descr.add_options()(OptionLabels::masks().c_str(),
//                        bpo::value<std::vector<std::string>>()->multitoken()
//                        ->default_value(std::vector<std::string>{}),
//                        "File masks");

//    descr.add_options()(OptionLabels::blocksize().c_str(),
//                        bpo::value<size_t>()->default_value(4),
//                        "Size of one block in bytes");

//    descr.add_options()(OptionLabels::hashalg().c_str(),
//                        bpo::value<std::string>()->default_value("md5"),
//                        "Hashing algorithm");
