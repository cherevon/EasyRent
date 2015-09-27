#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSet>
#include "Interfaces.h"
#include <QQuickView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public IMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /*IMainForm*/
    // активация указанного окна
    void activateWindow(QWidget* pwgt);
    // добавление пользовательского окна на главное окно
    void addUserWindow(QWidget* pwgt, const bool needActivate = true);
    // удаление пользовательского окна с главного окна
    void removeUserWindow(QWidget* pwgt);
    // добавление действия на панель инструментов
    void addToolbarAction(QAction* pAct);
    // удаление действия с панели инструментов
    void removeToolbarAction(QAction* pAct);

private:
    QQuickView* ui; // пользовательский интерфейс окна
    QList<QWidget*> fOpenedWindows; // список открытых в данный момент окон
    QObjectList fExtractedControls; // список извлеченных из пользовательского окна элементов управления

    // извлечение элементов управления из виджета
    void extractControls(IControlExtractor* pwgt);
    // получение порядкового номера вкладки по указателю на виджет
    int getTabNumByWidget(QWidget* pwgt);

protected:
    virtual void connectEvents(); // connecting signals and slots of this window
    // удаление всех элементов управления, извлеченных из пользовательского окна
    virtual void removeExtractedControls();
};

#endif // MAINWINDOW_H
