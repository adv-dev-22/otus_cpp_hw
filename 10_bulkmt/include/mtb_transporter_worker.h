#ifndef _MTB_10_TRANSPORTER_WORKER_H_
#define _MTB_10_TRANSPORTER_WORKER_H_

class MtbTransporterWorkerBase
{
public:
    MtbTransporterWorkerBase();
    virtual ~MtbTransporterWorkerBase() = default;

    virtual void operator() () = 0;

    void conclude_processing() noexcept;

protected:
    bool processing_is_finished_;

};

class MtbTransporterWorkerStd : public MtbTransporterWorkerBase
{
public:
    MtbTransporterWorkerStd();
    virtual ~MtbTransporterWorkerStd() = default;

    virtual void operator() () override;

};

class MtbTransporterWorkerFile : public MtbTransporterWorkerBase
{
public:
    MtbTransporterWorkerFile();
    virtual ~MtbTransporterWorkerFile() = default;

    virtual void operator() () override;
};

#endif  // _MTB_10_TRANSPORTER_WORKER_H_

// End of the file
