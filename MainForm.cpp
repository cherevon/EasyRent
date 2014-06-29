#include "MainForm.h"

extern QString PQFilePath;

/*==========================================================================================*/

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent)
{
    setParent(parent);
    MdiArea = new QMdiArea();
    MdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    MdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    setCentralWidget(MdiArea);

    QMenu *MenuPQ = new QMenu("Приоритетные запросы");
    QAction *ShowPQ = new QAction("Показать", MenuPQ);
    QAction *SearchPQ = new QAction("Найти совпадения", MenuPQ);

    MenuPQ->setStyleSheet("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(255, 248, 0, 255), stop:0.5 rgba(0, 255, 158, 255), stop:1 rgba(187, 255, 0, 255));");

    ShowPQ->setToolTip("Показать все приоритетные запросы");

    MenuPQ->addAction(ShowPQ);
    MenuPQ->addAction(SearchPQ);


    menuBar()->addMenu(MenuPQ);
    connect(ShowPQ, SIGNAL(triggered()), SLOT(triggeredShowPQ()));
    //connect(this, SIGNAL(), this, SLOT(saveSettings()));
    //connect(ShowOQ, SIGNAL(triggered), SLOT());
    //menuBar()->setStyleSheet("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(255, 248, 0, 255), stop:0.511364 rgba(0, 255, 158, 255), stop:1 rgba(187, 255, 0, 255));");

    this->loadSettings();
    FormPQ = NULL;
}

/*==========================================================================================*/

void MainForm::triggeredShowPQ()
// открыть окно приоритетных запросов
{
    // если окно еще не создано, то создать его и разместить в MDI-области
    if (!FormPQ)
    {
        FormPQ = new FormPriorityShow(this);
        MdiArea->setActiveSubWindow(MdiArea->addSubWindow(FormPQ));
    }

    // показать окно "Приоритетные запросы"
    FormPQ->show();
}

/*==========================================================================================*/

void MainForm::destroyedFormPriorityShow()
{
    if (FormPQ) FormPQ = NULL;
}

/*==========================================================================================*/

void MainForm::loadSettings()
{
    PropertyStorage::loadWidgetSettings("MainForm", this);
}

/*==========================================================================================*/

void MainForm::saveSettings()
{
    PropertyStorage::saveWidgetSettings("MainForm", this);
}

/*==========================================================================================*/

void MainForm::closeEvent(QCloseEvent* e)
{
    saveSettings();

    e->accept();
}
