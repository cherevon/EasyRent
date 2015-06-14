#ifndef AUTHUNIT_H
#define AUTHUNIT_H

#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QException>

// файл содержит функции, отвечающие за авторизацию и управление авторизационными данными в системе EasyRent

// сведения о пользователе системы EasyRent
struct EasyRentUser
{
    uint ID; // уникальный идентификатор пользователя
    QString username; // логин
    QString password; // пароль
    QString surname; // фамилия
    QString name; // имя
    QString patronymic; // отчество
    QString country; // страна, в которой проживает пользователь
    QString city; // город, в котором проживает пользователь
};

// авторизация пользователя в системе EasyRent (в случае успеха возвращает структуру с данными пользователя)
EasyRentUser *Login(const QString &username, const QString &password);

// регистрация пользователя в системе EasyRent
bool RegisterUser(const EasyRentUser * const user);

#endif // AUTHUNIT_H
