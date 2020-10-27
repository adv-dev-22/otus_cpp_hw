#include "async_time_holder.h"
#include <chrono>
#include <iostream>

using namespace std::chrono;

namespace async
{

TimeHolder::TimeHolder():
time_stamp_("undefined"),
at_first_(true)
{
}

void TimeHolder::capture_at_first()
{
    if (at_first_)
    {
        system_clock::time_point tp = system_clock::now();
        system_clock::duration  dtn = tp.time_since_epoch();

        const unsigned long long secs = dtn.count() * system_clock::period::num / system_clock::period::den;
        time_stamp_ = std::to_string(secs);

        at_first_ = false;
    }
}

void TimeHolder::clear()
{
    at_first_ = true;
}

std::string TimeHolder::time_stamp() const noexcept
{
    return time_stamp_;
}

}

// End of the file

