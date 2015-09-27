#include "RentQuery.h"

RentQuery::RentQuery()
{
    fCreateDate = QDateTime::currentDateTime();
    fQueryType  = SDAM;
    fObjectType = Flat;
    fPriceFrom = 0;
    fPriceTo = 10000;
    fRoomCount = 1;
    fSquareTotal = 0.0;
    fSquareKitchen = 0.0;
    fSquareLive = 0.0;
    fPeriod = 12;
    fCities = QSet<QString>();
    fAreas = QSet<QString>();
    fMetros = QSet<QString>();
}

RentQuery::~RentQuery()
{
}

bool RentQuery::matches(RentQuery *query)
{
    bool result;
    // запросы должны быть противополжных типов
    result = query->fObjectType != fObjectType;
}
