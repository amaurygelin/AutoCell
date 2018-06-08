#ifndef DBMANAGER_H
#define DBMANAGER_H

///
/// \file dbManager.h
/// \brief Gestion de la sauvegarde à partir d'une base de données.
/// \author Loïc
///

#include "saveManager.h"


/// \class DbManager
/// \brief Classe de sauvegarde sur une base de données.
///
/// Fait l'interface entre l'application et une base de données SQLite.
///

class DbManager final:public SaveManager
{
    private:
        QSqlDatabase db; ///Une base de données SQLite
    public:
        /// \brief Constructeur.
        ///
        /// Le constructeur de DbManager permet la connexion à la base de données, et sa création le cas échéant.
        DbManager();
        /// \brief Destructeur.
        ///
        /// Le destructeur de DbManager engendre la déconnexion à la base de données.
        virtual ~DbManager();
        /// \brief Création des tables de la base de données.
        ///
        /// Permet, s'ils n'existent pas, la création des tables de la base de données.
        void createTables() const;
        /// \brief Sauvegarde d'un automate élémentaire.
        ///
        /// Permet la sauvegarde d'un automate élémentaire.
        ///
        /// \param a : un automate élémentaire qui ne sera pas modifié.
        void saveAutomaton(const ElementaryAutomaton &a) const override;
        /// \brief Sauvegarde d'un automate jeu de la vie.
        ///
        /// Permet la sauvegarde d'un automate jeu de la vie.
        ///
        /// \param a : un automate jeu de la vie qui ne sera pas modifié.
        void saveAutomaton(const GameOfLife &a) const override;
        /// \brief Sauvegarde d'un automate QuadLife.
        ///
        /// Permet la sauvegarde d'un automate QuadLife.
        ///
        /// \param a : un automate QuadLife qui ne sera pas modifié.
        void saveAutomaton(const QuadLife &a) const override;
        /// \brief Chargement des automates élémentaires.
        ///
        /// Permet de récupérer tous les automates élémentaires dans la base de données.
        ///
        /// \return La liste des automates élémentaires présents dans la base de données.
        QSqlQuery loadElementaryAutomaton() const;
        /// \brief Chargement des automates jeu de la vie.
        ///
        /// Permet de récupérer tous les automates jeu de la vie dans la base de données.
        ///
        /// \return La liste des automates jeu de la vie présents dans la base de données.
        QSqlQuery loadLifeAutomaton() const;
        /// \brief Chargement des automates QuadLife.
        ///
        /// Permet de récupérer tous les automates QuadLife dans la base de données.
        ///
        /// \return La liste des automates QuadLife présents dans la base de données.
        QSqlQuery loadQuadLifeAutomaton() const;
};
#endif // DBMANAGER_H
