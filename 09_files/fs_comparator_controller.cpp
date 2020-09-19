#include "fs_comparator_controller.h"
#include "fs_comparator_options.h"
#include <memory>
#include <iostream>

FsComparatorController::FsComparatorController()
{
}

void FsComparatorController::run(int argc, char * argv [])
{
    auto cmd_options = std::make_unique<FsComparatorOptions>();
    cmd_options->parse(argc, argv);

    std::cout << "!! " << cmd_options->min_file_size() << std::endl;

}

// End of the file
