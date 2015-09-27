#ifndef WGTREGISTERUSER_H
#define WGTREGISTERUSER_H

#include <QWidget>
#include "Location.h"
#include "AuthUnit.h"

namespace Ui {
class WgtRegisterUser;
}

class WgtRegisterUser : public QWidget
{
    Q_OBJECT

public:
    explicit WgtRegisterUser(QWidget *parent = 0);
    ~WgtRegisterUser();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::WgtRegisterUser *ui;

private slots:
    // обработчик события при выборе другой страны
    void countryChanged(QString newCountry);
    // обработчик события при нажатии кнопки "зарегистрировать"
    void registerClicked();

signals:
    // сигнал при успешной регистрации пользователя
    void userRegistered();
};

#endif // WGTREGISTERUSER_H
