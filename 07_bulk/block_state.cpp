#include "block_state.h"
#include "data_processor.h"
#include <iostream>


size_t IBlockState::block_size_ = 0;

IBlockState::IBlockState()
{
}

void IBlockState::set_block_size(const size_t block_size)
{
    block_size_ = block_size;
}

//-----------------------------------------------------------------------------

BlockStateEmpty::BlockStateEmpty():
IBlockState()
{
}

void BlockStateEmpty::open_bracket(DataProcessor * dp)
{
    //dp->set_state(new BlockStateBracketOpen(1));
    dp->set_state(new BlockStateTwoMoreBracketOpen(1));
}

void BlockStateEmpty::close_bracket(DataProcessor * /* dp */)
{
    throw std::logic_error("Can not close block. It is not opened.");
}

void BlockStateEmpty::add_line(DataProcessor * dp)
{
    dp->set_state(new BlockStateSimpleFilling());
}

void BlockStateEmpty::go_next_state(DataProcessor * dp)
{
}

void BlockStateEmpty::update_state(DataProcessor * dp)
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

BlockStateSimpleFilling::BlockStateSimpleFilling():
IBlockState(),
lines_counter_(1)
{
}

void BlockStateSimpleFilling::open_bracket(DataProcessor * dp)
{
    dp->set_state(new BlockStateBracketOpen(1));
}

void BlockStateSimpleFilling::close_bracket(DataProcessor * dp)
{
    throw std::logic_error("Can not close block. It is not opened.");
}

void BlockStateSimpleFilling::add_line(DataProcessor * dp)
{
    if (++lines_counter_ == BlockStateSimpleFilling::block_size_)
    {
        dp->set_state(new BlockStateReady());
    }
}

void BlockStateSimpleFilling::go_next_state(DataProcessor * dp)
{
}

void BlockStateSimpleFilling::update_state(DataProcessor * dp)
{
}

bool BlockStateSimpleFilling::is_relevant() const
{
    return true;
}

bool BlockStateSimpleFilling::is_ready() const
{
    return false;
}

//-----------------------------------------------------------------------------

BlockStateBracketOpen::BlockStateBracketOpen(const size_t brackets_counter):
brackets_counter_(brackets_counter)
{
}

void BlockStateBracketOpen::open_bracket(DataProcessor * dp)
{
}

void BlockStateBracketOpen::close_bracket(DataProcessor * dp)
{
}

void BlockStateBracketOpen::add_line(DataProcessor * dp)
{
    throw std::logic_error("Can not add line. It must be written.");
}

void BlockStateBracketOpen::go_next_state(DataProcessor * dp)
{
    dp->set_state(new BlockStateBracketFilling(1));
}

void BlockStateBracketOpen::update_state(DataProcessor * dp)
{
}

bool BlockStateBracketOpen::is_relevant() const
{
    return false;
}

bool BlockStateBracketOpen::is_ready() const
{
    return true;
}

//-----------------------------------------------------------------------------

BlockStateBracketFilling::BlockStateBracketFilling(const size_t brackets_counter):
brackets_counter_(brackets_counter)
{

}

void BlockStateBracketFilling::open_bracket(DataProcessor * dp)
{
    ++brackets_counter_;
    dp->set_state(new BlockStateTwoMoreBracketOpen(brackets_counter_));
}

void BlockStateBracketFilling::close_bracket(DataProcessor * dp)
{
    if (0 == --brackets_counter_)
    {
        dp->set_state(new BlockStateReady());
    }
    else
    {
        dp->set_state(new BlockStateTwoMoreBracketOpen(brackets_counter_));
    }
}

void BlockStateBracketFilling::add_line(DataProcessor * dp)
{
}

void BlockStateBracketFilling::go_next_state(DataProcessor * dp)
{
}

void BlockStateBracketFilling::update_state (DataProcessor * dp)
{
}

bool BlockStateBracketFilling::is_relevant() const
{
    return true;
}

bool BlockStateBracketFilling::is_ready() const
{
    return false;
}

//-----------------------------------------------------------------------------

BlockStateTwoMoreBracketOpen::BlockStateTwoMoreBracketOpen(const size_t brackets_counter):
brackets_counter_(brackets_counter)
{
}

void BlockStateTwoMoreBracketOpen::open_bracket(DataProcessor * dp)
{}

void BlockStateTwoMoreBracketOpen::close_bracket(DataProcessor * dp)
{}

void BlockStateTwoMoreBracketOpen::add_line(DataProcessor * dp)
{}

void BlockStateTwoMoreBracketOpen::go_next_state(DataProcessor * dp)
{}

void BlockStateTwoMoreBracketOpen::update_state(DataProcessor * dp)
{
    dp->set_state(new BlockStateBracketFilling(brackets_counter_));
}

bool BlockStateTwoMoreBracketOpen::is_relevant() const
{
    return false;
}

bool BlockStateTwoMoreBracketOpen::is_ready() const
{
    return false;
}

//-----------------------------------------------------------------------------

BlockStateReady::BlockStateReady():
IBlockState()
{
}

void BlockStateReady::open_bracket(DataProcessor * dp)
{
    throw std::logic_error("Can not open block. It must be written.");
}

void BlockStateReady::close_bracket(DataProcessor * dp)
{
    throw std::logic_error("Can not close block. It is not opened.");
}

void BlockStateReady::add_line(DataProcessor * dp)
{
    throw std::logic_error("Can not close block. It is not opened.");
}

void BlockStateReady::go_next_state(DataProcessor * dp)
{
    dp->set_state(new BlockStateEmpty());
}

void BlockStateReady::update_state (DataProcessor * dp)
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
