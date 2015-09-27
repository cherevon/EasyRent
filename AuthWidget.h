#ifndef AUTHWIDGET_H
#define AUTHWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "AuthUnit.h"
#include "WgtRegisterUser.h"

namespace Ui {
class AuthWidget;
}

class AuthWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AuthWidget(QWidget *parent = 0);
    ~AuthWidget();

private:
    Ui::AuthWidget *ui;

private slots:
    // нажатие кнопки "Вход"
    void loginClicked();
    // нажатие кнопки "Регистрация"
    void registerClicked();

signals:
    void loginSuccessful(EasyRentUser*);
    void loginFailed();
};

#endif // AUTHWIDGET_H
