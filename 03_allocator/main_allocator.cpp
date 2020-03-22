#include "custom_allocator.hpp"
#include <iostream>
#include <map>



int main(int argc, char * argv []) {

    custom_allocator<double> alc;
    double * darr = alc.allocate(2);
    darr[1] = 224;

    alc.construct(darr,     2.0);
    alc.construct(darr + 1, 3.0);

    std::cout << darr[0] << std::endl;
    std::cout << darr[1] << std::endl;

    alc.destroy(darr);

    alc.deallocate(darr, 2);


    std::map<int, int>  standard_map;




    return 0;
}



// End of the file

