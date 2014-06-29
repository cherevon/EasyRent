#ifndef PRIORITYQUERY_H
#define PRIORITYQUERY_H

#include <QDateTime>
#include "AbstractQuery.h"

/*====================================================================================================================*/

namespace Queries
{
    enum ObjType {Room, Flat, Elite};   // тип объекта
}

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
    // порядок отображения полей запроса по умолчанию
    static QMap<QString, int> defaultColumnSequence;

    // наименования полей для поиска по ассоциативному массиву
    static const QString    CREATE_TIME_SIGN;
    static const QString    OBJECT_TYPE_SIGN;
    static const QString    LAST_SEARCH_SIGN;
    static const QString    EMAILS_SIGN;

    // CONSTRUCTORS
    PriorityQuery();

    // FIELD ACCESS METHODS
    QDateTime       createTime()         const                  {return fCreateTime;}
    ObjType         searchObjectType()   const                  {return fObjectType;}
    QDateTime       lastSearchTime()     const                  {return fLastSearch;}
    QSet<QString>&  eMails()                                    {return fEMails;}
    void            setCreateTime(const QDateTime Value)        {fCreateTime = Value;}
    void            setSearchObjectType(const ObjType Value)    {fObjectType = Value;}
    void            setLastSearchTime(const QDateTime Value)    {fLastSearch = Value;}

    // OPERATORS
    bool operator ==(const PriorityQuery& Q);
    PriorityQuery& operator =(const PriorityQuery& Q);
    friend QDataStream& operator <<(QDataStream& stream, const PriorityQuery& Q);
    friend QDataStream& operator >>(QDataStream& stream, PriorityQuery& Q);

    // METHODS
    virtual void readBinary(QFile &f);
    virtual void writeBinary(QFile &f) const;
    virtual bool writeInTableWidget(QTableWidget *table, const int row, const QMap<QString, int> *pColumnNames = NULL) const;
};

/*====================================================================================================================*/

#endif // PRIORITYQUERY_H
