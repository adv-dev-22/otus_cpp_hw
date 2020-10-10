#include "mtb_data_translator.h"
#include "mtb_data_processor.h"
#include "mtb_block_transporter.h"
#include <iostream>
#include <memory>

void DataTranslator::run(int argc, char * argv [])
{
    if (argc < 2)
    {
        std::cout << "Block size must be set as a command line parameter.." << std::endl;
        return;
    }
    const size_t block_size = std::stoi(argv[1]);

    auto data_processor = std::make_unique<DataProcessor>();
    data_processor->set_block_size(block_size);

    auto up_block_transporter = std::make_unique<MtbBlockTransporter>();
    up_block_transporter->start_threads();

    auto block_observer_std = std::make_shared<BlockObserverStd>();
    data_processor->subscribe(block_observer_std);

    auto block_observer_file = std::make_shared<BlockObserverFile>();
    data_processor->subscribe(block_observer_file);

    std::string buffer;
    while (std::getline(std::cin, buffer))
    {
        data_processor->consider(buffer);
    }

    if (std::cin.eof())
    {
        data_processor->conclude();
    }

    up_block_transporter->conclude_threads();
    up_block_transporter->join_threads();
}

// End of the file
