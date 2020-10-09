#include "mtb_block_observer.h"
#include "mtb_data_block.h"
#include <iostream>
#include <fstream>

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
    std::string file_name("bulk");
    file_name.append(data_block.time_stamp());
    file_name.append(".log");

    std::ofstream fout(file_name, std::ofstream::out);
    data_block.write(fout);
    fout.close();
}

// End of the file
