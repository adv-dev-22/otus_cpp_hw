#include "fs_file_block_proxy.h"
#include <fstream>
#include <iostream>


FsFileBlockProxy::FsFileBlockProxy(const std::string & full_name,
                                   const FsComparatorOptions & cmpr_options,
                                   const size_t index_offset):
FsBaseFileProxy(full_name, cmpr_options),
idx_offset_(index_offset),
hash_(),
up_hash_alg_(nullptr)
{
    setup_hashing_algorithm_();
}

const std::string & FsFileBlockProxy::get_hash() const
{
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

//        md5 boost_md5_hash;
//        md5::digest_type digest;
//        boost_md5_hash.process_bytes(vec_buffer.data(), vec_buffer.size());
//        boost_md5_hash.get_digest(digest);

//        hash_ = md5_to_string(digest);

        hash_ = up_hash_alg_->compute(vec_buffer);
        std::cout << "md5(" << vec_buffer.data() << ") = " << hash_ << std::endl;

        this->is_initialized_ = true;
    }

    return hash_;
}

void FsFileBlockProxy::setup_hashing_algorithm_()
{
//    if (HashingAlgorithm::md5 == this->ref_cmpr_optns_->hash_alg())
//    {
        up_hash_alg_ = std::make_unique<HashAlgorithmMd5>();
        return;
//    }

    // ..

//    throw
}

// End of the file


//    std::string s;

//      while(std::getline(std::cin, s)) {
//          md5 hash;
//          md5::digest_type digest;

//          hash.process_bytes(s.data(), s.size());
//          hash.get_digest(digest);

//          std::cout << "md5(" << s << ") = " << toString(digest) << '\n';
//      }
