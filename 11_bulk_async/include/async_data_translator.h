#pragma once

#include "async_data_processor.h"
#include "async_block_observer.h"
#include <cstddef>
#include <string>

namespace async
{

class DataTranslator final
{
public:
    void setup(const size_t block_size, const size_t id);
    void translate(const std::string & buffer);
    void close();

private:
    std::shared_ptr<DataProcessor>     data_processor_;
    std::shared_ptr<BlockObserverStd>  block_observer_std_;
    std::shared_ptr<BlockObserverFile> block_observer_file_;
};

}

// End of the file

