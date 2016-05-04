#include "DlgUserQueryEditor.h"
#include "ui_DlgUserQueryEditor.h"

DlgUserQueryEditor::DlgUserQueryEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgUserQueryEditor)
{
    ui->setupUi(this);
}

DlgUserQueryEditor::~DlgUserQueryEditor()
{
    delete ui;
}
