#include "AuthWidget.h"
#include "ui_AuthWidget.h"

AuthWidget::AuthWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthWidget)
{
    ui->setupUi(this);
    connect(ui->bLogin, SIGNAL(clicked()), SLOT(LoginClicked()));
}

AuthWidget::~AuthWidget()
{
    delete ui;
}

void AuthWidget::LoginClicked()
// нажатие кнопки "Вход"
{
    if ( Login(ui->eLogin->text(), ui->ePassword->text()) != NULL )
        emit loginSuccessful();
    else
    {
        emit loginFailed();

        QMessageBox *failDlg = new QMessageBox(this);
        failDlg->setModal(true);
        failDlg->setText("Неверное имя пользователя или пароль!");
        failDlg->setIcon(QMessageBox::Critical);
        failDlg->show();
    }
}
