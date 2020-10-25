#pragma once

#include <cstddef>

struct MtbStatsCounterThread
{
    MtbStatsCounterThread(size_t blocks, size_t commands):
        blocks_counter(blocks),
        commands_counter(commands)
    {
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

    size_t lines_counter;
};

// End of the file
