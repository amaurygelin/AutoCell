#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

class ElementaryAutomaton;
class GameOfLife;
class QuadLife;

class SaveManager
{
    public:
        SaveManager(){}
        virtual ~SaveManager();
        virtual void saveAutomaton(const ElementaryAutomaton &a) const=0;
        virtual void saveAutomaton(const GameOfLife &a) const=0;
        virtual void saveAutomaton(const QuadLife &a) const=0;
};

#endif // SAVEMANAGER_H
