#ifndef _DEFAULT_CONSTANTS_H_
#define _DEFAULT_CONSTANTS_H_

#include <cstddef>

namespace GraphicalEditorCore {

class Default {

    class Document {
    public:
        static size_t width() noexcept;
        static size_t height() noexcept;
        static size_t colorDepth() noexcept;
    };

    // ..  ..

};

} // End of the namespace GraphicalEditorCore.

#endif  // _DEFAULT_CONSTANTS_H_

// End of the file
