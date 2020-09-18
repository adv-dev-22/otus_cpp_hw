#ifndef _FS_OPTION_LABELS_H_
#define _FS_OPTION_LABELS_H_

#include <string>

class OptionLabels final
{
public:
    OptionLabels() = default;
    ~OptionLabels() = default;

    static std::string help()      noexcept;
    static std::string scandirs()  noexcept;
    static std::string scipdirs()  noexcept;
    static std::string level()     noexcept;
    static std::string minfilesz() noexcept;
    // ..
    static std::string blocksize() noexcept;
    static std::string hashalg()   noexcept;

};

#endif // _FS_OPTION_LABELS_H_

// End of the file
