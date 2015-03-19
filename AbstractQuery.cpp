#include "AbstractQuery.h"

/*====================================================================================================================*/

AbstractQuery::AbstractQuery()
{
    fType       = SDAM;
    fAreas      = QSet<QString>();
    fMetros     = QSet<QString>();
    fRoomCount  = 1;
    fCity       = "";
    fFurniture  = fWasher = fFridge = fTelephone = Queries::NO_MATTER;
    fBasePrice  = 10000;
    fAddInfo    = "";
    fPeriodLong = true;
    fSquareKitchen = 0.0;
    fSquareLive = 0.0;
    fSquareTotal = 0.0;
}

/*====================================================================================================================*/

AbstractQuery::~AbstractQuery()
{
    fAreas.clear();
    fMetros.clear();
}

/*====================================================================================================================*/

bool AbstractQuery::operator ==(const AbstractQuery& Q)
{
    if (this == &Q) return true;
    return (
                fCity       == Q.fCity &&
                fType       == Q.fType &&
                fFurniture  == Q.fFurniture &&
                fWasher     == Q.fWasher &&
                fFridge     == Q.fFridge &&
                fTelephone  == Q.fTelephone &&
                ((fPeriod == Q.fPeriod) || (fPeriodLong == (Q.fPeriodLong == true))) &&
                fBasePrice  == Q.fBasePrice &&
                fRoomCount  == Q.fRoomCount &&
                fSquareKitchen == Q.fSquareKitchen &&
                fSquareLive == Q.fSquareLive &&
                fSquareTotal == Q.fSquareTotal &&
                fAddInfo    == Q.fAddInfo &&
                fAreas      == Q.fAreas &&
                fMetros     == Q.fMetros
            );
}

/*====================================================================================================================*/

AbstractQuery& AbstractQuery::operator =(const AbstractQuery& Q)
{
    if (this == &Q) return *this;
    fCity       = Q.fCity;
    fType       = Q.fType;
    fAreas      = Q.fAreas;
    fMetros     = Q.fMetros;
    fFurniture  = Q.fFurniture;
    fWasher     = Q.fWasher;
    fFridge     = Q.fFridge;
    fTelephone  = Q.fTelephone;
    fPeriod     = Q.fPeriod;
    fPeriodLong = Q.fPeriodLong;
    fBasePrice  = Q.fBasePrice;
    fRoomCount  = Q.fRoomCount;
    fSquareTotal = Q.fSquareTotal;
    fSquareKitchen = Q.fSquareKitchen;
    fSquareLive = Q.fSquareLive;
    fAddInfo    = Q.fAddInfo;

    return *this;
}

/*====================================================================================================================*/
