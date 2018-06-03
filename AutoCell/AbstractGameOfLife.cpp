#include <iostream>
#include "AbstractGameOfLife.h"

using namespace std;

AbstractGameOfLife::AbstractGameOfLife(unsigned int dim, unsigned int nb_s, unsigned int nb_n, unsigned int min_n, unsigned int max_n)
    : Automaton(dim, nb_s), nb_neighbours_to_born(nb_n), min_neighbours_to_stay_alive(min_n), max_neighbours_to_stay_alive(max_n)
{

}

/*unsigned int AbstractGameOfLife::countNeighboursAlive(unsigned int i, unsigned int j) const
{
    int nb_neighbours_alive(0);

    if(j-1>=0 && getCell(i,j-1)) //if there is a neighbour on the left AND if he is alive
        nb_neighbours_alive++;
    if(j+1<=src.getNbCol && getCell(i,j+1)) //right
        nb_neighbours_alive++;
    if(i-1>=0 && getCell(i-1,j)) //top
        nb_neighbours_alive++;
    if(i+1<=src.getNbRow && getCell(i+1,j)) //bottom
        nb_neighbours_alive++;
    if(i-1>=0 && j-1>=0 && getCell(i-1,j-1)) //top left corner
        nb_neighbours_alive++;
    if(i-1>=0 && j+1<=src.getNbCol && getCell(i-1,j+1)) //top right corner
        nb_neighbours_alive++;
    if(i+1<=src.getNbRow && j-1>=0 && getCell(i+1,j-1)) //bottom left corner
        nb_neighbours_alive++;
    if(i+1<=src.getNbRow && j+1<=src.getNbCol && getCell(i+1,j+1)) //bottom right corner
        nb_neighbours_alive++;

    return nb_neighbours_alive;
}*/

ostream& AbstractGameOfLife::display(ostream& f) const
{
    Automaton::display(f);
    f << "############ GAME OF LIFE" << endl;
    f << "Number of neighbours alive to born : " << nb_neighbours_to_born<< endl;
    f << "Minimum number of neighbours alive to stay alive : " << min_neighbours_to_stay_alive << endl;
    f << "Maximum number of neighbours alive to stay alive : " << max_neighbours_to_stay_alive << endl;
    return f;
}

