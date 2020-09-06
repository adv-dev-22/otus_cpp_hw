#ifndef _07_DATA_BLOCK_H_
#define _07_DATA_BLOCK_H_

#include <cstddef>
#include <list>
#include <string>

class DataBlock
{
public:
    size_t block_size() const noexcept;

    void append(const std::string & str_line);

private:
    // Line number
    size_t size_;

    std::list<std::string> lst_data_;


};

#endif // _07_DATA_BLOCK_H_

// End of the file

