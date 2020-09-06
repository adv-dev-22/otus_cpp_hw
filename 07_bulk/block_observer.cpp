#include "block_observer.h"
#include "data_block.h"
#include <iostream>

BlockObserverStd::BlockObserverStd():
BlockObserver()
{

}

void BlockObserverStd::update(const DataBlock & data_block)
{
    data_block.write(std::cout);
}

BlockObserverFile::BlockObserverFile():
BlockObserver()
{

}

void BlockObserverFile::update(const DataBlock & data_block)
{

    std::cout << "File " << data_block.size() << std::endl;

}

// End of the file
