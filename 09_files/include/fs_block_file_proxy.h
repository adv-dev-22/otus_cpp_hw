#ifndef _FS_BLOCK_FILE_PROXY_H_
#define _FS_BLOCK_FILE_PROXY_H_

#include <string>

class FsBlockFileProxy
{
public:
    FsBlockFileProxy(const std::string & full_name); //+ size of block
    ~FsBlockFileProxy() = default;

    size_t blocks_size() const noexcept;
    char block(const size_t index);

private:
    std::string fname_;
    //size_t


    std::string hash_;
    size_t position_;
};

#endif // _FS_BLOCK_FILE_PROXY_H_

// End of the file
