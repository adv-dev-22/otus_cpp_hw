#include "async_block_observer.h"
#include "async_data_block.h"
#include <iostream>
#include <fstream>

namespace async
{

BlockObserverStd::BlockObserverStd():
BlockObserver()
{
}

void BlockObserverStd::update(const DataBlock & data_block)
{
    data_block.write(std::cout);
}

BlockObserverFile::BlockObserverFile(const size_t id):
BlockObserver(),
id_(id)
{
}

void BlockObserverFile::update(const DataBlock & data_block)
{
    std::string file_name("bulk-");
    file_name.append(std::to_string(this->id_));
    file_name.append("-");
    file_name.append(data_block.time_stamp());
    file_name.append(".log");

    std::ofstream fout(file_name, std::ofstream::app);
    data_block.write(fout);
    fout.close();
}

}

// End of the file
