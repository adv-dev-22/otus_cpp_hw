#include "vers_lib.h"
#include "version.h"

int version_major() noexcept {
    return PROJECT_VERSION_MAJOR;
}

int version_minor() noexcept {
    return PROJECT_VERSION_MINOR;
}

int version_patch() noexcept {
    return PROJECT_VERSION_PATCH;
}

// End of the file
