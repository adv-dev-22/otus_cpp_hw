#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]

using  std::vector;
using  std::string;

using  vec_str = std::vector<std::string>;
using  str_sz_t = std::string::size_type;

vec_str split(const std::string &str, char d) {

    vec_str r;

    str_sz_t start = 0;
    str_sz_t stop = str.find_first_of(d);

    while(stop != std::string::npos) {

        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

bool ccomparator(const vec_str & left_vs,
                 const vec_str & right_vs,
                 const size_t counter = 0) {

    if (4 == counter) return false;

    const size_t left_byte_k  = std::stoi(left_vs.at(counter));
    const size_t right_byte_k = std::stoi(right_vs.at(counter));

    if (left_byte_k > right_byte_k) {
        return true;
    }

    if (left_byte_k == right_byte_k) {
        return ccomparator(left_vs, right_vs, counter + 1);
    }

    return false;
}

int main(int argc, char const *argv[]) {






    try {
        std::vector<vec_str> ip_pool;

        for(std::string line; std::getline(std::cin, line); ) {
            vec_str v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        // TODO reverse lexicographically sort
        std::sort(ip_pool.begin(),
                  ip_pool.end(),
                  [](const vec_str & left_item, const vec_str & right_item) {
                    return ccomparator(left_item, right_item);
                  });

        for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip) {
            for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part) {
                if (ip_part != ip->cbegin()) {
                    std::cout << ".";
                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)
//        std::copy_if(ip_pool.cbegin(),
//                     ip_pool.cend(),
//                     std::ostream_iterator<const vec_str>(std::cout," "),
//                     [](const vec_str & item) {

////            if (1 == std::stoi(item.at(0))) {
////                return true;
////            }

//            return false;

//        }
//                     );

//          std::cout << std::endl;

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
