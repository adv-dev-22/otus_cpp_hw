#ifndef _FS_BLOCKS_NUMBER_PROXY_H_
#define _FS_BLOCKS_NUMBER_PROXY_H_

#include "fs_comparator_options.h"
#include <string>

class FsBlocksNumberProxy final
{
public:
    FsBlocksNumberProxy(const std::string & full_name,
                        const FsComparatorOptions & cmpr_options);
    ~FsBlocksNumberProxy() = default;

    size_t get() const;

private:
    /*! File name to get the size */
    const std::string & ref_fname_;

    /*! Provides block_size value. */
    const FsComparatorOptions & ref_cmpr_optns_;

    /*! Controls proxy workflow. */
    mutable bool is_initialized_;

    /*! It is computed at first, then keeps the value.  */
    mutable size_t blocks_number_;
};

#endif  // _FS_BLOCKS_NUMBER_PROXY_H_

// End of the file
