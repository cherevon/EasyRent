#include "RealEstateQuery.h"


const QString ERR_NO_SOURCE_QUERY = QObject::tr("Не указан запрос-источник!");


void RealEstateQuery::setLastError(const QString &value)
{
    fLastError = value;
}


RealEstateQuery::RealEstateQuery(QObject *parent) : QObject(parent)
{
    fCreateDate = QDateTime::currentDateTime();
    fQueryType = QUERY_SELL;
    fSearchObject = NULL;
    fSource = "";
    fID = "";
    fPrice = 0;
}


QString RealEstateQuery::ID() const
{
    return fID;
}


RealEstateObject *RealEstateQuery::searchObject() const
{
    return fSearchObject;
}


QString RealEstateQuery::source() const
{
    return fSource;
}

uint RealEstateQuery::price() const
{
    return fPrice;
}


QDateTime RealEstateQuery::createDate() const
{
    return fCreateDate;
}


QueryType RealEstateQuery::queryType() const
{
    return fQueryType;
}


void RealEstateQuery::setID(const QString &value)
{
    fID = value;
}


void RealEstateQuery::setSearchObject(RealEstateObject * const value)
{
    fSearchObject = value;
}


void RealEstateQuery::setCreateDate(const QDateTime &value)
{
    fCreateDate = value;
}


void RealEstateQuery::setPrice(const uint &value)
{
    fPrice = value;
}


void RealEstateQuery::setSource(const QString &value)
{
    fSource = value;
}


void RealEstateQuery::setQueryType(const QueryType &value)
{
    fQueryType = value;
}


QString RealEstateQuery::lastError() const
{
    return fLastError;
}


bool RealEstateQuery::matches(const RealEstateQuery * const query) const
{
    // типы запросов
    bool typeMatches = false;
    for(int matchNum = 0; matchNum < QUERY_MATCHES_COUNT; ++matchNum)
    {
        if ((QUERY_MATCHES_TABLE[matchNum][0] == fQueryType) && (QUERY_MATCHES_TABLE[matchNum][1] == query->fQueryType))
        {
            typeMatches = true;
            break;
        }
    }

    // параметры объекта недвижимости и его стоимость
    bool priceMatches;
    bool searchObjectMatches;
    if ((fQueryType == QUERY_SELL) || (fQueryType == QUERY_SELL_RENT))
    {
        priceMatches = fPrice <= query->fPrice;
        searchObjectMatches = fSearchObject >= query->fSearchObject;
    }
    else
    {
        priceMatches = fPrice >= query->fPrice;
        searchObjectMatches = fSearchObject >= query->fSearchObject;
    }

    return typeMatches && priceMatches && searchObjectMatches;
}


bool RealEstateQuery::assign(const RealEstateQuery * const source)
{
    // проверяем возможность выполнения операции
    if (source == NULL)
    {
        setLastError(ERR_NO_SOURCE_QUERY);
        return false;
    }

    // копируем информацию из запроса-источника
    fQueryType = source->fQueryType;
    fCreateDate = source->fCreateDate;
    fPrice = source->fPrice;
    fSource = source->fSource;

    return true;
}


QString queryTypeToString(const QueryType &queryt)
{
    QMap<QueryType, QString>::ConstIterator iter;
    for(iter = QUERY_TYPE_STRINGS.constBegin(); iter != QUERY_TYPE_STRINGS.constEnd(); ++iter)
    {
        if (iter.key() == queryt)
            return iter.value();
    }

    return QString();
}


QStringList availableQueryTypesStrings()
{
    QStringList result;
    QMap<QueryType, QString>::ConstIterator iter;
    for(iter = QUERY_TYPE_STRINGS.constBegin(); iter != QUERY_TYPE_STRINGS.constEnd(); ++iter)
        result << iter.value();

    return result;
}


QueryType stringToQueryType(const QString &str)
{
    QMap<QueryType, QString>::ConstIterator iter;
    for(iter = QUERY_TYPE_STRINGS.constBegin(); iter != QUERY_TYPE_STRINGS.constEnd(); ++iter)
    {
        if (iter.value() == str)
            return iter.key();
    }

    return QUERY_NONE;
}
