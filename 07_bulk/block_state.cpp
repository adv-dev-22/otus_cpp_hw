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
    ///db->set_state();
    std::cout << "void BlockStateEmpty::open_bracket" << std::endl;
}

void BlockStateEmpty::close_bracket(DataProcessor * /* dp */)
{
    throw std::logic_error("Can not close block. It is not opened.");
}

void BlockStateEmpty::add_line(DataProcessor * dp)
{
    dp->set_state(new BlockStateSimpleFilling());
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
    std::cout << "void BlockStateSimpleFilling::open_bracket" << std::endl;
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

bool BlockStateSimpleFilling::is_relevant() const
{
    return true;
}

bool BlockStateSimpleFilling::is_ready() const
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
    std::cout << "void BlockStateSimpleFilling::open_bracket" << std::endl;
}

void BlockStateReady::close_bracket(DataProcessor * dp)
{
    throw std::logic_error("Can not close block. It is not opened.");
}

void BlockStateReady::add_line(DataProcessor * dp)
{
    throw std::logic_error("Can not close block. It is not opened.");
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
