#ifndef LOCATION_H
#define LOCATION_H

#include <QStringList>
#include <QtSql>
#include <QVariant>
#include <QDebug>

// получение перечня всех стран
QStringList *getAllCountries();

// получение перечня всех городов, находящихся в заданной стране
QStringList *getCitiesInCountry(const QString countryName);

#endif // LOCATION_H
