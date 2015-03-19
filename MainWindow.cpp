#include "MainWindow.h"
#include "ui_MainWindow.h"

extern QList<PriorityQuery*> PQs;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateToday->setDateTime(QDateTime::currentDateTime());

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
    addUserWindow(formPQs);
}

/*======================================================================================================================*/

void MainWindow::extractWindowControls(IControlExtractor *pwgt)
// extracts controls from pwgt
{
    QObjectList extractedControls = pwgt->extractControls();

    // place all actions on toolbar
    QObjectList::const_iterator extrControl;
    for(extrControl = extractedControls.cbegin(); extrControl != extractedControls.cend(); ++extrControl)
    {
        QAction* pAct = dynamic_cast<QAction*>(*extrControl);
        if (pAct)
            addToolbarAction(pAct);
    }
}

/*======================================================================================================================*/

void MainWindow::addUserWindow(QWidget *pwgt)
// insert new widget into QTabWidget
{
    ui->tabWidget->addTab(pwgt, pwgt->windowTitle());
    // remember new window as currently opened and refresh Window menu
    fOpenedWindows.push_back(pwgt);

    // extract controls from window
    IControlExtractor* controlExtractor = dynamic_cast<IControlExtractor*>(pwgt);
    if (controlExtractor)
        extractWindowControls(controlExtractor);
}

/*======================================================================================================================*/

void MainWindow::addToolbarAction(QAction *pAct)
// adds new action to the Toolbar
{
    ui->toolBar->insertAction(*ui->toolBar->actions().end(), pAct);
}

/*======================================================================================================================*/
