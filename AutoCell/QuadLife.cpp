#include <iostream>
#include "QuadLife.h"

using namespace std;

void QuadLife::born(Grid& g, int i, int j) const
{
    vector<unsigned int> states_neighbours(8,0);
    unsigned int state_cell;

    //order of the neighbours : top left, top, top right, left, right, bottom left, bottom, bottom right
    if(j-1>=0)
        if(state_cell = g.getCell(i,j-1)) //left
            {states_neighbours[3] = state_cell; cout << "true";}
    if(j+1<=g.getNbCol()-1)
        if(state_cell = g.getCell(i,j+1)) //right
            {states_neighbours[4] = state_cell; cout << "true";}
    if(i-1>=0)
        if(state_cell = g.getCell(i-1,j)) //top
            {states_neighbours[1] = state_cell; cout << "true";}
    if(i+1<=g.getNbRow()-1)
        if(state_cell = g.getCell(i+1,j)) //bottom
            {states_neighbours[6] = state_cell; cout << "true";}
    if(i-1>=0 && j-1>=0)
        if(state_cell = g.getCell(i-1,j-1)) //top left corner
            {states_neighbours[0] = state_cell; cout << "true";}
    if(i-1>=0 && j+1<=g.getNbCol()-1)
        if(state_cell = g.getCell(i-1,j+1)) //top right corner
            {states_neighbours[2] = state_cell; cout << "true";}
    if(i+1<=g.getNbRow()-1 && j-1>=0)
        if(state_cell = g.getCell(i+1,j-1)) //bottom left corner
            {states_neighbours[5] = state_cell; cout << "true";}
    if(i+1<=g.getNbRow()-1 && j+1<=g.getNbCol()-1)
        if(state_cell = g.getCell(i+1,j+1)) //bottom right corner
            {states_neighbours[7] = state_cell; cout << "true";}

    unsigned int a(0),b(0),c(0); //the states of the three neighbours that allowed the birth
    unsigned int counter(0);

    /*for(int k=0;k<7;k++)
    {
        cout << states_neighbours[k] << endl;
    }*/

    while(states_neighbours[counter]==0)
    {
        counter++;
    }
    a = states_neighbours[counter++];
    while(states_neighbours[counter]==0)
    {
        counter++;
    }
    b = states_neighbours[counter++];
    while(states_neighbours[counter]==0)
    {
        counter++;
    }
    c = states_neighbours[counter];

    /*cout << "a = " << a << endl;
    cout << "b = " << a << endl;
    cout << "c = " << a << endl;*/
    if(a!=b && a!=c && c!=b) //if every states states are different, the 4th other state is chosen
    {
        state_cell = 1;
        while(state_cell==a || state_cell==b || state_cell==c)
        {
            state_cell++;
        }
        g.setCell(i,j,state_cell);
    }
    else //if some states are the same, the most viewed one is chosen
    {
        if(a==b)
            state_cell=a;
        else if(a==c)
            state_cell=a;
        else if(b==c)
            state_cell=b;
        g.setCell(i,j,state_cell);
    }
}
