#include "RealEstateQueryModel.h"


// инициализируем константы класса RealEstateQueryModel
const QString RealEstateQueryModel::COLUMN_NAME_CREATE_DATE = QObject::tr("Дата создания");
const QString RealEstateQueryModel::COLUMN_NAME_QUERY_TYPE = QObject::tr("Тип запроса");
const QString RealEstateQueryModel::COLUMN_NAME_REAL_ESTATE_TYPE = QObject::tr("Тип объекта недвижимости");
const QString RealEstateQueryModel::COLUMN_NAME_CITY = QObject::tr("Город");
const QString RealEstateQueryModel::COLUMN_NAME_ADDRESS = QObject::tr("Адрес");
const QString RealEstateQueryModel::COLUMN_NAME_PRICE = QObject::tr("Стоимость");
const QString RealEstateQueryModel::COLUMN_NAME_FLOORS = QObject::tr("Этажи");
const QString RealEstateQueryModel::COLUMN_NAME_SQUARE_TOTAL = QObject::tr("Общая площадь");
const QString RealEstateQueryModel::COLUMN_NAME_SQUARE_ROOMS = QObject::tr("Площадь комнат");
const QString RealEstateQueryModel::COLUMN_NAME_CONTACT_INFO = QObject::tr("Контакт");
const QString RealEstateQueryModel::COLUMN_NAME_ADDITIONAL_INFO = QObject::tr("Дополнительная информация");
const QString RealEstateQueryModel::COLUMN_NAME_SOURCE = QObject::tr("Источник");


RealEstateQueryModel::RealEstateQueryModel(QObject *parent): QAbstractTableModel(parent)
{
    fColumnNames << COLUMN_NAME_ADDITIONAL_INFO
                 << COLUMN_NAME_CREATE_DATE
                 << COLUMN_NAME_QUERY_TYPE
                 << COLUMN_NAME_REAL_ESTATE_TYPE
                 << COLUMN_NAME_CITY
                 << COLUMN_NAME_ADDRESS
                 << COLUMN_NAME_PRICE
                 << COLUMN_NAME_FLOORS
                 << COLUMN_NAME_SQUARE_TOTAL
                 << COLUMN_NAME_SQUARE_ROOMS
                 << COLUMN_NAME_CONTACT_INFO
                 << COLUMN_NAME_SOURCE;
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
    case COLUMN_INDEX_CREATE_DATE:
        return QVariant(curQuery->createDate());
        break;
    case COLUMN_INDEX_QUERY_TYPE:
        return QVariant(queryTypeToString(curQuery->queryType()));
        break;
    case COLUMN_INDEX_REAL_ESTATE_TYPE:
        return QVariant(realEstateTypeToString(curQuery->searchObject()->realEstateType()));
    case COLUMN_INDEX_CITY:
        return QVariant(curQuery->searchObject()->city());
        break;
    case COLUMN_INDEX_ADDRESS:
        return QVariant(curQuery->searchObject()->address());
        break;
    case COLUMN_INDEX_PRICE:
        return QVariant(curQuery->searchObject()->price());
        break;
    case COLUMN_INDEX_FLOOR_COUNT:
        return QVariant(curQuery->searchObject()->floorCount());
        break;
    case COLUMN_INDEX_FIRST_FLOOR:
        return QVariant(curQuery->searchObject()->firstFloor());
        break;
    case COLUMN_INDEX_SQUARE_TOTAL:
        return QVariant(curQuery->searchObject()->squareTotal());
        break;
    case COLUMN_INDEX_SQUARE_ROOMS:
    {
        return QVariant(curQuery->searchObject()->totalRoomsSquare());
        break;
    }
    case COLUMN_INDEX_CONTACT_INFO:
        return QVariant(curQuery->searchObject()->contactInfo());
        break;
    case COLUMN_INDEX_ADDITIONAL_INFO:
        return QVariant(curQuery->searchObject()->additionalInfo());
        break;
    default:
        break;
    }
    return QVariant();
}


void RealEstateQueryModel::setQueries(QList<RealEstateQuery *> value)
{
    //fQueries.
}
