#include "MainWindow.h"
#include "ProgressButton.h"


MainWindow::MainWindow(QWidget *parent): QWidget(parent), UserInterface()
{
    // определяем основной компоновщик элементов формы
    fLayoutMain = new QHBoxLayout();
    setLayout(fLayoutMain);

    // располагаем область для отображения доступных пользователю задач
    fLayoutTasks = new QVBoxLayout();
    fLayoutTasks->addStretch(1);
    fLayoutMain->addLayout(fLayoutTasks);

    // располагаем область для отображения виджетов активной задачи
    fLayoutWidgets = new QStackedLayout();
    fLayoutMain->addLayout(fLayoutWidgets, 1);
}
