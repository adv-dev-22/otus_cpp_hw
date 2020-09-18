#ifndef _COMPARATOR_OPTIONS_H_
#define _COMPARATOR_OPTIONS_H_

#include <list>
#include <string>

class FsComparatorOptions final
{
public:
    FsComparatorOptions();
    ~FsComparatorOptions() = default;

    void parse(int argc, char * argv []);

    const std::list<std::string> & scan_dirs() const;
    const std::list<std::string> & excl_dirs() const;

    size_t block_size() const noexcept;

private:
    std::list<std::string> scan_dirs_;
    std::list<std::string> excl_dirs_;
    size_t block_size_;

};

#endif // _COMPARATOR_OPTIONS_H_

// End of the file



