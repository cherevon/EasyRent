#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fillStatusBar();
    connectEvents();
}

/*======================================================================================================================*/

MainWindow::~MainWindow()
{
    delete ui;
}

/*======================================================================================================================*/

void MainWindow::fillStatusBar()
// fill status bar with widgets
{
    ui->dateToday->adjustSize();
    ui->statusbar->addWidget(ui->dateToday);
}

/*======================================================================================================================*/

void MainWindow::connectEvents()
// connecting signals and slots of this window
{
    connect(ui->actShowPQs, SIGNAL(triggered()), SLOT(showPQs()));
}

/*======================================================================================================================*/

void MainWindow::showPQs()
// open the window with user`s priority queries
{
    FormPriorityShow *formPQs = new FormPriorityShow();
    addWindow(formPQs);
}

/*======================================================================================================================*/

void MainWindow::addWindow(QWidget *pwgt)
// insert new widget into QTabWidget
{
    ui->tabWidget->addTab(pwgt, pwgt->windowTitle());
    // remember new window as currently opened and refresh Window menu
    fOpenedWindows.push_back(pwgt);
}

/*======================================================================================================================*/

void MainWindow::loadPQs()
// load priority queries from file
{
    QFile PQFile("C:\\Projects\\priorities.pq");
    if (PQFile.open(QIODevice::ReadOnly))
    {
        PriorityQuery* NewPQ;
        while (!PQFile.atEnd())
        {
            NewPQ = new PriorityQuery();
            NewPQ->readBinary(PQFile);
            PQs.push_back(NewPQ);
        }
        PQFile.close();
    }
}

/*======================================================================================================================*/

void MainWindow::savePQs()
// save priority queries to file
{

}

/*======================================================================================================================*/
