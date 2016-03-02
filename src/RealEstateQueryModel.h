#ifndef REALESTATEQUERYMODEL_H
#define REALESTATEQUERYMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QVector>
#include "RealEstateQuery.h"

class RealEstateQueryModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit RealEstateQueryModel(QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setQueries(QList<RealEstateQuery*> value);

private:
    QList<RealEstateQuery*> fQueries; // запросы, добавленные в модель
    QVector<QVariant> fColumnNames; // наименования колонок

    // количество колонок
    static const int COLUMN_COUNT = 13;
    // индексы колонок
    static const int COLUMN_INDEX_CREATE_DATE = 0;
    static const int COLUMN_INDEX_QUERY_TYPE = 1;
    static const int COLUMN_INDEX_REAL_ESTATE_TYPE = 2;
    static const int COLUMN_INDEX_CITY = 3;
    static const int COLUMN_INDEX_ADDRESS = 4;
    static const int COLUMN_INDEX_PRICE = 5;
    static const int COLUMN_INDEX_FLOOR_COUNT = 6;
    static const int COLUMN_INDEX_FIRST_FLOOR = 7;
    static const int COLUMN_INDEX_SQUARE_TOTAL = 8;
    static const int COLUMN_INDEX_SQUARE_KITCHENS = 9;
    static const int COLUMN_INDEX_SQUARE_ROOMS = 10;
    static const int COLUMN_INDEX_CONTACT_INFO = 11;
    static const int COLUMN_INDEX_ADDITIONAL_INFO = 12;
    // наименования колонок
    static const char* COLUMN_NAME_CREATE_DATE;
    static const char* COLUMN_NAME_QUERY_TYPE;
    static const char* COLUMN_NAME_REAL_ESTATE_TYPE;
    static const char* COLUMN_NAME_CITY;
    static const char* COLUMN_NAME_ADDRESS;
    static const char* COLUMN_NAME_PRICE;
    static const char* COLUMN_NAME_FLOOR_COUNT;
    static const char* COLUMN_NAME_FIRST_FLOOR;
    static const char* COLUMN_NAME_SQUARE_TOTAL;
    static const char* COLUMN_NAME_SQUARE_KITCHENS;
    static const char* COLUMN_NAME_SQUARE_ROOMS;
    static const char* COLUMN_NAME_CONTACT_INFO;
    static const char* COLUMN_NAME_ADDITIONAL_INFO;
};

#endif // REALESTATEQUERYMODEL_H
