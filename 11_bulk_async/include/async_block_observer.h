#pragma once

#include <cstddef>

namespace async
{

class DataBlock;

class BlockObserver
{
public:
    BlockObserver() = default;
    virtual ~BlockObserver() = default;

    virtual void update(const DataBlock & data_block) = 0;
};

class BlockObserverStd : public BlockObserver
{
public:
    BlockObserverStd();
    virtual ~BlockObserverStd() = default;

    virtual void update(const DataBlock & data_block);
};

class BlockObserverFile : public BlockObserver
{
public:
    explicit BlockObserverFile(const size_t id);
    virtual ~BlockObserverFile() = default;

    virtual void update(const DataBlock & data_block);
private:
    size_t id_;
};

}

// End of the file
