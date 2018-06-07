#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "saveManager.h"
#include "ElementaryAutomaton.h"
#include "GameOfLife.h"
#include "QuadLife.h"


class DbManager final:public SaveManager
{
    private:
        QSqlDatabase db;
    public:
        DbManager();
        virtual ~DbManager();
        void createTables() const;
        void saveAutomaton(const ElementaryAutomaton &a) const override;
        void saveAutomaton(const GameOfLife &a) const override;
        void saveAutomaton(const QuadLife &a) const override;
        QSqlQuery loadElementaryAutomaton() const;
        QSqlQuery loadLifeAutomaton() const;
        QSqlQuery loadQuadLifeAutomaton() const;
};
#endif // DBMANAGER_H
