#ifndef _DEFAULT_CONSTANTS_H_
#define _DEFAULT_CONSTANTS_H_

#include "color_engine.h"
#include <cstddef>

namespace GraphicalEditorCore {

class Default {
public:

    class Document {
    public:
        static size_t width() noexcept;
        static size_t height() noexcept;
        using color_engine_type = ColorEngineUniform;
    };

    // ..  ..

};

} // End of the namespace GraphicalEditorCore.

#endif  // _DEFAULT_CONSTANTS_H_

// End of the file
