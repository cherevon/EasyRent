#ifndef RESPONSEQUERY_H
#define RESPONSEQUERY_H

#include <QDateTime>
#include "RentQuery.h"

/*====================================================================================================================*/

class ResponseQuery: public AbstractQuery
{
private:
    QDateTime   fUpdateTime;  // дата обновления
    QString     fAgent;       // агент

public:
    // CONSTRUCTORS
    ResponseQuery();

    // FIELD ACCESS METHODS
    QDateTime   updateTime()            const           {return fUpdateTime;}
    QString     agent()                 const           {return fAgent;}
    void        setUpdateTime(const QDateTime Value)    {fUpdateTime = Value;}
    void        setAgent(const QString Value)           {fAgent = Value;}

    // OPERATORS
    bool operator ==(const ResponseQuery& Q);
    ResponseQuery& operator =(const ResponseQuery& Q);
};

/*====================================================================================================================*/

#endif // RESPONSEQUERY_H
