#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSet>
#include "FormPriorityShow.h"
#include "Interfaces.h"

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
    void addUserWindow(QWidget* pwgt);
    void addToolbarAction(QAction* pAct);


private:
    QList<QWidget*> fOpenedWindows; // a list of all windows which are currently opened
    Ui::MainWindow *ui;

    void extractWindowControls(IControlExtractor* pwgt); // extracts controls from pwgt

protected:
    virtual void connectEvents(); // connecting signals and slots of this window
    virtual void fillStatusBar(); // fill status bar with widgets

public slots:
    void showPQs(); // open the window with user`s priority queries
};

#endif // MAINWINDOW_H
