#pragma once

#include <string>

namespace async
{

class TimeHolder final
{
public:
    TimeHolder();
    ~TimeHolder() = default;

    void capture_at_first();
    void clear();

    std::string time_stamp() const noexcept;

private:
    std::string time_stamp_;
    bool at_first_;
};

} //namespace async

// End of the file
