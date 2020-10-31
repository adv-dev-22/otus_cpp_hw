#include "async_data_translator.h"
#include "async_data_processor.h"
#include <iostream>
#include <memory>

namespace async
{

void DataTranslator::setup(const size_t block_size, const size_t id)
{
    data_processor_ = std::make_shared<DataProcessor>();
    data_processor_->set_block_size(block_size);

    block_observer_std_ = std::make_shared<BlockObserverStd>();
    data_processor_->subscribe(block_observer_std_);

    block_observer_file_ = std::make_shared<BlockObserverFile>(id);
    data_processor_->subscribe(block_observer_file_);
}

void DataTranslator::translate(const std::string & buffer)
{
    data_processor_->consider(buffer);
}

void DataTranslator::close()
{
    data_processor_->conclude();
}

}

// End of the file
