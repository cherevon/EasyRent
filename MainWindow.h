#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSet>
#include "FormPriorityShow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addWindow(QWidget *pwgt); // insert new widget into QTabWidget

private:
    QList<QWidget*> fOpenedWindows; // a list of all windows which are currently opened
    Ui::MainWindow *ui;

protected:
    virtual void connectEvents(); // connecting signals and slots of this window
    virtual void fillStatusBar(); // fill status bar with widgets

public slots:
    void showPQs(); // open the window with user`s priority queries
    void loadPQs(); // load priority queries from file
    void savePQs(); // save priority queries to file
};

#endif // MAINWINDOW_H
