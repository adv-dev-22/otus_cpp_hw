#include "fs_comparator_controller.h"
#include "fs_comparator_engine.h"
#include "fs_comparator_options.h"
#include "fs_names_collection.h"
#include "fs_printer.h"
#include <memory>

FsComparatorController::FsComparatorController()
{
}

void FsComparatorController::run(int argc, char * argv [])
{
    auto up_cmd_options = std::make_unique<FsComparatorOptions>();
    up_cmd_options->parse(argc, argv);

    if (up_cmd_options->help_request()) return;

    auto up_names_clctn = std::make_unique<FsNamesCollectionBoost>();
    up_names_clctn->extract_file_names(*up_cmd_options);

    auto up_cmpr_engine = std::make_unique<FsComparatorEngine>();
    up_cmpr_engine->find_duplicates(up_names_clctn->fnames_vec(), *up_cmd_options);

    auto up_printer = std::make_unique<FsPrinter>();
    up_printer->put_out(up_names_clctn->fnames_vec(), up_cmpr_engine->lli_duplicates());
}

// End of the file
