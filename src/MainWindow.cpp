#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addUserTask(ui->actMyQueries);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::addUserTask(QAction* newTask)
{
    if (newTask != NULL)
    {
        QToolButton* taskButton = new QToolButton(this);
        taskButton->setIcon(newTask->icon());
        taskButton->setText(newTask->text());
//        taskButton->addAction(newTask);
        connect(taskButton, SIGNAL(clicked()), newTask, SLOT(trigger()));
        ui->layoutTasks->addWidget(taskButton);
    }
}
