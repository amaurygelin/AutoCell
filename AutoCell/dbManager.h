#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "saveManager.h"

class DbManager final:public SaveManager
{
    private:
        QSqlDatabase db;
    public:
        DbManager();
        virtual ~DbManager();
        void createTables();
        void saveAutomaton(const ElementaryAutomaton &a) override;
        void saveAutomaton(const GameOfLife &a) override;
        void saveAutomaton(const QuadLife &a) override;
};
#endif // DBMANAGER_H
