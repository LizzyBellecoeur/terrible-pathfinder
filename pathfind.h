
#ifndef PATHFIND_H
#define PATHFIND_H

#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

struct Cell
{
    unsigned int x, y;
    float ranking;
    Cell(unsigned int, unsigned int);
    Cell(){} //the `fuck off compiler` constructor.
    void rankCell(const Cell&);
    bool operator<(const Cell&) const;
    bool operator>(const Cell&) const;
};

std::string* createMatrix(unsigned int);

void fillMatrix(std::string*, unsigned int);

void printMatrix(const std::string*, unsigned int);

void destroyMatrix(std::string*);

void getCellOfChar(const std::string*, unsigned int, char target, Cell&);

void getValidMoves(const std::string*, const Cell&, std::vector<Cell*>&);

void destroyMoveVectors(std::vector<Cell*>&);

void rankCells(std::vector<Cell*>&, const Cell&);

bool solve(std::string*, const Cell&, const Cell&);

#endif