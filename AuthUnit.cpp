#include "AuthUnit.h"
#include <QDebug>
#include <QSqlError>

EasyRentUser* login(const QString &username, const QString &password)
// авторизация пользователя в системе EasyRent (в случае успеха возвращает структуру с данными пользователя)
{
    // получаем информацию о пользователе из БД
    QSqlQuery query;
    query.prepare(QString("SELECT usr.id, usr.surname, usr.name AS usr_name, usr.patronymic, ") +
                  QString("city.name AS city_name, cntry.name AS cntry_name ") +
                  QString("FROM er_users usr, cities city, countries cntry ") +
                  QString("WHERE usr.username = :username AND usr.pswd = :password ") +
                  QString("AND cntry.sign = city.country AND city.id = usr.city_id"));
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec())
        qDebug() << query.lastError();

    // если пользователь есть, то создаем и заполняем структуру
    if (query.next())
    {
        EasyRentUser* user = new EasyRentUser;
        user->name = query.value("usr_name").toString();
        user->surname = query.value("surname").toString();
        user->patronymic = query.value("patronymic").toString();
        user->city = query.value("city_name").toString();
        user->ID = query.value("id").toInt();
        user->country = query.value("cntry_name").toString();
        user->username = username;
        user->password = password;
        return user;
    }
    else return NULL; // иначе, возвращаем NULL
}

bool registerUser(const EasyRentUser* const user)
// регистрация пользователя в системе EasyRent
{
    // проверяем наличие фамилии
    if (user->surname.isEmpty())
        return false;
    // проверяем наличие имени
    if (user->name.isEmpty())
        return false;
    // проверяем наличие логина
    if (user->username.isEmpty())
        return false;
    // проверяем наличие пароля
    if (user->password.isEmpty())
        return false;

    QSqlQuery query;
    // проверяем логин на уникальность
    query.prepare("SELECT id FROM er_users WHERE username = :username");
    query.bindValue(":username", user->username);
    if (!query.exec())
        qDebug() << query.lastError();
    if (query.next())
        return false;

    // проверяем соответствие города и страны
    query.prepare(QString("SELECT city.id FROM cities city, countries cntry ") +
                  QString("WHERE city.country = cntry.sign ") +
                  QString("AND cntry.name = :country_name ")+
                  QString("AND city.name = :city_name "));
    query.bindValue(":country_name", user->country);
    query.bindValue(":city_name", user->city);
    if (!query.exec())
        qDebug() << query.lastError();
    if (!query.next())
        return false;

    // регистрируем нового пользователя в системе EasyRent
    query.prepare(QString("INSERT INTO er_users(surname, name, patronymic, username, pswd, city_id) ") +
                  QString("VALUES (:surname, :name, :patronymic, :username, :password, ") +
                  QString("(SELECT city.id FROM cities city, countries cntry WHERE city.country = cntry.sign ") +
                  QString("AND cntry.name = :country_name AND city.name = :city_name))"));
    query.bindValue(":surname", user->surname);
    query.bindValue(":name", user->name);
    query.bindValue(":patronymic", user->patronymic);
    query.bindValue(":username", user->username);
    query.bindValue(":password", user->password);
    query.bindValue(":country_name", user->country);
    query.bindValue(":city_name", user->city);
    if (!query.exec())
    {
        qDebug() << query.lastError();
        return false;
    }
    else
        return true;
}
