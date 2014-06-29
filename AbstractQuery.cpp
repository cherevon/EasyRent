#include "AbstractQuery.h"

/*====================================================================================================================*/

// инициализация констант
const QString AbstractQuery::QUERY_TYPE_SIGN        = "QueryTypeField";
const QString AbstractQuery::ROOMS_SIGN             = "RoomsField";
const QString AbstractQuery::PRICE_SIGN             = "PriceField";
const QString AbstractQuery::PERIOD_SIGN            = "PeriodField";
const QString AbstractQuery::AREAS_SIGN             = "AreasField";
const QString AbstractQuery::METROS_SIGN            = "MetrosField";
const QString AbstractQuery::FURNITURE_SIGN         = "FurnitureField";
const QString AbstractQuery::WASHER_SIGN            = "WasherField";
const QString AbstractQuery::TELEPHONE_SIGN         = "TelephoneField";
const QString AbstractQuery::FRIDGE_SIGN            = "FridgeField";
const QString AbstractQuery::ADDRESS_SIGN           = "AddressField";
const QString AbstractQuery::CONTACT_SIGN           = "ContactField";
const QString AbstractQuery::ADDITIONAL_INFO_SIGN   = "AddInfoField";

QMap<QString, int> AbstractQuery::defaultColumnSequence;

struct InitAbstractQuery
{
    InitAbstractQuery()
    {
        // порядок размещения полей запроса по умолчанию
        AbstractQuery::defaultColumnSequence[AbstractQuery::QUERY_TYPE_SIGN]       = 0;
        AbstractQuery::defaultColumnSequence[AbstractQuery::ROOMS_SIGN]            = 1;
        AbstractQuery::defaultColumnSequence[AbstractQuery::PRICE_SIGN]            = 2;
        AbstractQuery::defaultColumnSequence[AbstractQuery::PERIOD_SIGN]           = 3;
        AbstractQuery::defaultColumnSequence[AbstractQuery::AREAS_SIGN]            = 4;
        AbstractQuery::defaultColumnSequence[AbstractQuery::METROS_SIGN]           = 5;
        AbstractQuery::defaultColumnSequence[AbstractQuery::FURNITURE_SIGN]        = 6;
        AbstractQuery::defaultColumnSequence[AbstractQuery::WASHER_SIGN]           = 7;
        AbstractQuery::defaultColumnSequence[AbstractQuery::TELEPHONE_SIGN]        = 8;
        AbstractQuery::defaultColumnSequence[AbstractQuery::FRIDGE_SIGN]           = 9;
        AbstractQuery::defaultColumnSequence[AbstractQuery::ADDRESS_SIGN]          = 10;
        AbstractQuery::defaultColumnSequence[AbstractQuery::CONTACT_SIGN]          = 11;
        AbstractQuery::defaultColumnSequence[AbstractQuery::ADDITIONAL_INFO_SIGN]  = 12;
    }
} initAbstr;

/*====================================================================================================================*/

AbstractQuery::AbstractQuery()
{
    fType       = SDAM;
    fAreas      = QSet<QString>();
    fMetros     = QSet<QString>();
    fRooms      = 1;
    fAddress    = "";
    fFurniture  = fWasher = fFridge = fTelephone = false;
    fPrice      = 10000;
    fContact    = "";
    fAddInfo    = "";
}

/*====================================================================================================================*/

AbstractQuery::~AbstractQuery()
{
    fAreas.clear();
    fMetros.clear();
}

/*====================================================================================================================*/

