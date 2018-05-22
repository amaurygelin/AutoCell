#include "SymmetricHGridGenerator.h"
#include "stdlib.h"

void SymmetricHGridGenerator::generateGrid(Grid &grid)
{
    unsigned int r=grid.getNbRow();
    unsigned int c=grid.getNbCol();
    for (unsigned int i=0; i<(r/2); ++i)
    {
        for (unsigned int j=0; j<c; ++j)
        {
            int val = rand()% grid.getNbPossibleStates();
            grid.setCell(i,j,val);
            grid.setCell(r-i-1,j,val);
        }
    }
    if (r%2 == 1)
    {
        for (unsigned int j=0; j<c; ++j)
        {
            grid.setCell(r/2,j,rand()% grid.getNbPossibleStates());
        }
    }
}
