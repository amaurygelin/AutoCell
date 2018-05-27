#include <iostream>
#include "Automaton.h"

using namespace std;

ostream& Automaton::display(ostream& f) const
{
    f << "############ AUTOMATON DISPLAY" << endl;
    f << "############ GENERAL CARACTERISTICS" << endl;
    f << "dimension : " << dimension << endl;
    f << "number of states : " << nb_states << endl;
    for(vector<int>::const_iterator it = states_list.begin(); it != states_list.end(); it++){
        f << "state number " << -distance(it, states_list.begin()) << " = " << *it << endl;
    }
    return f;
}

ostream& operator<<(ostream& f, Automaton const& a)
{
    return a.display(f);
}

