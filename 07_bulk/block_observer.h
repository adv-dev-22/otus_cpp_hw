#ifndef _07_BLOCK_OBSERVER_H_
#define _07_BLOCK_OBSERVER_H_

class DataBlock;

class BlockObserver
{
public:
    BlockObserver() = default;
    virtual ~BlockObserver() = default;

    virtual void update(const DataBlock & data_block) = 0;

private:

};

class BlockObserverStd : public BlockObserver
{
public:
    BlockObserverStd();
    virtual ~BlockObserverStd() = default;

    virtual void update(const DataBlock & data_block);

private:

};

class BlockObserverFile : public BlockObserver
{
public:
    BlockObserverFile();
    virtual ~BlockObserverFile() = default;

    virtual void update(const DataBlock & data_block);

private:

};


#endif  // _07_BLOCK_OBSERVER_H_

// End of the file
