#include "PriorityQuery.h"

QList<AbstractQuery*> PQs; // set of current user`s priority query

QMap<QString, int> PriorityQuery::defaultColumnSequence = AbstractQuery::defaultColumnSequence;

const QString PriorityQuery::CREATE_TIME_SIGN   = "CreateTimeField";
const QString PriorityQuery::OBJECT_TYPE_SIGN   = "ObjectTypeField";
const QString PriorityQuery::LAST_SEARCH_SIGN   = "LastSearchField";
const QString PriorityQuery::EMAILS_SIGN        = "EMailsField";

/*====================================================================================================================*/

PriorityQuery::PriorityQuery(): AbstractQuery()
{
    fCreateTime = QDateTime::currentDateTime();
    fObjectType = Flat;
    fLastSearch = QDateTime();
}

/*====================================================================================================================*/

bool PriorityQuery::operator ==(const PriorityQuery& Q)
{
    return (
        (AbstractQuery::operator == (Q)) &&
        fCreateTime == Q.fCreateTime &&
        fObjectType == Q.fObjectType &&
        fLastSearch == Q.fLastSearch
    );
}

/*====================================================================================================================*/

PriorityQuery& PriorityQuery::operator =(const PriorityQuery& Q)
{
    AbstractQuery::operator =(Q);
    fCreateTime = Q.fCreateTime;
    fObjectType = Q.fObjectType;
    fLastSearch = Q.fLastSearch;

    return *this;
}

/*====================================================================================================================*/

inline QDataStream& operator >>(QDataStream& inStream, PriorityQuery& Q)
{
    inStream >> Q.fCreateTime;

    qint32 ObjectType;
    inStream >> ObjectType;
    Q.fObjectType = Queries::ObjType(ObjectType);

    inStream >> Q.fLastSearch;

    return inStream;
}

/*====================================================================================================================*/

inline QDataStream& operator <<(QDataStream& outStream, const PriorityQuery& Q)
{
    outStream << Q.fCreateTime;
    outStream << (qint32)Q.fObjectType;
    outStream << Q.fLastSearch;

    return outStream;
}

/*====================================================================================================================*/

void PriorityQuery::readBinary(QFile &f)
{
    AbstractQuery::readBinary(f);
    QDataStream inStream(&f);
    inStream >> *this;
}

/*====================================================================================================================*/

void PriorityQuery::writeBinary(QFile &f) const
{
    AbstractQuery::writeBinary(f);
    QDataStream outStream(&f);
    outStream << *this;

    f.flush();
}

/*====================================================================================================================*/

bool PriorityQuery::writeInTableWidget(QTableWidget *table, const int row, const QMap<QString, int> *pColumnNames) const
// запись данных приоритетного запроса в таблицу в строку row
// возвращается ИСТИНА, если запрос был занесен в таблицу, иначе ЛОЖЬ
{
    // проверяем, существует ли таблица и есть ли в ней строка с заданным индексом
    if ((!table) || (row<0) || (row>=table->rowCount())) return false;

    QMap<QString, int> colNamesUse;

    if (pColumnNames)
        // если порядок отображения полей задан, то используем его
        colNamesUse = *pColumnNames;
    else // задать стандартный для приоритетных запросов порядок отображения полей
        colNamesUse = PriorityQuery::defaultColumnSequence;

    // размещаем поля, которые содержатся в базовом запросе
    if (!AbstractQuery::writeInTableWidget(table, row, &colNamesUse)) return false;

    // если количества столбцов в таблице не хватает, то добавляем необходимые
    if (table->columnCount() < colNamesUse.size())
        table->setColumnCount(colNamesUse.size());

    // размещаем поля, которые содержатся только в приоритетном запросе
    QTableWidgetItem* cell;

    // время создания
    if (colNamesUse.contains(CREATE_TIME_SIGN))
    {
        cell = new QTableWidgetItem(fCreateTime.toString());
        table->setItem(row, colNamesUse[CREATE_TIME_SIGN], cell);
    }

    // тип искомого объекта
    if (colNamesUse.contains(OBJECT_TYPE_SIGN))
    {
        switch (fObjectType)
        {
        case Queries::Flat:
            cell = new QTableWidgetItem("Квартира");
            break;
        case Queries::Room:
            cell = new QTableWidgetItem("Комната");
            break;
        case Queries::Elite:
            cell = new QTableWidgetItem("Элитное");
            break;
        default:
            cell = new QTableWidgetItem();
            break;
        }
        table->setItem(row, colNamesUse[OBJECT_TYPE_SIGN], cell);
    }

    // время последнего поиска
    if (colNamesUse.contains(LAST_SEARCH_SIGN))
    {
        cell = new QTableWidgetItem( (fLastSearch.isValid())?"НИКОГДА":fLastSearch.toString() );
        table->setItem(row, colNamesUse[LAST_SEARCH_SIGN], cell);
    }

    // адреса e-mail
    if (colNamesUse.contains(EMAILS_SIGN))
    {
        cell = new QTableWidgetItem( ContainerUtils::commaText(fEMails) );
        table->setItem(row, colNamesUse[EMAILS_SIGN], cell);
    }

    return true;
}

/*====================================================================================================================*/
