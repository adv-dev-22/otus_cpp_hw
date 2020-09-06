#include "data_processor.h"
#include <iostream>

DataProcessor::DataProcessor():
block_size_(0),
wp_block_observer_()
{

}

void DataProcessor::set_block_size(const size_t block_size)
{
    block_size_ = block_size;
}

void DataProcessor::subscribe(std::weak_ptr<BlockObserver> wp_block_observer)
{
    wp_block_observer_ = wp_block_observer;
}

void DataProcessor::consider(const std::string & str_line)
{
    std::cout << "Processing: " << str_line << std::endl;



}

void DataProcessor::conclude()
{
    std::cout << "Ctrl + D is pressed" << std::endl;
}

// End of the file
