#ifndef PRIORITYQUERY_H
#define PRIORITYQUERY_H

#include <QDateTime>
#include "RealEstateQuery.h"

using namespace Queries;

/*====================================================================================================================*/

class PriorityQuery: public AbstractQuery
{
private:
    QDateTime       fCreateTime;    // дата создания
    ObjType         fObjectType;    // тип объекта (комната/квартира/элитное)
    QDateTime       fLastSearch;    // дата последнего поиска по данному запросу
    QSet<QString>   fEMails;        // перечень адресов электронной почты для рассылки результатов поиска

public:
    // CONSTRUCTORS
    PriorityQuery();

    // FIELD ACCESS METHODS
    QDateTime       createTime()         const                  {return fCreateTime;}
    ObjType         searchObjectType()   const                  {return fObjectType;}
    QDateTime       lastSearchTime()     const                  {return fLastSearch;}
    QSet<QString>   eMails()             const                  {return fEMails;}
    void            setCreateTime(const QDateTime Value)        {fCreateTime = Value;}
    void            setSearchObjectType(const ObjType Value)    {fObjectType = Value;}
    void            setLastSearchTime(const QDateTime Value)    {fLastSearch = Value;}

    // OPERATORS
    bool operator ==(const PriorityQuery& Q);
    PriorityQuery& operator =(const PriorityQuery& Q);
};

/*====================================================================================================================*/

#endif // PRIORITYQUERY_H
