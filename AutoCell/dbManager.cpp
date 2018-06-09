#include "dbManager.h"
#include <iostream>
#include <QString>
#include "ElementaryAutomaton.h"
#include "GameOfLife.h"
#include "QuadLife.h"

DbManager::DbManager(): SaveManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("autoCellDb.db");
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();
        if (ok)
            std::cout<<"Connexion...\n";
        else
            std::cout<<"Erreur de connexion\n";
}

DbManager::~DbManager()
{
    db.close();
    std::cout<<"Deconnexion...\n";
}

void DbManager::createTables() const
{
    QSqlQuery query;
    query.exec("CREATE TABLE automaton_simple("
        "num INTEGER PRIMARY KEY,"
        "rule_num INTEGER NOT NULL)");
    query.exec("CREATE TABLE automaton_life("
        "num INTEGER PRIMARY KEY,"
        "nb_neighbours_born INTEGER NOT NULL,"
        "min_neighbours_alive INTEGER NOT NULL,"
        "max_neighbours_alive INTEGER NOT NULL)");
    query.exec("CREATE TABLE automaton_quadlife("
        "num INTEGER PRIMARY KEY,"
        "nb_neighbours_born INTEGER NOT NULL,"
        "min_neighbours_alive INTEGER NOT NULL,"
        "max_neighbours_alive INTEGER NOT NULL)");
}

void DbManager::saveAutomaton(const ElementaryAutomaton & a) const {
    QSqlQuery query;
    query.prepare("INSERT INTO automaton_simple (rule_num) "
                  "VALUES (:rule_num)");
    query.bindValue(":rule_num", a.getRuleNum());
    query.exec();
}

void DbManager::saveAutomaton(const GameOfLife & a) const {
    QSqlQuery query;
    query.prepare("INSERT INTO automaton_life (nb_neighbours_born, min_neighbours_alive, max_neighbours_alive) "
                    "VALUES (:nb_neighbours_born, :min_neighbours_alive, :max_neighbours_alive)");
    query.bindValue(":nb_neighbours_born", a.getNbNeighboursToBorn());
    query.bindValue(":min_neighbours_alive", a.getMinNeighboursToStayAlive());
    query.bindValue(":max_neighbours_alive", a.getMaxNeighboursToStayAlive());
    query.exec();
}

void DbManager::saveAutomaton(const QuadLife & a) const {
    QSqlQuery query;
    query.prepare("INSERT INTO automaton_quadlife (nb_neighbours_born, min_neighbours_alive, max_neighbours_alive) "
                    "VALUES (:nb_neighbours_born, :min_neighbours_alive, :max_neighbours_alive)");
    query.bindValue(":nb_neighbours_born", a.getNbNeighboursToBorn());
    query.bindValue(":min_neighbours_alive", a.getMinNeighboursToStayAlive());
    query.bindValue(":max_neighbours_alive", a.getMaxNeighboursToStayAlive());
    query.exec();
}

QSqlQuery DbManager::loadElementaryAutomaton() const
{
    QSqlQuery query;
    query.prepare("SELECT rule_num "
                  "FROM automaton_simple");
    query.exec();
    return query;
}
QSqlQuery DbManager::loadLifeAutomaton() const
{
    QSqlQuery query;
    query.prepare("SELECT nb_neighbours_born, min_neighbours_alive, max_neighbours_alive "
                  "FROM automaton_life");
    query.exec();
    return query;
}
QSqlQuery DbManager::loadQuadLifeAutomaton() const
{
    QSqlQuery query;
    query.prepare("SELECT nb_neighbours_born, min_neighbours_alive, max_neighbours_alive "
                  "FROM automaton_quadlife");
    query.exec();
    return query;
}
