#include "fs_base_file_proxy.h"


FsBaseFileProxy::FsBaseFileProxy(const std::string & full_name,
                                 const FsComparatorOptions & cmpr_options):
ref_fname_(full_name),
ref_cmpr_optns_(cmpr_options),
is_initialized_(false)
{
}

// End of the file
