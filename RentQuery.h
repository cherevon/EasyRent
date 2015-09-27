#ifndef RENTQUERY_H
#define RENTQUERY_H

/*
01.09.2015 Черевичко С.А.
Данный модуль содержит класс запроса аренды (СДАМ/СНИМУ)
*/

#include <QList>
#include <QSet>
#include <QString>
#include <QFile>
#include <QDateTime>


namespace RealEstate
{
    enum RentQueryType {SDAM, SNIMU};    // тип запроса аренды
    enum TriStateBool {YES, NO, NO_MATTER};         // bool c тремя возможными состояниями
    enum RealEstateObjectType {Room, Flat, Elite};   // тип объекта
}

using namespace RealEstate;


// общий тип для всех запросов покупки/аренды недвижимости
class RentQuery
{
private:
    QDateTime fCreateDate; // дата создания
    RentQueryType fQueryType; // тип запроса
    RealEstateObjectType fObjectType; // тип искомого объекта
    uint fPriceFrom; // стоимость от
    uint fPriceTo; // стоимость до
    uint fRoomCount; // количество комнат
    float fSquareTotal; // общая площадь
    float fSquareKitchen; // площадь кухни
    float fSquareLive; // жилая площадь
    uint fPeriod; // срок аренды (только СДАМ и СНИМУ)
    QSet<QString> fCities; // города, в которых доступен запрос
    QSet<QString> fAreas; // районы городов, в которых доступен запрос
    QSet<QString> fMetros; // станции метро

public:
    RentQuery();
    virtual ~RentQuery();

    QDateTime createDate() const {return fCreateDate;}
    RentQueryType queryType() const {return fQueryType;}
    RealEstateObjectType objectType() const {return fObjectType;}
    uint priceFrom() const {return fPriceFrom;}
    uint priceTo() const {return fPriceTo;}
    uint roomCount() const {return fRoomCount;}
    float squareTotal() const {return fSquareTotal;}
    float squareKitchen() const {return fSquareKitchen;}
    float squareLive() const {return fSquareLive;}
    uint period() const {return fPeriod;}
    QSet<QString> cities() const {return fCities;}
    QSet<QString> areas() const {return fAreas;}
    QSet<QString> metros() const {return fMetros;}

    void createDate(const QDateTime value) {fCreateDate = value;}
    void queryType(const RentQueryType value) {fQueryType = value;}
    void objectType(const RealEstateObjectType value) {fObjectType = value;}
    void priceFrom(const uint value) {fPriceFrom = value;}
    void priceTo(const uint value) {fPriceTo = value;}
    void roomCount(const uint value) {fRoomCount = value;}
    void squareTotal(const float value) {fSquareTotal = value;}
    void squareKitchen(const float value) {fSquareKitchen = value;}
    void squareLive(const float value) {fSquareLive = value;}
    void period(const uint value) {fPeriod = value;}
    void cities(const QSet<QString> value) {fCities = value;}
    void areas(const QSet<QString> value) {fAreas = value;}
    void metros(const QSet<QString> value) {fMetros = value;}

    // проверка подходит ли указанный запрос для данного
    bool matches(RentQuery* query);

    // ОПЕРАТОРЫ
    bool operator ==(const RentQuery& Q);
    RentQuery& operator =(const RentQuery& Q);
};

/*====================================================================================================================*/

#endif // RENTQUERY_H
