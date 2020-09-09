#include "data_processor.h"
#include <iostream>

DataProcessor::DataProcessor():
block_size_(0),
list_wp_block_observers_(),
up_data_block_(std::make_unique<DataBlock>()),
brackets_(std::make_pair("{","}")),
up_block_state_(std::make_unique<BlockStateEmpty>())
{
}

void DataProcessor::set_state(IBlockState * block_state)
{
    up_block_state_.reset(block_state);
}

void DataProcessor::set_block_size(const size_t block_size)
{
    block_size_ = block_size;
    IBlockState::set_block_size(block_size);
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
    // The order of the block statements is important.

    if (0 == str_line.size()) return;

    up_block_state_->update_state(this);

    if (str_line == brackets_.first ) up_block_state_->open_bracket(this);
    if (str_line == brackets_.second) up_block_state_->close_bracket(this);

    if (up_block_state_->is_relevant())
    {
        up_data_block_->append(str_line);
        up_block_state_->add_line(this);
    }

    if (up_block_state_->is_ready())
    {
        this->notify();
        this->clear_block_();
        return;
    }
}

void DataProcessor::conclude()
{
    //std::cout << "Ctrl + D is pressed" << std::endl;
    if (up_block_state_->is_simple())
    {
        this->notify();
        this->clear_block_();
    }
}

void DataProcessor::clear_block_()
{
    up_data_block_->clear();
    up_block_state_->go_next_state(this);
}

// End of the file
