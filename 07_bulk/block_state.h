#ifndef _07_BLOCK_STATE_H_
#define _07_BLOCK_STATE_H_

class DataProcessor;

class IBlockState
{
public:
    IBlockState(const size_t block_size,
                const size_t lines_counter,
                const size_t brackets_counter);

    virtual ~IBlockState() = default;

    virtual void open_bracket(DataProcessor * dp) = 0;
    virtual void close_bracket(DataProcessor * dp) = 0;
    virtual bool add_line(DataProcessor * dp) = 0;

    virtual bool is_relevant() const = 0;
    virtual bool is_ready() const = 0;

protected:
    size_t block_size_
    size_t lines_counter_;

    size_t brackets_counter_;
};


class BlockStateEmpty : public IBlockState
{
public:
    BlockStateEmpty(const size_t block_size,
                    const size_t lines_counter = 0,
                    const size_t brackets_counter = 0);

    virtual ~BlockStateEmpty() = default;

    virtual void open_bracket(DataProcessor * dp) override;
    virtual void close_bracket(DataProcessor * dp) override;
    virtual bool add_line(DataProcessor * dp) override;

    virtual bool is_relevant() const override;
    virtual bool is_ready() const override;
};


class BlockStateSimpleFilling : public IBlockState
{
public:
    BlockStateSimpleFilling(const size_t block_size,
                            const size_t lines_counter,
                            const size_t brackets_counter);

    virtual ~BlockStateSimpleFilling() = default;

    virtual void open_bracket(DataProcessor * dp) override;
    virtual void close_bracket(DataProcessor * dp) override;
    virtual bool add_line(DataProcessor * dp) override;

    virtual bool is_relevant() const override;
    virtual bool is_ready() const override;
};


class BlockStateBracketFilling : public IBlockState
{
public:
    BlockStateBracketFilling(const size_t block_size,
                             const size_t lines_counter,
                             const size_t brackets_counter);

    virtual ~BlockStateBracketFilling() = default;

    virtual void open_bracket(DataProcessor * dp) override;
    virtual void close_bracket(DataProcessor * dp) override;
    virtual bool add_line(DataProcessor * dp) override;

    virtual bool is_relevant() const override;
    virtual bool is_ready() const override;
};


class BlockStateReady : public IBlockState
{
public:
    BlockStateReady(const size_t block_size,
                    const size_t lines_counter,
                    const size_t brackets_counter);

    virtual ~BlockStateReady() = default;

    virtual void open_bracket(DataProcessor * dp) override;
    virtual void close_bracket(DataProcessor * dp) override;
    virtual bool add_line(DataProcessor * dp) override;

    virtual bool is_relevant() const override;
    virtual bool is_ready() const override;
};

#endif  // _07_BLOCK_STATE_H_

// End of the file

