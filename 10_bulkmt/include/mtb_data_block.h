#ifndef _MTB_10_DATA_BLOCK_H_
#define _MTB_10_DATA_BLOCK_H_

#include "mtb_time_holder.h"
#include <cstddef>
#include <list>
#include <string>
#include <iostream>
#include <memory>

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

#endif // _MTB_10_DATA_BLOCK_H_

// End of the file

