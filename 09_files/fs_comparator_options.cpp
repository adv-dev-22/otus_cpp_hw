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
excl_dirs_(),
block_size_(0)
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

    // exclude dirs
    // ..

    descr.add_options()(OptionLabels::level().c_str(),
                        bpo::value<size_t>()->default_value(1),
                        "Scan level: 0 - no recursive subfolder, 1 - all subfolders");

    descr.add_options()(OptionLabels::minfilesz().c_str(),
                        bpo::value<size_t>()->default_value(1),
                        "Minimal file size in bytes");




    bpo::variables_map vars_map;
    bpo::store(bpo::parse_command_line(argc, argv, descr), vars_map);

    if (vars_map.count("help"))
    {
        std::cout << descr << std::endl;
    }

    const std::vector<std::string> & scan_vec = vars_map["scandirs"].as<std::vector<std::string>>();
    for (int k = 0; k < scan_vec.size(); ++k)
    {
        std::cout << scan_vec[k] << " ";
    }
    std::cout << std::endl;

}

const std::vector<std::string> & FsComparatorOptions::scan_dirs() const
{
    return scan_dirs_;
}

const std::vector<std::string> & FsComparatorOptions::excl_dirs() const
{
    return excl_dirs_;
}

size_t FsComparatorOptions::block_size() const noexcept
{
    return block_size_;
}

// End of the file
