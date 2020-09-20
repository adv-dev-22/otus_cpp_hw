#ifndef _COMPARATOR_OPTIONS_H_
#define _COMPARATOR_OPTIONS_H_

#include <vector>
#include <string>

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
    const std::vector<std::string> & skip_dirs() const noexcept;

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

private:
    std::vector<std::string> scan_dirs_;

    std::vector<std::string> skip_dirs_;

    ScanLevel level_;

    size_t min_file_size_;

    std::vector<std::string> masks_;

    size_t block_size_;

    HashingAlgorithm hash_alg_;
};

#endif // _COMPARATOR_OPTIONS_H_

// End of the file



