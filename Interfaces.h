#ifndef INTERFACES_H
#define INTERFACES_H

#include <QObjectList>

// интерфейс для обЪектов, которые могут извлекать свои элементы управления на главное окно
class IControlExtractor
{
public:
    // получение перечня элементов, которые неободимо расположить в главном окне
    virtual QObjectList extractControls() = 0;
};


// интерфейс главного окна приложения
class IMainWindow
{
public:
    // активация указанного окна
    virtual void activateWindow(QWidget* pwgt) = 0;
    // добавление пользовательского окна на главное окно
    virtual void addUserWindow(QWidget* pwgt, const bool needActivate = true) = 0;
    // удаление пользовательского окна с главного окна
    virtual void removeUserWindow(QWidget* pwgt) = 0;
    // добавление действия на панель инструментов
    virtual void addToolbarAction(QAction* pAct) = 0;
    // удаление действия с панели инструментов
    virtual void removeToolbarAction(QAction* pAct) = 0;
};

#endif // INTERFACES_H
