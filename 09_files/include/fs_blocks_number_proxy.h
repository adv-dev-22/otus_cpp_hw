#ifndef _FS_BLOCKS_NUMBER_PROXY_H_
#define _FS_BLOCKS_NUMBER_PROXY_H_

#include <string>

class FsBlocksNumberProxy final
{
public:
    FsBlocksNumberProxy(const std::string & full_name);
    ~FsBlocksNumberProxy() = default;

    size_t operator() ();

private:
    /*! File name to get the size */
    const std::string & ref_fname_;

    /*! Controls proxy workflow. */
    bool is_initialized_;

    /*! It is computed at first, then keeps the value.  */
    size_t blocks_number_;
};

#endif  // _FS_BLOCKS_NUMBER_PROXY_H_

// End of the file
