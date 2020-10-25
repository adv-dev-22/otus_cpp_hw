#ifndef _MTB_10_DATA_PROCESSOR_H_
#define _MTB_10_DATA_PROCESSOR_H_

#include "mtb_block_observer.h"
#include "mtb_data_block.h"
#include "mtb_block_state.h"
#include "mtb_block_transporter.h"
#include "mtb_stats_counter.h"
#include <string>
#include <memory>
#include <cstddef>
#include <list>
#include <utility>

class DataProcessor final
{
public:
    DataProcessor();
    ~DataProcessor() = default;

    void set_state(IBlockState * );

    void set_block_size(const size_t block_size);

    void subscribe(std::weak_ptr<MtbBlockTransporter> wp_block_transporter);

    // TODO: refactor
    void notify();

    void consider(const std::string & str_line);

    void conclude();

    void print_statistics();

private:
    /*! Default size from input */
    size_t block_size_;

    std::weak_ptr<MtbBlockTransporter> wp_transporter_;

    /*! Working data block. */
    std::unique_ptr<DataBlock> up_data_block_;

    std::pair<std::string, std::string> brackets_;

    std::unique_ptr<IBlockState> up_block_state_;

    std::shared_ptr<MtbStatsCounterMain> stats_counter_main_;

    void  clear_block_();
};


#endif  // _MTB_10_DATA_PROCESSOR_H_

// End of the file
