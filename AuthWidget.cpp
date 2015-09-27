#include "AuthWidget.h"
#include "ui_AuthWidget.h"
#include <QDebug>

AuthWidget::AuthWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthWidget)
{
    ui->setupUi(this);
    connect(ui->bLogin, SIGNAL(clicked()), SLOT(loginClicked()));
    connect(ui->bRegister, SIGNAL(clicked()), SLOT(registerClicked()));
}

AuthWidget::~AuthWidget()
{
    delete ui;
}

void AuthWidget::loginClicked()
// нажатие кнопки "Вход"
{
    EasyRentUser* authUser = login(ui->eLogin->text(), ui->ePassword->text());
    if (authUser != NULL)
        emit loginSuccessful(authUser);
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

void AuthWidget::registerClicked()
// нажатие кнопки "Регистрация"
{
    WgtRegisterUser *registerDlg = new WgtRegisterUser();
    registerDlg->setWindowModality(Qt::ApplicationModal);
    registerDlg->show();
}
