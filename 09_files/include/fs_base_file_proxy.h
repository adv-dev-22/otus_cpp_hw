#ifndef _FS_BASE_FILE_PROXY_H_
#define _FS_BASE_FILE_PROXY_H_

#include "fs_comparator_options.h"
#include <string>

class FsBaseFileProxy
{
public:
    FsBaseFileProxy(const std::string & full_name,
                    const FsComparatorOptions & cmpr_options);

    virtual ~FsBaseFileProxy() = default;

protected:
    /*! File name to get the size */
    const std::string & ref_fname_;

    /*! Provides block_size value. */
    const FsComparatorOptions & ref_cmpr_optns_;

    /*! Controls proxy workflow. */
    mutable bool is_initialized_;
};

#endif  // _FS_BASE_FILE_PROXY_H_

// End of the file
