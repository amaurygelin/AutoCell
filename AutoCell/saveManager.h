#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <QApplication>
#include <QSqlDatabase>

class ElementaryAutomaton;
class GameOfLife;
class QuadLife;

class SaveManager
{
    public:
        SaveManager(){}
        virtual ~SaveManager();
        virtual void saveAutomaton(const ElementaryAutomaton &a)=0;
        virtual void saveAutomaton(const GameOfLife &a)=0;
        virtual void saveAutomaton(const QuadLife &a)=0;
        //void chargementAutomate();
};

#endif // SAVEMANAGER_H
