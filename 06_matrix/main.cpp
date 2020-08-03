#include "infinite_matrix.h"
#include "effective_cell.h"
#include "infinite_row.h"
#include <iostream>
#include <cassert>

int main(int argc, char * argv []) {

    InfiniteMatrix<int, -1> matrix;
    assert(matrix.size() == 0);

    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0);

    matrix[100][100] = 314;
    assert(314 == matrix[100][100]);
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);

//    for (auto c : matrix) {

//    }

    ((matrix[23][24] = 555) = 227) = 99;
    std::cout << "99 = " << matrix[23][24] << std::endl;

    return 0;
}


// End of the file
