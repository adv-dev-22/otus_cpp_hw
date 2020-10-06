#ifndef _FS_HASH_ALGORITHM_H_
#define _FS_HASH_ALGORITHM_H_

#include <string>
#include <vector>

class HashAlgorithmBase
{
public:
    HashAlgorithmBase() = default;
    virtual ~HashAlgorithmBase() = default;

    virtual std::string compute(const std::vector<char> & vec_buffer) = 0;
};

class HashAlgorithmMd5 : public HashAlgorithmBase
{
public:
    HashAlgorithmMd5() = default;
    virtual ~HashAlgorithmMd5() = default;

    virtual std::string compute(const std::vector<char> & vec_buffer);
};

class HashAlgorithmCrc32 : public HashAlgorithmBase
{
public:
    HashAlgorithmCrc32() = default;
    virtual ~HashAlgorithmCrc32() = default;

    virtual std::string compute(const std::vector<char> &vec_buffer);
};

#endif  // _FS_HASH_ALGORITHM_H_

// End of the file
