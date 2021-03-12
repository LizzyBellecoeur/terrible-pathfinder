#include "pathfind.h"

Cell::Cell(unsigned int a, unsigned int b):
y(a),
x(b),
ranking(0)
{}

void Cell::rankCell(const Cell& tagetCell)
{
    ranking = sqrt((x-tagetCell.x)*(x-tagetCell.x)
                  +(y-tagetCell.y)*(y-tagetCell.y));
}

std::string* createMatrix(unsigned int rows)
{
    return new std::string[rows];
}

void fillMatrix(std::string* matrix, unsigned int rows)
{
    for(auto i = 0; i < rows; i++)
        std::getline(std::cin, matrix[i]);
}

void printMatrix(const std::string* matrix, unsigned int rows)
{
    for(auto i = 0; i < rows; i++)
        std::cout << matrix[i] << std::endl;
    std::cout << std::endl;
}

void destroyMatrix(std::string* matrix)
{
    delete [] matrix;
}

void getValidMoves(const std::string* matrix, const Cell& origin, std::vector<Cell*>& moveVector)
{
    char currentChar;
    for(short i = -1; i <= 1; i++)
        for(short j = -1; j <= 1; j++)
        {
            currentChar = matrix[origin.y+i][origin.x+j];
            if(currentChar == ' ' || currentChar == 'E')
                moveVector.push_back(new Cell(origin.y+i, origin.x+j));
        }
}

void destroyMoveVector(std::vector<Cell*>& moveVector)
{
    for(Cell* i : moveVector)
        delete i;
}

void getCellOfChar(const std::string* matrix, unsigned int rows, char target, Cell& cell)
{
    unsigned int matWidth = matrix[0].length();
    for(auto i = 0; i < rows; i++)
        for(auto j = 0; j < matWidth; j++)
            if(matrix[i][j] == target)
            {
                cell.y = i;
                cell.x = j;
                return;
            }
}

void rankCells(std::vector<Cell*>& moveVector, const Cell& targetCell)
{
    for(Cell* i : moveVector)
        i->rankCell(targetCell);
}

bool solve(std::string* matrix, const Cell& currentSpace, const Cell& target)
{
    std::vector<Cell*> moveVector;
    char& currentChar = matrix[currentSpace.y][currentSpace.x];
    
    if(currentChar == 'E')
        return true;
    
    if(currentChar != 'N')
        currentChar = '@';

    getValidMoves(matrix, currentSpace, moveVector);
    rankCells(moveVector, target);

    std::sort(moveVector.begin(), moveVector.end(),
    [](Cell* a, Cell* b)
    {
        return a->ranking < b->ranking;
    });

    for(Cell* i : moveVector)
        if(solve(matrix, *i, target))
        {
            destroyMoveVector(moveVector);
            return true;
        }

    if(currentChar != 'N')
        currentChar = ' ';

    destroyMoveVector(moveVector);

    return false;
}