#include <iostream>
#include "Automaton.h"
#include "ElementaryAutomaton.h"
#include "GameOfLife.h"
#include "grid.h"
#include "randomGridGenerator.h"
#include "simulator.h"

using namespace std;

int main()
{
    try
    {
        /*
        ElementaryAutomaton ea(30);
        Automaton* pt1 = &ea;
        cout << *pt1 << endl;

        Grid g(1,5,2);
        Grid& grille = g;
        Grid& grille_dest = g;
        cout << grille << endl;
        RandomGridGenerator gridGeneratorA;
        grille.executeGridGenerator(gridGeneratorA);
        cout << grille << endl;

        ea.transition(grille, grille_dest);
        cout << grille << endl;


        cout << "Simulator" << endl;

        Simulator s(ea,g,3);
        s.run(2);
        s.displayGrids();

        */

        GameOfLife gol(3,2,3);
        Automaton* pt2 = &gol;
        cout << *pt2 << endl;


        Grid g(5,5,2);
        Grid& grille = g;
        Grid& grille_dest = g;
        //cout << grille << endl;
        RandomGridGenerator gridGeneratorA;
        grille.executeGridGenerator(gridGeneratorA);
        //cout << grille << endl;
        gol.transition(grille, grille_dest);
        cout << grille << endl;

        Simulator s(gol,g,3);
        s.run(2);
        s.displayGrids();

    }
    catch(char const* e)
    {
        cout << e << endl;
    }

    return 0;
}
