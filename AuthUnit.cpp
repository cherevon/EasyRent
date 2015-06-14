#include "AuthUnit.h"
#include <QDebug>
#include <QSqlError>

EasyRentUser* Login(const QString &username, const QString &password)
// авторизация пользователя в системе EasyRent (в случае успеха возвращает структуру с данными пользователя)
{
    // получаем информацию о пользователе из БД
    QSqlQuery query;
    query.prepare(QString("SELECT usr.id, usr.surname, usr.name, usr.patronymic, ") +
                  QString("city.name, cntry.name FROM er_users usr, cities city, ") +
                  QString("countries cntry ") +
                  QString("WHERE usr.username = :username AND usr.pswd = :password") +
                  QString("AND cntry.sign = city.country AND city.id = usr.city_id"));
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec())
        qDebug() << "CHECK:" << query.lastError();

    // если пользователь есть, то создаем и заполняем структуру
    if (query.next())
    {
        EasyRentUser* user = new EasyRentUser;
        return user;
    }
    else return NULL; // иначе, возвращаем NULL
}

bool RegisterUser(const EasyRentUser* const user)
// регистрация пользователя в системе EasyRent
{
    // проверяем наличие фамилии
    // проверяем наличие имени
    // проверяем наличие логина
    // проверяем логин на уникальность
    // проверяем наличие пароля
    // проверяем наличие страны, в которой проживает пользователь
    // проверяем наличие города, в котором проживает пользователь
    // проверяем соответствие города и страны
//    QSqlQuery query('INSERT INTO er_users(username, pswd, city_id');
}
