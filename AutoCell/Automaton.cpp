#include <iostream>
#include "Automaton.h"

using namespace std;

ostream& Automaton::display(ostream& f) const
{
    f << "############ AUTOMATON DISPLAY" << endl;
    f << "############ GENERAL CARACTERISTICS" << endl;
    f << "dimension : " << dimension << endl;
    f << "number of states : " << nb_states << endl;
    for(unsigned int i=0; i<nb_states; i++){
        f << "state " << i << endl;
    }
    return f;
}

ostream& operator<<(ostream& f, Automaton const& a) //template method
{
    return a.display(f);
}

