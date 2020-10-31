#pragma once

#include "async_time_holder.h"
#include <cstddef>
#include <list>
#include <string>
#include <iostream>
#include <memory>

namespace async
{

class DataBlock final
{
public:
    DataBlock();
    ~DataBlock() = default;

    size_t size() const noexcept;
    std::string time_stamp() const noexcept;

    void append(const std::string & str_line);
    void clear();

    void write(std::ostream & xout) const;

private:
    // Number of lines
    size_t size_;

    std::list<std::string> list_data_;

    std::unique_ptr<TimeHolder> up_time_holder_;
};

}

// End of the file

