#include "FormPriorityShow.h"
#include <QDebug>

/*====================================================================================================================*/

FormPriorityShow::FormPriorityShow(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("Приоритетные запросы");

    PQTable = new QTableWidget(0, PQColumnAmount, this);
    PQTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList PQTableColNames;
    for(int i=0; i<PQColumnAmount; ++i)
        PQTableColNames << PQColumnNames[i];
    PQTable->setHorizontalHeaderLabels(PQTableColNames);

    loadMenu();

    TotalLayout = new QVBoxLayout(this);
    TotalLayout->addWidget(MenuBar);
    TotalLayout->addWidget(PQTable);
    TotalLayout->setMargin(0);

    PQCreate = NULL;

    connect(this, SIGNAL(destroyed()), parent, SLOT(destroyedFormPriorityShow()));
}

/*====================================================================================================================*/

void FormPriorityShow::loadMenu()
// загрузка всех видов меню на форме
{
    MenuBar             = new QMenuBar(this);
    actPrint            = MenuBar->addAction("Печать");
    menuPriority        = MenuBar->addMenu("Приоритетный запрос");
    actNewPriority      = menuPriority->addAction("Новый");
    actEditPriority     = menuPriority->addAction("Изменить");
    actDeletePriority   = menuPriority->addAction("Удалить");
    menuPriority->addSeparator();
    actSearchPriority   = menuPriority->addAction("Провести поиск");

    connect(actNewPriority,     SIGNAL(triggered()), this,      SLOT(actNewPriorityExecute()));
    connect(actEditPriority,    SIGNAL(triggered()), this,      SLOT(actEditPriorityExecute()));
    connect(actDeletePriority,  SIGNAL(triggered()), this,      SLOT(actDeletePriorityExecute()));
    connect(actPrint,           SIGNAL(triggered()), this,      SLOT(actPrintExecute()));
    connect(actSearchPriority,  SIGNAL(triggered()), this,      SLOT(actPrintExecute()));
}

/*====================================================================================================================*/

QObjectList* FormPriorityShow::extractControls()
// извлекаем элементы управления на главное окно
{
    QObjectList *extractedControls = new QObjectList();

    extractedControls->append(actNewPriority);
    extractedControls->append(actEditPriority);
    extractedControls->append(actDeletePriority);

    return extractedControls;
}

/*====================================================================================================================*/

void FormPriorityShow::show()
{
    QWidget::show();

    loadSettings();
    refreshData();
}

/*====================================================================================================================*/

void FormPriorityShow::refreshData()
// обновление данных в окне "Приоритетные запросы"
{
    QList<AbstractQuery*>::iterator iter;
    QList<AbstractQuery*> PQs = GlobalDataManager::Instance.PQs();
    int RowCount = 0;
    // для каждого приоритетного запроса
    for(iter = PQs.begin(); iter != PQs.end(); ++iter)
    {
        PQTable->setRowCount(++RowCount);
        // записываем приоритетный запрос в таблицу
        (*iter)->writeInTableWidget(PQTable, RowCount - 1);
    }

    // запрещаем редактирование всех ячеек таблицы приоритетных запросов (ReadOnly)
    for(int row = 0; row < PQTable->rowCount(); ++row)
        for(int column = 0; column < PQTable->columnCount(); ++column)
            if (PQTable->item(row, column))
                PQTable->item(row, column)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
}

/*====================================================================================================================*/

void FormPriorityShow::saveSettings()
{
    PropertyStorage::saveWidgetSettings("FormPriorityShow", this);
}

/*====================================================================================================================*/

void FormPriorityShow::loadSettings()
{
    PropertyStorage::loadWidgetSettings("FormPriorityShow", this);
}

/*====================================================================================================================*/

void FormPriorityShow::closeEvent(QCloseEvent *e)
{
    saveSettings();

    e->accept();
}

/*====================================================================================================================*/

void FormPriorityShow::actPrintExecute()
{

}

/*====================================================================================================================*/

void FormPriorityShow::actSearchPriorityExecute()
{

}

/*====================================================================================================================*/

void FormPriorityShow::actNewPriorityExecute()
// создать новый приоритетный запрос
{
    if (PQCreate == NULL)
        PQCreate = new FormPriorityCreate();
    connect(PQCreate, SIGNAL(newPQCreated()), SLOT(refreshData()));
    PQCreate->setWindowModality(Qt::ApplicationModal);
    PQCreate->show();
}

/*====================================================================================================================*/

void FormPriorityShow::actEditPriorityExecute()
// редактировать выбранный приоритетный запрос
{
    QMessageBox* msg = new QMessageBox();
    msg->setIcon(QMessageBox::Warning);

    // если выбрано больше одного запроса, то выдать сообщение
    if (PQTable->selectedItems().size()/ (PQColumnAmount - 1) > 1)
    {      
        msg->setText("Выбрано более одного приоритетного запроса");
        msg->exec();
        return;
    }

    // если не выбрано ни одного запроса, то выдать сообщение
    if (PQTable->selectedItems().isEmpty())
    {
        msg->setText("Не выбрано ни одного приоритетного запроса");
        msg->exec();
        return;
    }

    // открытие окна для редактирования приоритетного запроса
    if (PQCreate)
    {
        delete PQCreate;
        PQCreate = NULL;
    }

    PriorityQuery* selectedPQ = (PriorityQuery*)(GlobalDataManager::Instance.PQs().at(PQTable->selectedItems().at(0)->row()));
    PQCreate = new FormPriorityCreate(selectedPQ, this);
    connect(PQCreate, SIGNAL(newPQCreated()), SLOT(refreshData()));
    PQCreate->setWindowModality(Qt::ApplicationModal);
    PQCreate->show();
}

/*====================================================================================================================*/

void FormPriorityShow::actDeletePriorityExecute()
// удаляет выбранный приоритетный запрос(ы)
{
    // удаляем приоритетный запрос из памяти
    QList<QTableWidgetSelectionRange>::iterator selRange;
    qDebug() << PQTable->selectedRanges().size();
    for(selRange = PQTable->selectedRanges().begin(); selRange != PQTable->selectedRanges().end(); ++selRange)
    {
        qDebug() << (PQTable->selectedRanges().begin() == selRange);
        qDebug() << "RC" << PQTable->selectedRanges().at(0).rowCount();
        qDebug() << "TR" << PQTable->selectedRanges().at(0).topRow();
        qDebug() << "rowCount:" << (*selRange).rowCount();
        qDebug() << "topRow:" << (*selRange).topRow();
        int rowDelete = (*selRange).topRow();
//        for(int i = 0; i < (*selRange).rowCount(); ++i, ++rowDelete)
//        {
//            qDebug() << rowDelete;
//            GlobalDataManager::Instance.PQs().removeAt(rowDelete);
//        }
    }

    // обновляем таблицу приоритетных запросов, чтобы на ней отобразились изменения
    refreshData();
}

/*====================================================================================================================*/
