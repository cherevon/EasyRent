#include "FormUserQueries.h"
#include "ui_FormUserQueries.h"
#include "DlgUserQueryEditor.h"
#include <QDebug>

FormUserQueries::FormUserQueries(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUserQueries)
{
    ui->setupUi(this);

    refreshData();
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


void FormUserQueries::refreshData()
{
    //RealEstateQueryModel* model = new RealEstateQueryModel(ui->tableView);
    //ui->tableView->setModel(model);
}
