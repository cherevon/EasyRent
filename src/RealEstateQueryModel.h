#ifndef REALESTATEQUERYMODEL_H
#define REALESTATEQUERYMODEL_H


#include <QAbstractTableModel>
#include <QList>
#include <QVector>
#include "RealEstateQuery.h"


/// Модель для отображения запросов для поиска недвижимости
class RealEstateQueryModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit RealEstateQueryModel(QObject *parent = 0);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QList<RealEstateQuery *> queries() const;
    void setQueries(QList<RealEstateQuery*> value);

private:
    QList<RealEstateQuery*> fQueries; // запросы, добавленные в модель
    QVector<QVariant> fColumnNames; // наименования колонок

    // наименования колонок по умолчанию
    static const QString DEF_COL_NAME_SOURCE;
    static const QString DEF_COL_NAME_CREATE_DATE;
    static const QString DEF_COL_NAME_QUERY_TYPE;
    static const QString DEF_COL_NAME_REAL_ESTATE_TYPE;
    static const QString DEF_COL_NAME_CITY;
    static const QString DEF_COL_NAME_ADDRESS;
    static const QString DEF_COL_NAME_PRICE;
    static const QString DEF_COL_NAME_FLOORS;
    static const QString DEF_COL_NAME_SQUARE_TOTAL;
    static const QString DEF_COL_NAME_SQUARE_ROOMS;
    static const QString DEF_COL_NAME_CONTACT_INFO;
    static const QString DEF_COL_NAME_ADDITIONAL_INFO;

    // индексы колонок по умолчанию
    static const int COL_COUNT = 12;
    static const int DEF_COL_IDX_SOURCE = 0;
    static const int DEF_COL_IDX_CREATE_DATE = DEF_COL_IDX_SOURCE + 1;
    static const int DEF_COL_IDX_QUERY_TYPE = DEF_COL_IDX_CREATE_DATE + 1;
    static const int DEF_COL_IDX_REAL_ESTATE_TYPE = DEF_COL_IDX_QUERY_TYPE + 1;
    static const int DEF_COL_IDX_CITY = DEF_COL_IDX_REAL_ESTATE_TYPE + 1;
    static const int DEF_COL_IDX_ADDRESS = DEF_COL_IDX_CITY + 1;
    static const int DEF_COL_IDX_PRICE = DEF_COL_IDX_ADDRESS + 1;
    static const int DEF_COL_IDX_FLOORS = DEF_COL_IDX_PRICE + 1;
    static const int DEF_COL_IDX_SQUARE_TOTAL = DEF_COL_IDX_FLOORS + 1;
    static const int DEF_COL_IDX_SQUARE_ROOMS = DEF_COL_IDX_SQUARE_TOTAL + 1;
    static const int DEF_COL_IDX_CONTACT_INFO = DEF_COL_IDX_SQUARE_ROOMS + 1;
    static const int DEF_COL_IDX_ADDITIONAL_INFO = DEF_COL_IDX_CONTACT_INFO + 1;
};


#endif // REALESTATEQUERYMODEL_H
