#include <QApplication>
#include <QSqlQuery>
#include <QSettings>
#include <QDir>

#include <iostream>
#include "Automaton.h"
#include "ElementaryAutomaton.h"
#include "GameOfLife.h"
#include "grid.h"
#include "randomGridGenerator.h"
#include "simulator.h"
#include "QuadLife.h"
#include "dbmanager.h"
#include "autocellElem.h"
#include "autocellGol.h"
#include "autocellquad.h"
#include "mainWindow.h"

DbManager dbTest;

using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        dbTest.createTables();

        QApplication app(argc, argv);
        MainWindow fenetrePrincipale;
        fenetrePrincipale.show();

        return app.exec();
    }
    catch(char const* e)
    {
        cout << e << endl;
    }
}
