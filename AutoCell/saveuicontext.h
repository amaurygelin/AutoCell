#ifndef SAVEUICONTEXT_H
#define SAVEUICONTEXT_H

#include <QVariant>
#include <QString>

void saveUiContext(const QString &key, const QVariant &value);

QVariant loadUiContext(const QString &key, const QVariant &defaultValue);

#endif // SAVEUICONTEXT_H
