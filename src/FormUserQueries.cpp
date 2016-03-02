#include "FormUserQueries.h"
#include "ui_FormUserQueries.h"
#include "CreateUserQueryDialog.h"
#include <QDebug>

FormUserQueries::FormUserQueries(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUserQueries)
{
    ui->setupUi(this);
    refreshData();

    connect(ui->toolButton, SIGNAL(clicked()), SLOT(newUserQuery()));
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
    CreateUserQueryDialog* dlg = new CreateUserQueryDialog();
    dlg->exec();
}


void FormUserQueries::refreshData()
{

    RealEstateQueryModel* model = new RealEstateQueryModel(ui->tableView);
    ui->tableView->setModel(model);
}
