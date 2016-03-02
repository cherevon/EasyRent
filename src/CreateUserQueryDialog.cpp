#include "CreateUserQueryDialog.h"
#include "ui_CreateUserQueryDialog.h"

CreateUserQueryDialog::CreateUserQueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateUserQueryDialog)
{
    ui->setupUi(this);
}

CreateUserQueryDialog::~CreateUserQueryDialog()
{
    delete ui;
}

void CreateUserQueryDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
