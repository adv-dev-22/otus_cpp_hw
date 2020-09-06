#include "data_processor.h"
#include <iostream>

DataProcessor::DataProcessor():
block_size_(0),
list_wp_block_observers_(),
up_data_block_(std::make_unique<DataBlock>()),
brackets_(std::make_pair("{","}")),
lines_counter_(0)
{

}

void DataProcessor::set_block_size(const size_t block_size)
{
    block_size_ = block_size;
}

void DataProcessor::subscribe(std::weak_ptr<BlockObserver> wp_block_observer)
{
    list_wp_block_observers_.push_back(wp_block_observer);
}

void DataProcessor::notify()
{
    for (auto item : list_wp_block_observers_)
    {
        item.lock()->update(*up_data_block_.get());
    }
}

void DataProcessor::consider(const std::string & str_line)
{
    if (0 == str_line.size()) return;

    up_data_block_->append(str_line);

    if (++lines_counter_ == block_size_)
    {
        this->notify();
        this->clear_block_();
    }

//    if (str_line == brackets_.first)
//    {

//    }

//    if (str_line == brackets_.second)
//    {


//    }
}

void DataProcessor::conclude()
{
    std::cout << "Ctrl + D is pressed" << std::endl;
    //this->notify();
}

void DataProcessor::clear_block_()
{
    lines_counter_ = 0;
    up_data_block_->clear();
}

// End of the file
