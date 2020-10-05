#include "fs_file_block_proxy.h"
#include <fstream>
#include <iostream>
#include <boost/uuid/detail/md5.hpp>
#include <boost/algorithm/hex.hpp>

using boost::uuids::detail::md5;

std::string toString(const md5::digest_type &digest)
{
    const auto charDigest = reinterpret_cast<const char *>(&digest);
    std::string result;
    boost::algorithm::hex(charDigest, charDigest + sizeof(md5::digest_type), std::back_inserter(result));
    return result;
}


FsFileBlockProxy::FsFileBlockProxy(const std::string & full_name,
                                   const FsComparatorOptions & cmpr_options,
                                   const size_t index_offset):
FsBaseFileProxy(full_name, cmpr_options),
idx_offset_(index_offset),
hash_()
{
}

char FsFileBlockProxy::get_hash() const
{
//    std::string s;

//      while(std::getline(std::cin, s)) {
//          md5 hash;
//          md5::digest_type digest;

//          hash.process_bytes(s.data(), s.size());
//          hash.get_digest(digest);

//          std::cout << "md5(" << s << ") = " << toString(digest) << '\n';
//      }




    if (!this->is_initialized_)
    {
        const size_t block_size = this->ref_cmpr_optns_.block_size();

        // Buffer to read in
        std::vector<char> vec_buffer(block_size, '\0');

        // Open file
        std::ifstream fin(ref_fname_, std::ifstream::binary);

        // Jump to the proper position
        fin.seekg(idx_offset_ * block_size);

        // In case last block is shorter, it reads only the tail and set eofbit and failbit to 1.
        fin.read(vec_buffer.data(), block_size);

        for (auto item : vec_buffer)
        {
            std::cout << item << " ";
        } std::cout << std::endl;

        //this->is_initialized_ = true;
    }

    return hash_;
}

// End of the file
