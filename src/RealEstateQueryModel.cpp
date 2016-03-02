#include "RealEstateQueryModel.h"


// инициализируем константы класса RealEstateQueryModel
const char* RealEstateQueryModel::COLUMN_NAME_CREATE_DATE = "Дата создания";
const char* RealEstateQueryModel::COLUMN_NAME_QUERY_TYPE = "Тип запроса";
const char* RealEstateQueryModel::COLUMN_NAME_REAL_ESTATE_TYPE = "Тип объекта недвижимости";
const char* RealEstateQueryModel::COLUMN_NAME_CITY = "Город";
const char* RealEstateQueryModel::COLUMN_NAME_ADDRESS = "Адрес";
const char* RealEstateQueryModel::COLUMN_NAME_PRICE = "Стоимость";
const char* RealEstateQueryModel::COLUMN_NAME_FLOOR_COUNT = "Количество этажей";
const char* RealEstateQueryModel::COLUMN_NAME_FIRST_FLOOR = "Номер нижнего этажа";
const char* RealEstateQueryModel::COLUMN_NAME_SQUARE_TOTAL = "Общая площадь";
const char* RealEstateQueryModel::COLUMN_NAME_SQUARE_KITCHENS = "Площадь кухонь";
const char* RealEstateQueryModel::COLUMN_NAME_SQUARE_ROOMS = "Площадь комнат";
const char* RealEstateQueryModel::COLUMN_NAME_CONTACT_INFO = "Контакт";
const char* RealEstateQueryModel::COLUMN_NAME_ADDITIONAL_INFO = "Дополнительная информация";


RealEstateQueryModel::RealEstateQueryModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    fColumnNames.resize(COLUMN_COUNT);
    fColumnNames[COLUMN_INDEX_ADDITIONAL_INFO] = COLUMN_NAME_ADDITIONAL_INFO;
    fColumnNames[COLUMN_INDEX_CREATE_DATE] = COLUMN_NAME_CREATE_DATE;
    fColumnNames[COLUMN_INDEX_QUERY_TYPE] = COLUMN_NAME_QUERY_TYPE;
    fColumnNames[COLUMN_INDEX_REAL_ESTATE_TYPE] = COLUMN_NAME_REAL_ESTATE_TYPE;
    fColumnNames[COLUMN_INDEX_CITY] = COLUMN_NAME_CITY;
    fColumnNames[COLUMN_INDEX_ADDRESS] = COLUMN_NAME_ADDRESS;
    fColumnNames[COLUMN_INDEX_PRICE] = COLUMN_NAME_PRICE;
    fColumnNames[COLUMN_INDEX_FLOOR_COUNT] = COLUMN_NAME_FLOOR_COUNT;
    fColumnNames[COLUMN_INDEX_FIRST_FLOOR] = COLUMN_NAME_FIRST_FLOOR;
    fColumnNames[COLUMN_INDEX_SQUARE_TOTAL] = COLUMN_NAME_SQUARE_TOTAL;
    fColumnNames[COLUMN_INDEX_SQUARE_KITCHENS] = COLUMN_NAME_SQUARE_KITCHENS;
    fColumnNames[COLUMN_INDEX_SQUARE_ROOMS] = COLUMN_NAME_SQUARE_ROOMS;
    fColumnNames[COLUMN_INDEX_CONTACT_INFO] = COLUMN_NAME_CONTACT_INFO;
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
    return COLUMN_COUNT;
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
        return QVariant(realEstateTypeToString(curQuery->realEstateType()));
    case COLUMN_INDEX_CITY:
        return QVariant(curQuery->city());
        break;
    case COLUMN_INDEX_ADDRESS:
        return QVariant(curQuery->address());
        break;
    case COLUMN_INDEX_PRICE:
        return QVariant(curQuery->price());
        break;
    case COLUMN_INDEX_FLOOR_COUNT:
        return QVariant(curQuery->floorCount());
        break;
    case COLUMN_INDEX_FIRST_FLOOR:
        return QVariant(curQuery->firstFloor());
        break;
    case COLUMN_INDEX_SQUARE_TOTAL:
        return QVariant(curQuery->squareTotal());
        break;
    case COLUMN_INDEX_SQUARE_KITCHENS:
    {
        float kitchensSquare = 0;
        for (uint i = 0; i < curQuery->kitchenCount(); ++i)
            kitchensSquare += curQuery->squareKitchen(i);
        return QVariant(kitchensSquare);
        break;
    }
    case COLUMN_INDEX_SQUARE_ROOMS:
    {
        float roomsSquare = 0;
        for (uint i = 0; i < curQuery->roomCount(); ++i)
            roomsSquare += curQuery->squareRoom(i);
        return QVariant(roomsSquare);
        break;
    }
    case COLUMN_INDEX_CONTACT_INFO:
        return QVariant(curQuery->contactInfo());
        break;
    case COLUMN_INDEX_ADDITIONAL_INFO:
        return QVariant(curQuery->additionalInfo());
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
