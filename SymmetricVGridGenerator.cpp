#include "SymmetricVGridGenerator.h"
#include "stdlib.h"

void SymmetricVGridGenerator::generateGrid(Grid &grid)
{
    unsigned int r=grid.getNbRow();
    unsigned int c=grid.getNbCol();
    for (unsigned int i=0; i<r; ++i)
    {
        for (unsigned int j=0; j<(c/2); ++j)
        {
            int val = rand()% grid.getNbPossibleStates();
            grid.setCell(i,j,val);
            grid.setCell(i,c-j-1,val);
        }
    }
    if (c%2 == 1)
    {
        for (unsigned int i=0; i<r; ++i)
        {
            grid.setCell(i,c/2,rand()% grid.getNbPossibleStates());
        }
    }
}
