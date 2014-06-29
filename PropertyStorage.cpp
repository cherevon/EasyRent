#include "PropertyStorage.h"

void PropertyStorage::saveWidgetSettings(QString aKey, QWidget *pwgt)
{
    QSettings Storage;

    Storage.beginGroup(aKey);
        Storage.setValue(StorageKeys::SIZE_KEY, pwgt->size());
        Storage.setValue(StorageKeys::POSITION_KEY, pwgt->pos());
        Storage.setValue(StorageKeys::STYLESHEET_KEY, pwgt->styleSheet());
        Storage.setValue(StorageKeys::WINDOWMAX_KEY, pwgt->isMaximized());
    Storage.endGroup();
}

/*=========================================================================================*/

void PropertyStorage::loadWidgetSettings(QString aKey, QWidget *pwgt)
{
    QSettings Storage;

    Storage.beginGroup(aKey);
        pwgt->resize(Storage.value(StorageKeys::SIZE_KEY).toSize());
        pwgt->move(Storage.value(StorageKeys::POSITION_KEY).toPoint());
        pwgt->setStyleSheet(Storage.value(StorageKeys::STYLESHEET_KEY).toString());
        bool maximized = Storage.value(StorageKeys::WINDOWMAX_KEY).toBool();
        if (maximized) pwgt->setWindowState(Qt::WindowMaximized);
    Storage.endGroup();
}

/*=========================================================================================*/

void PropertyStorage::saveString(QString aKey, QString str)
{
    QSettings Storage;

    Storage.setValue(aKey, str);
}

/*=========================================================================================*/

QString PropertyStorage::loadString(QString aKey)
{
    QSettings Storage;

    return Storage.value(aKey).toString();
}

/*=========================================================================================*/
