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

    ((matrix[23][24] = 555) = 227) = 99;
    std::cout << "99 = " << matrix[23][24] << std::endl;

    // Main task. Fill it up.
    auto up_mtx_diag = std::make_unique<InfiniteMatrix<int, 0>>();
    auto & mtx_diag = *up_mtx_diag;
    for (int k = 0; k <= 9; ++k) {
        mtx_diag[k][k] = k;
        mtx_diag[k][9 - k] = 9 - k;
    }

    // Print out submatrix
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            std::cout << mtx_diag[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "occupied cells number = " << mtx_diag.size() << std::endl;

//    for (auto item : mtx_diag) {

//    }

    return 0;
}


// End of the file
