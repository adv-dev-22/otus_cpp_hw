#include "reserve_allocator.hpp"
#include <iostream>
#include <map>

int main(int argc, char * argv []) {

    reserve_allocator<double, 16> alc;
    double * darr0 = alc.allocate(2);
    double * darr2 = alc.allocate(1);
    double * darr3 = alc.allocate(13);
    alc.deallocate(darr3, 4);
    double * darr12 = alc.allocate(3);


    //    darr[1] = 224;

//    alc.construct(darr,     2.0);
//    alc.construct(darr + 1, 3.0);

//    std::cout << darr[0] << std::endl;
//    std::cout << darr[1] << std::endl;

//    alc.destroy(darr);

//    alc.deallocate(darr, 2);


//    std::map<int, int>  standard_map;




    return 0;
}



// End of the file

