#include "ip_loader.h"
#include <iostream>

static vec_str split(const string & str, char d) {

    vec_str r;

    string::size_type start = 0;
    string::size_type stop = str.find_first_of(d);

    while(stop != std::string::npos) {

        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

IpDataLoader::IpDataLoader():
vvs_ip_pool_(0) {
}

void IpDataLoader::read_from_stdin() {

    try {
        for (string line; std::getline(std::cin, line); ) {
            vector<string> v = split(line, '\t');
            vvs_ip_pool_.push_back(split(v.at(0), '.'));
        }
    }
    catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}

vector<vec_str> IpDataLoader::get_ip_pool() noexcept {

    //std::cout << "-->" << vvs_ip_pool_.size() << std::endl;
    return std::move(vvs_ip_pool_);
}

// End of the file

