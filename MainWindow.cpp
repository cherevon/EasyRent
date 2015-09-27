#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    ui = new QQuickView();
    QWidget *wgtQuick = QWidget::createWindowContainer(ui, this);
    setCentralWidget(wgtQuick);
    ui->setResizeMode(QQuickView::SizeRootObjectToView);
    ui->setSource(QUrl("qrc:/MainWindow.qml"));

    fExtractedControls = QObjectList();

    // соединяем сигналы со слотами
    connectEvents();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connectEvents()
// connecting signals and slots of this window
{
//    connect(ui->tabWidget, SIGNAL(currentChanged(int)), SLOT(activeWindowChanged()));
}


// извлечение элементов управления из виджета
void MainWindow::extractControls(IControlExtractor *pwgt)
{
    fExtractedControls = pwgt->extractControls();

    // place all actions on toolbar
    QObjectList::const_iterator extrControl;
    for(extrControl = fExtractedControls.cbegin(); extrControl != fExtractedControls.cend(); ++extrControl)
    {
//        QAction* pAct = dynamic_cast<QAction*>(*extrControl);
//        if (pAct)
//            addToolbarAction(pAct);
    }
}


void MainWindow::addUserWindow(QWidget *pwgt, const bool needActivate)
// insert new widget into QTabWidget
{
    // remember new window as currently opened and refresh Window menu
    fOpenedWindows.push_back(pwgt);

    // отображаем компонент на новой вкладке
//    ui->tabWidget->addTab(pwgt, pwgt->windowTitle());

    // активируем только что добавленное окно, если это необходимо
    if (needActivate)
        activateWindow(pwgt);
}


// активация указанного окна
void MainWindow::activateWindow(QWidget* pwgt)
{
    // удаляем извлеченные ранее элементы управления
    removeExtractedControls();

    // extract controls from window
    IControlExtractor* controlExtractor = dynamic_cast<IControlExtractor*>(pwgt);
    if (controlExtractor != NULL)
        extractControls(controlExtractor);

//    ui->tabWidget->setCurrentWidget(pwgt);
}


// получение порядкового номера вкладки по указателю на виджет
int MainWindow::getTabNumByWidget(QWidget* pwgt)
{
//    if (ui->tabWidget->count() > 0)
//    {
//        int wgtNum;
//        for (wgtNum = 0; wgtNum < ui->tabWidget->count(); ++wgtNum)
//            if (ui->tabWidget->widget(wgtNum) == pwgt)
//                break;
//        return wgtNum;
//    }
//    else return -1;
}


// добавление действия на панель инструментов
void MainWindow::addToolbarAction(QAction *pAct)
{
//    ui->toolBar->insertAction(*ui->toolBar->actions().end(), pAct);
}


// удаление действия с панели инструментов
void MainWindow::removeToolbarAction(QAction* pAct)
{
//    ui->toolBar->removeAction(pAct);
}


// удаление пользовательского окна с главного окна
void MainWindow::removeUserWindow(QWidget* pwgt)
{
    int wgtNum = getTabNumByWidget(pwgt);
//    if (wgtNum != -1)
//        ui->tabWidget->removeTab(wgtNum);
}


// удаление всех элементов управления, извлеченных из пользовательского окна
void MainWindow::removeExtractedControls()
{
    QObjectList::const_iterator extrCtrl; // очередной извлеченный элемент управления
    for (extrCtrl = fExtractedControls.constBegin(); extrCtrl != fExtractedControls.constEnd(); ++extrCtrl)
    {
        // все действия удаляются с панели инструментов
//        QAction *pAct = dynamic_cast<QAction*>(*extrCtrl);
//        if (pAct != NULL)
//            removeToolbarAction(pAct);
    }

    // извлеченных элементов управления на данный момент нет
    fExtractedControls.clear();
}
