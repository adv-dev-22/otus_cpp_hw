#ifndef _COMPARATOR_OPTIONS_H_
#define _COMPARATOR_OPTIONS_H_

#include <vector>
#include <string>
#include <set>
#include <boost/program_options.hpp>

namespace bpo = boost::program_options;

enum class ScanLevel : char
{
    ZeroLayer = 0,
    AllSubfolders = 64,
    Undefined = 65
};

enum class HashingAlgorithm : char
{
    md5 = 1,
    crc32 = 2,
    Undefined = 0
};


class FsComparatorOptions final
{
public:
    FsComparatorOptions();
    ~FsComparatorOptions() = default;

    /*! Parser uses boost options. */
    void parse(int argc, char * argv []);

    /*! Directories for scan */
    const std::vector<std::string> & scan_dirs() const noexcept;

    /*! Directories which should be excluded from scan */
    const std::set<std::string> & skip_dirs() const noexcept;

    /*! 0 - no subfolders. 1 - recursively, all subfolders */
    ScanLevel level() const noexcept;

    /*! Minimal file size in bytes */
    size_t min_file_size() const noexcept;

    /*! File name should satisfy one of the given regexp */
    const std::vector<std::string> & masks() const noexcept;

    /*! Files are read and compared by hash computed on block */
    size_t block_size() const noexcept;

    /*! Hashing algorithm */
    HashingAlgorithm hash_alg() const noexcept;

    bool help_request() const noexcept;

private:
    /*! Directories for scan. */
    std::vector<std::string> scan_dirs_;

    /*! During scan of given directories it checks if there are
     *  some to be skipped. This is exactly the set which contains
     *  such (to be skipped) dirs. Access should be fast enough, so it is
     *  set with O(log(n)) complexity.
     */
    std::set<std::string> skip_dirs_;

    /*! Scans recursively subfolders or only 1 layer. */
    ScanLevel level_;

    size_t min_file_size_;

    std::vector<std::string> masks_;

    size_t block_size_;

    HashingAlgorithm hash_alg_;

    /*! Stop program workflow in case --help option is typed. */
    bool help_request_;


    /*! Introduce necessary options. Add description and default values. */
    bpo::options_description  describe_options_();

    /*! Fill up internal class data from boost program options. */
    void extract_option_values_(const bpo::variables_map & vars_map);
};

#endif // _COMPARATOR_OPTIONS_H_

// End of the file



