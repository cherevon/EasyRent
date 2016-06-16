#include "RealEstateQueryModel.h"


// инициализируем наименования заголовков колонок по умолчанию
const QString RealEstateQueryModel::DEF_COL_NAME_CREATE_DATE = QObject::tr("Дата создания");
const QString RealEstateQueryModel::DEF_COL_NAME_QUERY_TYPE = QObject::tr("Тип запроса");
const QString RealEstateQueryModel::DEF_COL_NAME_REAL_ESTATE_TYPE = QObject::tr("Тип объекта недвижимости");
const QString RealEstateQueryModel::DEF_COL_NAME_CITY = QObject::tr("Город");
const QString RealEstateQueryModel::DEF_COL_NAME_ADDRESS = QObject::tr("Адрес");
const QString RealEstateQueryModel::DEF_COL_NAME_PRICE = QObject::tr("Стоимость");
const QString RealEstateQueryModel::DEF_COL_NAME_FLOORS = QObject::tr("Этажи");
const QString RealEstateQueryModel::DEF_COL_NAME_SQUARE_TOTAL = QObject::tr("Общая площадь");
const QString RealEstateQueryModel::DEF_COL_NAME_SQUARE_ROOMS = QObject::tr("Площадь комнат");
const QString RealEstateQueryModel::DEF_COL_NAME_CONTACT_INFO = QObject::tr("Контакт");
const QString RealEstateQueryModel::DEF_COL_NAME_ADDITIONAL_INFO = QObject::tr("Дополнительная информация");
const QString RealEstateQueryModel::DEF_COL_NAME_SOURCE = QObject::tr("Источник");
// инициализируем индексы колонок по умолчанию


RealEstateQueryModel::RealEstateQueryModel(QObject *parent): QAbstractTableModel(parent)
{
    fColumnNames.resize(COL_COUNT);

    fColumnNames[DEF_COL_IDX_ADDITIONAL_INFO] = DEF_COL_NAME_ADDITIONAL_INFO;
    fColumnNames[DEF_COL_IDX_CREATE_DATE] = DEF_COL_NAME_CREATE_DATE;
    fColumnNames[DEF_COL_IDX_QUERY_TYPE] = DEF_COL_NAME_QUERY_TYPE;
    fColumnNames[DEF_COL_IDX_REAL_ESTATE_TYPE] = DEF_COL_NAME_REAL_ESTATE_TYPE;
    fColumnNames[DEF_COL_IDX_CITY] = DEF_COL_NAME_CITY;
    fColumnNames[DEF_COL_IDX_ADDRESS] = DEF_COL_NAME_ADDRESS;
    fColumnNames[DEF_COL_IDX_PRICE] = DEF_COL_NAME_PRICE;
    fColumnNames[DEF_COL_IDX_FLOORS] = DEF_COL_NAME_FLOORS;
    fColumnNames[DEF_COL_IDX_SQUARE_TOTAL] = DEF_COL_NAME_SQUARE_TOTAL;
    fColumnNames[DEF_COL_IDX_SQUARE_ROOMS] = DEF_COL_NAME_SQUARE_ROOMS;
    fColumnNames[DEF_COL_IDX_CONTACT_INFO] = DEF_COL_NAME_CONTACT_INFO;
    fColumnNames[DEF_COL_IDX_SOURCE] = DEF_COL_NAME_SOURCE;
}


QVariant RealEstateQueryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    return fColumnNames[section];
}


bool RealEstateQueryModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role) && orientation == Qt::Horizontal) {
        fColumnNames[section] = value;
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int RealEstateQueryModel::rowCount(const QModelIndex &) const
{
    return fQueries.count();
}


int RealEstateQueryModel::columnCount(const QModelIndex &) const
{
    return fColumnNames.size();
}


QVariant RealEstateQueryModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    // определяем запрос, для которого необходимо вернуть информацию
    RealEstateQuery* curQuery = fQueries.at(index.row());

    // возвращаем данные определенного параметра запроса, соответствующего колонке
    switch (index.column())
    {
    case DEF_COL_IDX_SOURCE:
        return QVariant(curQuery->source());
        break;
    case DEF_COL_IDX_CREATE_DATE:
        return QVariant(curQuery->createDate());
        break;
    case DEF_COL_IDX_QUERY_TYPE:
        return QVariant(queryTypeToString(curQuery->queryType()));
        break;
    case DEF_COL_IDX_REAL_ESTATE_TYPE:
        return QVariant(realEstateTypeToString(curQuery->searchObject()->realEstateType()));
        break;
    case DEF_COL_IDX_CITY:
        return QVariant(curQuery->searchObject()->city());
        break;
    case DEF_COL_IDX_ADDRESS:
        return QVariant(curQuery->searchObject()->address());
        break;
    case DEF_COL_IDX_PRICE:
        return QVariant(curQuery->price());
        break;
    case DEF_COL_IDX_FLOORS:
        return QVariant(QString::number(curQuery->searchObject()->firstFloor()) +
                        QString(" - ") +
                        QString::number(curQuery->searchObject()->firstFloor() + curQuery->searchObject()->floorCount() - 1)
                        );
        break;
    case DEF_COL_IDX_SQUARE_TOTAL:
        return QVariant(curQuery->searchObject()->totalSquare());
        break;
    case DEF_COL_IDX_SQUARE_ROOMS:
    {
        return QVariant(curQuery->searchObject()->totalRoomsSquare());
        break;
    }
    case DEF_COL_IDX_CONTACT_INFO:
        return QVariant(curQuery->searchObject()->contactInfo());
        break;
    case DEF_COL_IDX_ADDITIONAL_INFO:
        return QVariant(curQuery->searchObject()->additionalInfo());
        break;
    default:
        break;
    }
    return QVariant();
}


QList<RealEstateQuery *> RealEstateQueryModel::queries() const
{
    return fQueries;
}


void RealEstateQueryModel::setQueries(QList<RealEstateQuery *> value)
{
    fQueries.clear();
    fQueries.append(value);
}
