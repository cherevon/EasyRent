#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QToolButton>
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>

#include "UserInterface.h"


/** Главное окно приложения
 */
class MainWindow : public QWidget, public UserInterface
{
    Q_OBJECT

private:
    /** Главный компоновщик элементов, располагаемых в окне
     */
    QHBoxLayout* fLayoutMain;
    /** Компоновщик для расположения доступных пользователю задач
     */
    QVBoxLayout* fLayoutTasks;
    /** Компоновщик для расположения виджетов запущенных задач
     */
    QStackedLayout* fLayoutWidgets;

public:
    explicit MainWindow(QWidget *parent = 0);
};


#endif // MAINWINDOW_H
