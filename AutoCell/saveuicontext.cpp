#include "saveuicontext.h"
#include <QSettings>
#include <QDir>

void saveUiContext(const QString &key, const QVariant &value){
    QString qsname = "settings.ini";
    qsname = QDir::currentPath()+"/"+qsname;
    QSettings settings(qsname, QSettings::IniFormat);
    settings.setValue(key, value);
}

QVariant loadUiContext(const QString &key, const QVariant &defaultValue){
    QString qsname = "settings.ini";
    qsname = QDir::currentPath()+"/"+qsname;
    QSettings settings(qsname, QSettings::IniFormat);
    QVariant value = settings.value(key, defaultValue);
    return value;
}
