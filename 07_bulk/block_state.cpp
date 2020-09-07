#include "block_state.h"

BlockState::BlockState(const size_t block_size,
                       const size_t lines_counter,
                       const size_t brackets_counter):
block_size_(block_size),
lines_counter_(lines_counter),
brackets_counter_(brackets_counter)
{

}

//-----------------------------------------------------------------------------

BlockStateEmpty::BlockStateEmpty(const size_t block_size,
                                 const size_t lines_counter,
                                 const size_t brackets_counter):
IBlockState(block_size, lines_counter, brackets_counter)
{

}

void BlockStateEmpty::open_bracket(DataProcessor * dp)
{

}


void BlockStateEmpty::close_bracket(DataProcessor * dp)
{
    // throw std::
}

bool BlockStateEmpty::add_line(DataProcessor * dp)
{

}

bool BlockStateEmpty::is_relevant() const
{
    return true;
}

bool BlockStateEmpty::is_ready() const
{
    return false;
}

//-----------------------------------------------------------------------------

BlockStateReady::BlockStateReady(const size_t block_size,
                                 const size_t lines_counter,
                                 const size_t brackets_counter):
IBlockState(block_size, lines_counter, brackets_counter)
{

}

void BlockStateReady::open_bracket(DataProcessor * dp)
{

}

void BlockStateReady::close_bracket(DataProcessor * dp)
{

}

bool BlockStateReady::add_line(DataProcessor * dp)
{

}

bool BlockStateReady::is_relevant() const
{
    return false;
}

bool BlockStateReady::is_ready() const
{
    return true;
}


// End of the file
