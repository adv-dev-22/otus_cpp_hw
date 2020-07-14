#ifndef _DEFAULT_CONSTANTS_H_
#define _DEFAULT_CONSTANTS_H_

#include <cstddef>

namespace GraphicalEditorCore {

class Default {
public:

    class Document {
    public:
        static size_t width() noexcept;
        static size_t height() noexcept;
    };

    template <typename T>
    class ColorEngine_t {
    public:
        using Type = T;
    };

    // ..  ..

};

} // End of the namespace GraphicalEditorCore.

#endif  // _DEFAULT_CONSTANTS_H_

// End of the file
