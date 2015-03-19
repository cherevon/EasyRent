#include "FormPriorityShow.h"
#include "ui_FormPriorityShow.h"

extern QList<AbstractQuery*> PQs;

FormPriorityShow::FormPriorityShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPriorityShow)
{
    ui->setupUi(this);

    connectEvents();
}

FormPriorityShow::~FormPriorityShow()
{
    delete ui;
}

void FormPriorityShow::connectEvents()
// connects signals and slots of all objects
{
    connect(ui->actNewPQ, SIGNAL(triggered()), this, SLOT(createPQ()));
}

void FormPriorityShow::createPQ()
// shows a dialog to create new priority query
{
    FormPriorityCreate* formCreatePQ = new FormPriorityCreate();

    formCreatePQ->setWindowModality(Qt::ApplicationModal);
    formCreatePQ->show();
}

QObjectList FormPriorityShow::extractControls()
// extract controls to the main window
{
    QObjectList actList;

    actList.push_back(ui->actNewPQ);    // new priority query
    actList.push_back(ui->actFind);     // find priority query
    actList.push_back(ui->actDelete);   // delete priority query

    return actList;
}

void FormPriorityShow::refreshData()
// reload priority queries from the set
{
    QList<AbstractQuery*>::const_iterator iter;
    for(iter = PQs.constBegin(); iter != PQs.constEnd(); ++iter)
    {
        appendPQ((PriorityQuery*)*iter);
    }
}

void FormPriorityShow::appendPQ(const PriorityQuery * const PQ)
// add new priority query to the grid
{
    ui->PQTable->setRowCount(ui->PQTable->rowCount() + 1);

    // insert all fields of the given priority query into the grid
    QTableWidgetItem* newCell;

    // query type
    newCell = new QTableWidgetItem( (PQ->queryType() == Queries::SDAM)?"Сдам":"Сниму" );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fQueryTypeColumn, newCell);

    // areas
    newCell = new QTableWidgetItem( ContainerUtils::commaText( PQ->areas() ) );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fAreasColumn, newCell);

    // metros
    newCell = new QTableWidgetItem( ContainerUtils::commaText( PQ->metros() ) );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fMetrosColumn, newCell);

    // rooms
    newCell = new QTableWidgetItem( QString::number( PQ->roomCount() ) );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fRoomsColumn, newCell);

    // furniture
    newCell = new QTableWidgetItem( PQ->hasFurniture()?"+":"-" );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fFurnitureColumn, newCell);

    // washer
    newCell = new QTableWidgetItem( PQ->hasWasher()?"+":"-" );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fWasherColumn, newCell);

    // telephone
    newCell = new QTableWidgetItem( PQ->hasTelephone()?"+":"-" );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fTelephoneColumn, newCell);

    // fridge
    newCell = new QTableWidgetItem( PQ->hasFridge()?"+":"-" );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fFridgeColumn, newCell);
   
    // price
    newCell = new QTableWidgetItem( QString::number(PQ->basePrice()) + " руб." );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fPriceColumn, newCell);

    // period
    newCell = new QTableWidgetItem( (PQ->period() >= 12)?"Длительный":QString::number(PQ->period()) );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fPeriodColumn, newCell);

    // additional information
    newCell = new QTableWidgetItem( PQ->additionalInfo() );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fAddInfoColumn, newCell);

    // create time
    newCell = new QTableWidgetItem( PQ->createTime().toString() );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fCreateTimeColumn, newCell);

    // object type
    switch (PQ->searchObjectType())
    {
        case Queries::Room :
            newCell = new QTableWidgetItem("Комната");
            break;
        case Queries::Flat :
            newCell = new QTableWidgetItem("Квартира");
            break;
        case Queries::Elite :
            newCell = new QTableWidgetItem("Элитное");
            break;
        default :
            newCell = new QTableWidgetItem("Неизвестно");
            break;
    }
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fObjectTypeColumn, newCell);

    // last search
    newCell = new QTableWidgetItem( PQ->lastSearchTime().toString() );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fLastSearchColumn, newCell);

    // e-mail addresses
    newCell = new QTableWidgetItem( ContainerUtils::commaText( PQ->eMails() ) );
    ui->PQTable->setItem(ui->PQTable->rowCount() - 1, fEMailsColumn, newCell);
}
