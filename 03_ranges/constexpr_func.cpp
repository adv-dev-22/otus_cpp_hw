#include <cstddef>

constexpr size_t bin_id_gt_1(size_t x) {
    return 0 == x ? 0 : (1 == x ? 1 : 1 + bin_id_gt_1(x >> 1));
}

constexpr size_t bin_id(size_t x) {
    return (0 == x || 1 == x) ? 0 : bin_id_gt_1(x - 1);
}

int main(int argc, char * argv []) {

    static_assert(bin_id(0) == 0);
    static_assert(bin_id(1) == 0);
    static_assert(bin_id(2) == 1);
    static_assert(bin_id(4) == 2);
    static_assert(bin_id(7) == 3);
    static_assert(bin_id(8) == 3);
    static_assert(bin_id(9) == 4);
    static_assert(bin_id(1023) == 10);
    static_assert(bin_id(1024) == 10);
    static_assert(bin_id(1025) == 11);
    static_assert(bin_id(1024*1024-33) == 20);
    static_assert(bin_id(1024*1024) == 20);
    static_assert(bin_id(1024*1024+33) == 21);
    static_assert(bin_id(1024*1024*1024-127) == 30);
    static_assert(bin_id(1024*1024*1024) == 30);
    static_assert(bin_id(1024*1024*1024+127) == 31);

//    for (size_t i = 0; i < 20; ++i) {
//        std::cout << i << "  " << bin_id(i) << std::endl;
//    }

    return 0;
}
