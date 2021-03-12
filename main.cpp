#include "pathfind.h"
#include <iostream>
#include <string>

int main()
{
    Cell startCell, endCell;
    unsigned int rows = 1;
    std::string* matrix;
    while(1)
    {
        std::cin >> rows;
        std::cin.ignore();
        if(rows == 0)
            break;
        matrix = createMatrix(rows);
        fillMatrix(matrix, rows);
        getCellOfChar(matrix, rows, 'N', startCell);
        getCellOfChar(matrix, rows, 'E', endCell);
        solve(matrix, startCell, endCell);
        printMatrix(matrix, rows);
        destroyMatrix(matrix);
        std::cin.ignore();
    }
}