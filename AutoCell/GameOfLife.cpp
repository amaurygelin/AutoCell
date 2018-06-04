#include <iostream>
#include "GameOfLife.h"

using namespace std;

void GameOfLife::born(Grid& g, int i, int j) const
{
    g.setCell(i,j,1);
}
