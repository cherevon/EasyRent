#include "ResponseQuery.h"

/*====================================================================================================================*/

ResponseQuery::ResponseQuery(): AbstractQuery()
{
    fUpdateTime = QDateTime::currentDateTime();
    fAgent      = "";
}

/*====================================================================================================================*/

bool ResponseQuery::operator ==(const ResponseQuery &Q)
{
    return (AbstractQuery::operator ==(Q)) &&
            fUpdateTime == Q.fUpdateTime &&
            fAgent      == Q.fAgent;
}

/*====================================================================================================================*/
