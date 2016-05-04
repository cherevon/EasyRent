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

    void setQueries(QList<RealEstateQuery*> value);

private:
    QList<RealEstateQuery*> fQueries; // запросы, добавленные в модель
    QList<QVariant> fColumnNames; // наименования колонок

    // наименования колонок
    static const QString COLUMN_NAME_SOURCE;
    static const QString COLUMN_NAME_CREATE_DATE;
    static const QString COLUMN_NAME_QUERY_TYPE;
    static const QString COLUMN_NAME_REAL_ESTATE_TYPE;
    static const QString COLUMN_NAME_CITY;
    static const QString COLUMN_NAME_ADDRESS;
    static const QString COLUMN_NAME_PRICE;
    static const QString COLUMN_NAME_FLOORS;
    static const QString COLUMN_NAME_SQUARE_TOTAL;
    static const QString COLUMN_NAME_SQUARE_ROOMS;
    static const QString COLUMN_NAME_CONTACT_INFO;
    static const QString COLUMN_NAME_ADDITIONAL_INFO;
};

#endif // REALESTATEQUERYMODEL_H
