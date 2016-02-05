#include "Location.h"

QStringList* getAllCountries()
// получение перечня всех стран
{
    // запрашиваем перечень стран из БД
    QSqlQuery query;
    query.prepare("SELECT name FROM countries ORDER BY name");

    if (!query.exec())
        qDebug() << query.lastError();

    // сохраняем все полученные страны в список
    QStringList* countryList = new QStringList;
    while (query.next())
    {
        *countryList << query.value("name").toString();
    }
    return countryList;
}

QStringList* getCitiesInCountry(const QString countryName)
// получение перечня всех городов, находящихся в заданной стране
{
    // запрашиваем перечень городов в стране из БД
    QSqlQuery query;
    query.prepare(QString("SELECT cities.name FROM cities, countries ") +
                  QString("WHERE cities.country = countries.sign AND countries.name = :cntry_name ") +
                  QString("ORDER BY cities.name"));
    query.bindValue(":cntry_name", countryName);

    if (!query.exec())
        qDebug() << query.lastError();

    // сохраняем все полученные города в список
    QStringList* cityList = new QStringList();
    while (query.next())
    {
        *cityList << query.value("name").toString();
    }
    return cityList;
}
