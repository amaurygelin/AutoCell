#include "SymmetricDGridGenerator.h"
#include "stdlib.h"

void SymmetricDGridGenerator::generateGrid(Grid &grid)
{
    unsigned int r=grid.getNbRow();
    unsigned int c=grid.getNbCol();
    if(c != r)
    {
        throw ("Error: not a square grid.");
    }
    for (unsigned int i=0; i<r; ++i)
    {
       for (unsigned int j=0; j<c; ++j)
       {
           int val = rand()% grid.getNbPossibleStates();
           grid.setCell(i,j,val);
           grid.setCell(j,i,val);
       }
   }
}
