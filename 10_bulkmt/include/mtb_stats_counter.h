#pragma once

#include <cstddef>
#include <sstream>
#include <string>

struct MtbStatsCounterThread
{
    MtbStatsCounterThread(size_t blocks, size_t commands):
        blocks_counter(blocks),
        commands_counter(commands)
    {
    }

    virtual std::string get_stat_str(const std::string & label) const
    {
        std::stringstream ss;
        ss << label;
        ss << this->blocks_counter << " blocks, ";
        ss << this->commands_counter << " commands";

        return ss.str();
    }

    size_t blocks_counter;
    size_t commands_counter;
};

struct MtbStatsCounterMain : public MtbStatsCounterThread
{
    MtbStatsCounterMain(size_t blocks, size_t commands, size_t lines):
    MtbStatsCounterThread(blocks, commands),
    lines_counter(lines)
    {
    }

    virtual std::string get_stat_str(const std::string & label) const
    {
        std::stringstream ss;
        ss << label;
        ss << this->lines_counter << " lines, ";
        ss << MtbStatsCounterThread::get_stat_str("");

        return ss.str();
    }

    size_t lines_counter;
};

// End of the file
