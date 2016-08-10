#include "FormUserQueries.h"
#include "ui_FormUserQueries.h"
#include "DlgRealEstateQueryEditor.h"
#include "ResidentialRealEstateObject.h"
#include <QDebug>

FormUserQueries::FormUserQueries(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUserQueries)
{
    ui->setupUi(this);

    refreshData();

    connect(ui->tvQueries, SIGNAL(activated(QModelIndex)), SLOT(showQueryInfo(QModelIndex)));
}

FormUserQueries::~FormUserQueries()
{
    delete ui;
}

void FormUserQueries::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void FormUserQueries::newUserQuery()
{
//    DlgUserQueryEditor* dlg = new DlgUserQueryEditor();
    //    dlg->exec();
}


void FormUserQueries::showQueryInfo(QModelIndex index)
{
    //RealEstateQueryModel* model = qobject_cast<RealEstateQueryModel*>(ui->tvQueries->model());
    //ui->widget->setEditQuery( model->queries().at(index.row()) );
}


QList<RealEstateQuery*> getRandomQueries(const int &queryCount, QObject* parent = NULL)
{
    QList<RealEstateQuery*> q;

    RealEstateQuery *newQuery;
    for(int queryNum = 0; queryNum < queryCount; ++queryNum)
    {
        newQuery = new RealEstateQuery(parent);
        newQuery->setSearchObject(new ResidentialRealEstateObject(newQuery));
        newQuery->setQueryType(QueryType(rand()%4 + 1));
        newQuery->setPrice(rand());
        newQuery->setSource(QApplication::applicationName());
        newQuery->searchObject()->setCity("Санкт-Петербург");
        newQuery->searchObject()->setFirstFloor(rand()%15 + 1);
        newQuery->searchObject()->setFloorCount(newQuery->searchObject()->firstFloor() + rand()%15 + 1);
        newQuery->searchObject()->setRoomCount(rand()%5+1);
        newQuery->searchObject()->setTotalSquare(rand()%10000 / 100);
        newQuery->searchObject()->setRealEstateType(RealEstateType(rand()%5 + 1));
        q.append(newQuery);
    }

    return q;
}


void FormUserQueries::refreshData()
{
    RealEstateQueryModel* model = new RealEstateQueryModel(ui->tvQueries);
    model->setQueries(getRandomQueries(15, model));
    ui->tvQueries->setModel(model);
}
