#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

///
/// \file saveManager.h
/// \brief Gestion de la sauvegarde
/// \author Loïc
///

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>

class ElementaryAutomaton;
class GameOfLife;
class QuadLife;

/// \class SaveManager
/// \brief Classe de sauvegarde.
///
/// Fait l'interface entre l'architecture de l'application et la sauvegarde externalisée de données.
/// La classe sert aussi à implanter le patron de conception visiteur, permettant d'éviter une conversion de type lors de la sauvegarde d'un automate.
///

class SaveManager
{
    public:
        /// \brief Constructeur.
        /// Constructeur de SaveManager.
        SaveManager(){}
        /// \brief Destructeur.
        /// Destructeur de SaveManager.
        virtual ~SaveManager();
        /// \brief Sauvegarde d'un automate élémentaire.
        ///
        /// Permet la sauvegarde d'un automate élémentaire.
        ///
        /// \param a : un automate élémentaire qui ne sera pas modifié.
        virtual void saveAutomaton(const ElementaryAutomaton &a) const=0;
        /// \brief Sauvegarde d'un automate jeu de la vie.
        ///
        /// Permet la sauvegarde d'un automate jeu de la vie.
        ///
        /// \param a : un automate jeu de la vie qui ne sera pas modifié.
        virtual void saveAutomaton(const GameOfLife &a) const=0;
        /// \brief Sauvegarde d'un automate QuadLife.
        ///
        /// Permet la sauvegarde d'un automate QuadLife.
        ///
        /// \param a : un automate QuadLife qui ne sera pas modifié.
        virtual void saveAutomaton(const QuadLife &a) const=0;
};

#endif // SAVEMANAGER_H
