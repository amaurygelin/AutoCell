#include <iostream>
#include "AbstractGameOfLife.h"

using namespace std;

AbstractGameOfLife::AbstractGameOfLife(unsigned int dim, unsigned int nb_s, unsigned int nb_n, unsigned int min_n, unsigned int max_n)
    : Automaton(dim, nb_s), nb_neighbours_to_born(nb_n), min_neighbours_to_stay_alive(min_n), max_neighbours_to_stay_alive(max_n)
{

}

void AbstractGameOfLife::transition(const Grid& src, Grid& dest) const
{
    unsigned int state_cell(0);
    unsigned int nb_neighbours_alive(0);
    if( (src.getNbRow() != dest.getNbRow()) || (src.getNbCol() != dest.getNbCol()) )
    {
        throw "Grids with different number of columns and/or number of rows";
    }
    for(int i(0); i<src.getNbRow(); i++)
    {
        for(int j(0); j<src.getNbCol(); j++)
        {
            nb_neighbours_alive = countNeighboursAlive(src,i,j);
            if(state_cell = src.getCell(i,j)) //if the current cell is alive
            {
                if(nb_neighbours_alive>=min_neighbours_to_stay_alive && nb_neighbours_alive<=max_neighbours_to_stay_alive)
                    //stay alive
                    dest.setCell(i,j,state_cell);
                else
                    //die
                    dest.setCell(i,j,0);
            }
            else
            {
                if(nb_neighbours_alive==nb_neighbours_to_born)
                    //born
                    born(dest,i,j);
                else
                    //stay dead
                    dest.setCell(i,j,0);
            }
            nb_neighbours_alive = 0;
        }
    }
}

ostream& AbstractGameOfLife::display(ostream& f) const
{
    Automaton::display(f);
    f << "############ GAME OF LIFE" << endl;
    f << "Number of neighbours alive to born : " << nb_neighbours_to_born<< endl;
    f << "Minimum number of neighbours alive to stay alive : " << min_neighbours_to_stay_alive << endl;
    f << "Maximum number of neighbours alive to stay alive : " << max_neighbours_to_stay_alive << endl;
    return f;
}

unsigned int countNeighboursAlive(const Grid& g, int i, int j)
{
    unsigned int nb_neighbours_alive(0);

    if(j-1>=0) //if there is a neighbour on the left
        if(g.getCell(i,j-1)) //if he is alive
            nb_neighbours_alive++;
    if(j+1<=g.getNbCol()-1)
        if(g.getCell(i,j+1)) //right
            nb_neighbours_alive++;
    if(i-1>=0)
        if(g.getCell(i-1,j)) //top
            nb_neighbours_alive++;
    if(i+1<=g.getNbRow()-1)
        if(g.getCell(i+1,j)) //bottom
            nb_neighbours_alive++;
    if(i-1>=0 && j-1>=0)
        if(g.getCell(i-1,j-1)) //top left corner
            nb_neighbours_alive++;
    if(i-1>=0 && j+1<=g.getNbCol()-1)
        if(g.getCell(i-1,j+1)) //top right corner
            nb_neighbours_alive++;
    if(i+1<=g.getNbRow()-1 && j-1>=0)
        if(g.getCell(i+1,j-1)) //bottom left corner
            nb_neighbours_alive++;
    if(i+1<=g.getNbRow()-1 && j+1<=g.getNbCol()-1)
        if(g.getCell(i+1,j+1)) //bottom right corner
            nb_neighbours_alive++;

    return nb_neighbours_alive;
}

