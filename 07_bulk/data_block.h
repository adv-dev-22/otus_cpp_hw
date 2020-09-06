#ifndef _07_DATA_BLOCK_H_
#define _07_DATA_BLOCK_H_

#include <cstddef>
#include <list>
#include <string>
#include <iostream>

class DataBlock final
{
public:
    DataBlock();
    ~DataBlock() = default;

    size_t size() const noexcept;

    void append(const std::string & str_line);
    void clear();

    void write(std::ostream & xout) const;

private:
    // Number of lines
    size_t size_;

    std::list<std::string> list_data_;
};

#endif // _07_DATA_BLOCK_H_

// End of the file

