#ifndef PROPERTYSTORAGE_H
#define PROPERTYSTORAGE_H
#include <QWidget>
#include <QSettings>

namespace StorageKeys
{
    const QString SIZE_KEY          = "Size";               // размер
    const QString POSITION_KEY      = "Position";           // расположение на экране
    const QString STYLESHEET_KEY    = "CSS";                // CSS (каскадная таблица стилей)
    const QString WINDOWMAX_KEY     = "WindowMaximized";    // максимизировано ли окно
}

class PropertyStorage
{
private:
    PropertyStorage();
    PropertyStorage(const PropertyStorage& PS);

public:
    static void     saveWidgetSettings(QString aKey, QWidget *pwgt);    // сохранить настройки виджета
    static void     loadWidgetSettings(QString aKey, QWidget *pwgt);    // загрузить настройки виджета
    static void     saveString(QString aKey, QString str);              // сохранить строку
    static QString  loadString(QString aKey);                           // загрузить строку
};

#endif // PROPERTYSTORAGE_H
