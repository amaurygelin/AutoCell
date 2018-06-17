#ifndef SAVEUICONTEXT_H
#define SAVEUICONTEXT_H

///
/// \file saveuicontext.h
/// \brief Sauvegarde du contexte.
/// \author Waël
///

#include <QVariant>
#include <QString>

/// \brief Sauvegarde dans le contexte.
/// \param key : l'attribut.
/// \param value : sa valeur.
void saveUiContext(const QString &key, const QVariant &value);
/// \brief Charge depuis le contexte.
/// \param key : l'attribut.
/// \param value : sa valeur.
/// \return Le paramètre du contexte.
QVariant loadUiContext(const QString &key, const QVariant &defaultValue);

#endif // SAVEUICONTEXT_H
