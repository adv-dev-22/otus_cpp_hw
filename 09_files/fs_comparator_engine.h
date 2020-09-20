#ifndef _FS_COMPARATOR_ENGINE_H_
#define _FS_COMPARATOR_ENGINE_H_

#include <list>
#include <string>

class FsComparatorEngine
{
public:
    FsComparatorEngine();
    ~FsComparatorEngine() = default;

    void find_duplicates(const std::list<std::string> & fnames_list);

    const std::list<std::list<std::string>> & duplicates_list() const noexcept;

private:
    std::list<std::list<std::string>> lls_duplicates_;
};

#endif // _FS_COMPARATOR_ENGINE_H_

// End of the file
