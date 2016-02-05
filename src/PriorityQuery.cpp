#include "PriorityQuery.h"

QList<AbstractQuery*> PQs; // set of current user`s priority query

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
