#ifndef _07_BLOCK_STATE_H_
#define _07_BLOCK_STATE_H_

#include <cstddef>

class DataProcessor;

class IBlockState
{
public:
    IBlockState();

    virtual ~IBlockState() = default;

    static void set_block_size(const size_t block_size);

    virtual void open_bracket (DataProcessor * dp) = 0;
    virtual void close_bracket(DataProcessor * dp) = 0;
    virtual void add_line     (DataProcessor * dp) = 0;
    virtual void go_next_state(DataProcessor * dp) = 0;
    virtual void update_state (DataProcessor * dp) = 0;

    virtual bool is_relevant() const = 0;
    virtual bool is_ready()    const = 0;

protected:
    static size_t block_size_;
};

class BlockStateEmpty final : public IBlockState
{
public:
    BlockStateEmpty();
    virtual ~BlockStateEmpty() = default;

    virtual void open_bracket (DataProcessor * dp) override;
    virtual void close_bracket(DataProcessor * dp) override;
    virtual void add_line     (DataProcessor * dp) override;
    virtual void go_next_state(DataProcessor * dp) override;
    virtual void update_state (DataProcessor * dp) override;

    virtual bool is_relevant() const override;
    virtual bool is_ready()    const override;
};

class BlockStateSimpleFilling final : public IBlockState
{
public:
    BlockStateSimpleFilling();

    virtual ~BlockStateSimpleFilling() = default;

    virtual void open_bracket (DataProcessor * dp) override;
    virtual void close_bracket(DataProcessor * dp) override;
    virtual void add_line     (DataProcessor * dp) override;
    virtual void go_next_state(DataProcessor * dp) override;
    virtual void update_state (DataProcessor * dp) override;

    virtual bool is_relevant() const override;
    virtual bool is_ready()    const override;

protected:
    size_t lines_counter_;
};

class BlockStateBracketOpen final : public IBlockState
{
public:
    BlockStateBracketOpen(const size_t brackets_counter);
    virtual ~BlockStateBracketOpen() = default;

    virtual void open_bracket (DataProcessor * dp) override;
    virtual void close_bracket(DataProcessor * dp) override;
    virtual void add_line     (DataProcessor * dp) override;
    virtual void go_next_state(DataProcessor * dp) override;
    virtual void update_state (DataProcessor * dp) override;

    virtual bool is_relevant() const override;
    virtual bool is_ready()    const override;
private:
    size_t brackets_counter_;
};

class BlockStateBracketFilling final : public IBlockState
{
public:
    BlockStateBracketFilling(const size_t brackets_counter);

    virtual ~BlockStateBracketFilling() = default;

    virtual void open_bracket (DataProcessor * dp) override;
    virtual void close_bracket(DataProcessor * dp) override;
    virtual void add_line     (DataProcessor * dp) override;
    virtual void go_next_state(DataProcessor * dp) override;
    virtual void update_state (DataProcessor * dp) override;

    virtual bool is_relevant() const override;
    virtual bool is_ready()    const override;

protected:
    size_t brackets_counter_;
};

class BlockStateTwoMoreBracketOpen final : public IBlockState
{
public:
    BlockStateTwoMoreBracketOpen(const size_t brackets_counter);
    virtual ~BlockStateTwoMoreBracketOpen() = default;

    virtual void open_bracket (DataProcessor * dp) override;
    virtual void close_bracket(DataProcessor * dp) override;
    virtual void add_line     (DataProcessor * dp) override;
    virtual void go_next_state(DataProcessor * dp) override;
    virtual void update_state (DataProcessor * dp) override;

    virtual bool is_relevant() const override;
    virtual bool is_ready()    const override;
private:
    size_t brackets_counter_;
};

class BlockStateReady : public IBlockState
{
public:
    BlockStateReady();
    virtual ~BlockStateReady() = default;

    virtual void open_bracket (DataProcessor * dp) override;
    virtual void close_bracket(DataProcessor * dp) override;
    virtual void add_line     (DataProcessor * dp) override;
    virtual void go_next_state(DataProcessor * dp) override;
    virtual void update_state (DataProcessor * dp) override;

    virtual bool is_relevant() const override;
    virtual bool is_ready()    const override;
};

#endif  // _07_BLOCK_STATE_H_

// End of the file

