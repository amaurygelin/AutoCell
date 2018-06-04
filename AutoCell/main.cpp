#include <iostream>
#include "Automaton.h"
#include "ElementaryAutomaton.h"
#include "GameOfLife.h"
#include "grid.h"
#include "randomGridGenerator.h"
#include "simulator.h"
#include "QuadLife.h"

using namespace std;

int main()
{
    try
    {
        /*ElementaryAutomaton ea(30);
        Automaton* pt1 = &ea;
        cout << *pt1 << endl;

        Grid g(1,11,2);
        Grid& grille = g;
        Grid& grille_dest = g;
        cout << "Grille init" << endl;
        cout << grille << endl;
        g.setCell(0,5,1);
        cout << g << endl;

        cout << "Simulator" << endl;
        Simulator s(ea,g,5);
        s.run(4);
        s.displayGrids();*/


        /*GameOfLife gol(3,2,3);
        Automaton* pt2 = &gol;
        cout << *pt2 << endl;

        Grid g(3,3,2);
        Grid& grille = g;
        Grid& grille_dest = g;
        cout << "Grille init" << endl;
        cout << grille << endl;
        RandomGridGenerator gridGeneratorA;
        grille.executeGridGenerator(gridGeneratorA);

        cout << "Simulation : " << endl;
        Simulator s(gol,grille,3);
        s.run(2);
        s.displayGrids();*/


        QuadLife ql(3,2,3);

        Grid g(5,5,5);
        Grid& grille = g;
        Grid& grille_dest = g;
        cout << "Grille init" << endl;
        cout << grille << endl;
        RandomGridGenerator gridGeneratorA;
        grille.executeGridGenerator(gridGeneratorA);

        cout << "Simulation : " << endl;
        Simulator s(ql,grille,3);
        s.run(2);
        s.displayGrids();

    }
    catch(char const* e)
    {
        cout << e << endl;
    }

    return 0;
}
