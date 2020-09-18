#include <memory>
#include "fs_comparator_controller.h"

int main(int argc, char * argv [])
{
    auto fs_comparator = std::make_unique<FsComparatorController>();
    fs_comparator->run(argc, argv);

    return 0;
}


