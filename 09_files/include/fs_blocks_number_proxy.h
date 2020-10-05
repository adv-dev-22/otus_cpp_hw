#ifndef _FS_BLOCKS_NUMBER_PROXY_H_
#define _FS_BLOCKS_NUMBER_PROXY_H_

#include "fs_base_file_proxy.h"
#include <string>

class FsBlocksNumberProxy : public FsBaseFileProxy
{
public:
    FsBlocksNumberProxy(const std::string & full_name,
                        const FsComparatorOptions & cmpr_options);

    ~FsBlocksNumberProxy() = default;

    size_t get() const;

private:
    /*! It is computed at first, then keeps the value.  */
    mutable size_t blocks_number_;
};

#endif  // _FS_BLOCKS_NUMBER_PROXY_H_

// End of the file
