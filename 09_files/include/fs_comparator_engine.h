#ifndef _FS_COMPARATOR_ENGINE_H_
#define _FS_COMPARATOR_ENGINE_H_

#include <vector>
#include <string>
#include <list>

class FsComparatorEngine
{
public:
    FsComparatorEngine();
    ~FsComparatorEngine() = default;

    void find_duplicates(const std::vector<std::string> & fnames_list);

    const std::list<std::list<std::string>> & ll_duplicates() const noexcept;

private:
    std::list<std::list<std::string>> lls_duplicates_;

    std::list<std::pair<size_t, size_t>> make_pairs_list_(const std::vector<std::string> & fnames_vec);
};

#endif // _FS_COMPARATOR_ENGINE_H_

// End of the file