bool AbstractQuery::writeInTableWidget(QTableWidget *table, const int row, const QMap<QString, int> *pColumnNames) const
// запись данных запроса в таблицу в строку row
// возвращается ИСТИНА, если запрос был занесен в таблицу, иначе ЛОЖЬ
{
    // проверяем, существует ли таблица и есть ли в ней строка с заданным индексом
    if ((!table) || (row<0) || (row>=table->rowCount())) return false;

    QMap<QString, int> colNamesUse;

    // определяем порядок расположения столбцов
    (pColumnNames)?colNamesUse = *pColumnNames: colNamesUse = defaultColumnSequence;

    // если столбцов не хватает, то добавляем недостающее количество (colNamesUse)
    if (table->columnCount() < colNamesUse.size())
        table->setColumnCount(colNamesUse.size());

    QTableWidgetItem* cell;
    // записываем в таблицу те части запроса, которые указаны в полученном порядке
    // тип запроса
    if (colNamesUse.contains(QUERY_TYPE_SIGN))
    {
        cell = new QTableWidgetItem((fType == Queries::SDAM)?"Сдам":"Сниму");
        table->setItem(row, colNamesUse[QUERY_TYPE_SIGN], cell);
    }

    // районы
    if (colNamesUse.contains(AREAS_SIGN))
    {
        cell = new QTableWidgetItem(ContainerUtils::commaText(fAreas));
        table->setItem(row, colNamesUse[AREAS_SIGN], cell);
    }

    // станции метро
    if (colNamesUse.contains(METROS_SIGN))
    {
        cell = new QTableWidgetItem(ContainerUtils::commaText(fMetros));
        table->setItem(row, colNamesUse[METROS_SIGN], cell);
    }

    // количество комнат
    if (colNamesUse.contains(ROOMS_SIGN))
    {
        cell = new QTableWidgetItem(QString::number(fRooms));
        table->setItem(row, colNamesUse[ROOMS_SIGN], cell);
    }

    // адрес
    if (colNamesUse.contains(ADDRESS_SIGN))
    {
        cell = new QTableWidgetItem(fAddress);
        table->setItem(row, colNamesUse[ADDRESS_SIGN], cell);
    }

    // наличие мебели
    if (colNamesUse.contains(FURNITURE_SIGN))
    {
        cell = new QTableWidgetItem();
        cell->setCheckState((fFurniture)? Qt::Checked: Qt::Unchecked);
        table->setItem(row, colNamesUse[FURNITURE_SIGN], cell);
    }

    // наличие стиральной машины
    if (colNamesUse.contains(WASHER_SIGN))
    {
        cell = new QTableWidgetItem();
        cell->setCheckState((fWasher)? Qt::Checked: Qt::Unchecked);
        table->setItem(row, colNamesUse[WASHER_SIGN], cell);
    }

    // наличие холодильника
    if (colNamesUse.contains(FRIDGE_SIGN))
    {
        cell = new QTableWidgetItem();
        cell->setCheckState((fFridge)? Qt::Checked: Qt::Unchecked);
        table->setItem(row, colNamesUse[FRIDGE_SIGN], cell);
    }

    // наличие телефона
    if (colNamesUse.contains(TELEPHONE_SIGN))
    {
        cell = new QTableWidgetItem();
        cell->setCheckState((fTelephone)? Qt::Checked: Qt::Unchecked);
        table->setItem(row, colNamesUse[TELEPHONE_SIGN], cell);
    }

    // стоимость
    if (colNamesUse.contains(PRICE_SIGN))
    {
        cell = new QTableWidgetItem(QString::number(fPrice) + " руб.");
        table->setItem(row, colNamesUse[PRICE_SIGN], cell);
    }

    // срок
    if (colNamesUse.contains(PERIOD_SIGN))
    {
        cell = new QTableWidgetItem( (fPeriod == 0)?"Длительный":QString::number(fPeriod) );
        table->setItem(row, colNamesUse[PERIOD_SIGN], cell);
    }

    // контактная информация
    if (colNamesUse.contains(CONTACT_SIGN))
    {
        cell = new QTableWidgetItem(fContact);
        table->setItem(row, colNamesUse[CONTACT_SIGN], cell);
    }

    // дополнительные сведения
    if (colNamesUse.contains(ADDITIONAL_INFO_SIGN))
    {
        cell = new QTableWidgetItem(fAddInfo);
        table->setItem(row, colNamesUse[ADDITIONAL_INFO_SIGN], cell);
    }

    return true;
}

/*====================================================================================================================*/

bool AbstractQuery::operator ==(const AbstractQuery& Q)
{
    if (this == &Q) return true;
    return (
                fType       == Q.fType &&
                fAreas      == Q.fAreas &&
                fMetros     == Q.fMetros &&
                fRooms      == Q.fRooms &&
                fAddress    == Q.fAddress &&
                fFurniture  == Q.fFurniture &&
                fWasher     == Q.fWasher &&
                fFridge     == Q.fFridge &&
                fTelephone  == Q.fTelephone &&
                fPrice      == Q.fPrice &&
                fPeriod     == Q.fPeriod &&
                fContact    == Q.fContact &&
                fAddInfo    == Q.fAddInfo
            );
}

/*====================================================================================================================*/

AbstractQuery& AbstractQuery::operator =(const AbstractQuery& Q)
{
    if (this == &Q) return *this;
    fType       = Q.fType;
    fAreas      = Q.fAreas;
    fMetros     = Q.fMetros;
    fRooms      = Q.fRooms;
    fAddress    = Q.fAddress;
    fFurniture  = Q.fFurniture;
    fWasher     = Q.fWasher;
    fFridge     = Q.fFridge;
    fTelephone  = Q.fTelephone;
    fPrice      = Q.fPrice;
    fPeriod     = Q.fPeriod;
    fContact    = Q.fContact;
    fAddInfo    = Q.fAddInfo;

    return *this;
}

/*====================================================================================================================*/

void AbstractQuery::writeBinary(QFile &f) const
{
    QDataStream outStream(&f);
    outStream << *this;
}

/*====================================================================================================================*/

void AbstractQuery::readBinary(QFile &f)
{
    QDataStream inStream(&f);
    inStream >> *this;
}

/*====================================================================================================================*/

inline QDataStream& operator >>(QDataStream& stream, AbstractQuery& Q)
{
    qint32 QType;
    stream >> QType;
    Q.fType = Queries::QueryType(QType);
    stream >> Q.fAreas;
    stream >> Q.fMetros;
    stream >> Q.fRooms;
    stream >> Q.fAddress;
    stream >> Q.fFurniture;
    stream >> Q.fTelephone;
    stream >> Q.fWasher;
    stream >> Q.fFridge;
    stream >> Q.fPrice;
    stream >> Q.fPeriod;
    stream >> Q.fContact;
    stream >> Q.fAddInfo;

    return stream;
}

/*====================================================================================================================*/

inline QDataStream& operator <<(QDataStream& stream, const AbstractQuery& Q)
{
    stream << (qint32)Q.fType;
    stream << Q.fAreas;
    stream << Q.fMetros;
    stream << Q.fRooms;
    stream << Q.fAddress;
    stream << Q.fFurniture;
    stream << Q.fTelephone;
    stream << Q.fWasher;
    stream << Q.fFridge;
    stream << Q.fPrice;
    stream << Q.fPeriod;
    stream << Q.fContact;
    stream << Q.fAddInfo;

    return stream;
}

/*====================================================================================================================*/
