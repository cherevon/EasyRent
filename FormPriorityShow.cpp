#include "FormPriorityShow.h"
#include "ui_FormPriorityShow.h"

FormPriorityShow::FormPriorityShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPriorityShow)
{
    ui->setupUi(this);
}

FormPriorityShow::~FormPriorityShow()
{
    delete ui;
}

void FormPriorityShow::refreshData()
// reload priority queries from the set
{

}
