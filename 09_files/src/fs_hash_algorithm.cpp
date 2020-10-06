#include "fs_hash_algorithm.h"
#include <boost/uuid/detail/md5.hpp>
#include <boost/algorithm/hex.hpp>
#include <boost/crc.hpp>
#include <sstream>

#include <iostream>

using boost::uuids::detail::md5;

static std::string md5_to_string(const md5::digest_type &digest)
{
    const auto char_digest = reinterpret_cast<const char *>(&digest);
    std::string result;
    boost::algorithm::hex(char_digest,
                          char_digest + sizeof(md5::digest_type),
                          std::back_inserter(result));
    return result;
}

std::string HashAlgorithmMd5::compute(const std::vector<char> & vec_buffer)
{
    md5 boost_md5_hash;
    md5::digest_type digest;
    boost_md5_hash.process_bytes(vec_buffer.data(), vec_buffer.size());
    boost_md5_hash.get_digest(digest);

    return md5_to_string(digest);
}

std::string HashAlgorithmCrc32::compute(const std::vector<char> &vec_buffer)
{
    boost::crc_32_type result;
    result.process_bytes(vec_buffer.data(), vec_buffer.size());

    std::stringstream  ss;
    ss << result.checksum();

    return ss.str();
}

// End of the file
