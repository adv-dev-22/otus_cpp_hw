#include "mtb_data_translator.h"
#include <iostream>
#include <memory>

int main(int argc, char * argv [])
{
    auto data_translator = std::make_unique<DataTranslator>();
    data_translator->run(argc, argv);

    return 0;
}

// End of the file
