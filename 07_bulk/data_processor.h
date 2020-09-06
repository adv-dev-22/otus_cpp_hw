#ifndef _07_DATA_PROCESSOR_H_
#define _07_DATA_PROCESSOR_H_

#include "block_observer.h"
#include <string>
#include <memory>
#include <cstddef>

class DataProcessor final
{
public:
    DataProcessor();
    ~DataProcessor() = default;

    void set_block_size(const size_t block_size);
    void subscribe(std::weak_ptr<BlockObserver> wp_block_observer);

    void consider(const std::string & str_line);
    void conclude();

private:
    size_t block_size_;
    std::weak_ptr<BlockObserver> wp_block_observer_;
};


#endif  // _07_DATA_PROCESSOR_H_

// End of the file
