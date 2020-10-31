#include "async_data_block.h"

namespace async
{

DataBlock::DataBlock():
size_(0),
list_data_(),
up_time_holder_(std::make_unique<TimeHolder>())
{
}

size_t DataBlock::size() const noexcept
{
    return list_data_.size();
}

std::string DataBlock::time_stamp() const noexcept
{
    return up_time_holder_->time_stamp();
}

void DataBlock::append(const std::string & str_line)
{
    list_data_.push_back(str_line);
    up_time_holder_->capture_at_first();
}

void DataBlock::clear()
{
    list_data_.clear();
    up_time_holder_->clear();
}

void DataBlock::write(std::ostream & xout) const
{
    std::string delimeter("");

    xout << "bulk: ";
    for (auto & item : list_data_)
    {
        xout << delimeter << item;
        delimeter = ", ";
    }
    xout << std::endl;
}

}

// End of the file
