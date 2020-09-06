#include "data_block.h"

DataBlock::DataBlock():
size_(0),
list_data_()
{

}

size_t DataBlock::size() const noexcept
{
    return  list_data_.size();
}

void DataBlock::append(const std::string & str_line)
{
    list_data_.push_back(str_line);
}

void DataBlock::clear()
{
    list_data_.clear();
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

// End of the file
