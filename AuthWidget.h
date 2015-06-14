#ifndef AUTHWIDGET_H
#define AUTHWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "AuthUnit.h"

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
    void LoginClicked();

signals:
    void loginSuccessful();
    void loginFailed();
};

#endif // AUTHWIDGET_H
