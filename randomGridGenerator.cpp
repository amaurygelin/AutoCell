#include "randomGridGenerator.h"
#include "stdlib.h"

void RandomGridGenerator::generateGrid(Grid &grid)
{
    for (unsigned int i=0; i<grid.getNbRow(); ++i)
    {
        for (unsigned int j=0; j<grid.getNbCol(); j++)
        {
            grid.setCell(i,j,rand()% grid.getNbPossibleStates());
        }
    }
}
