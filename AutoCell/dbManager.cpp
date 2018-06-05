#include "dbManager.h"
#include <iostream>
#include <QString>
#include <QSqlQuery>

DbManager::DbManager(): SaveManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("automatonDB");
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();
        if (ok)
            std::cout<<"Connexion établie \n";
        else
            std::cout<<"Erreur de connexion \n";
}

DbManager::~DbManager()
{
    db.close();
    std::cout<<"Déconnexion à la base de données \n";
}

void DbManager::createTables()
{
    QSqlQuery query;
    query.exec("CREATE TABLE automaton_simple("
        "num INT PRIMARY KEY,"
        "dimension INT NOT NULL,"
        "nb_states INT NOT NULL,"
        "rule_num INT NOT NULL,"
        "rule_bits VARCHAR(9) NOT NULL)");
    query.exec("CREATE TABLE automaton_life("
        "num INT PRIMARY KEY,"
        "dimension INT NOT NULL,"
        "nb_states INT NOT NULL,"
        "min_neighbours INT NOT NULL,"
        "max_neighbours INT NOT NULL)");
}

void DbManager::saveAutomaton(const ElementaryAutomaton &) {
    std::cout << "Test 1" << std::endl;
}

void DbManager::saveAutomaton(const GameOfLife &) {
    std::cout << "Test 2" << std::endl;
}

void DbManager::saveAutomaton(const QuadLife &) {
    std::cout << "Test 3" << std::endl;
}

/*void AbstractDbManager::sauvegardeAutomate()
{
    QSqlQuery query;
    query.exec("INSERT INTO automaton_simple(dimension, nb_states, rule_num, rule_bits)"
        "VALUES (1,5,10,'10100001')");
}
*/
