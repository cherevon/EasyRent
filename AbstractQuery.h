#ifndef ABSTRACTQUERY_H
#define ABSTRACTQUERY_H

#include <QList>
#include <QSet>
#include <QString>
#include <QFile>
#include <QDataStream>
#include <QTableWidget>
#include "Tools/ContainerUtils.h"

/*====================================================================================================================*/

namespace Queries
{
    enum QueryType {SDAM, SNIMU, KUPLU, PRODAM};    // тип запроса
    enum TriStateBool {YES, NO, NO_MATTER};         // bool c тремя возможными состояниями
}

using namespace Queries;

/*====================================================================================================================*/

class AbstractQuery
{
private:
    QString         fCity;      // город
    QueryType       fType;      // тип запроса (СДАМ/СНИМУ/ПРОДАМ/КУПЛЮ)
    QSet<QString>   fAreas;     // районы СПИСОК
    QSet<QString>   fMetros;    // станции метро СПИСОК
    TriStateBool    fFurniture; // наличие мебели
    TriStateBool    fWasher;    // наличие стиральной машины
    TriStateBool    fTelephone; // наличие телефона
    TriStateBool    fFridge;    // наличие холодильника
    uint            fBasePrice; // стоимость
    uint            fPeriod;    // срок
    uint            fRoomCount; // количество комнат
    float           fSquareTotal; // общая площадь
    float           fSquareKitchen; // площадь кухни
    float           fSquareLive; // жилая площадь
    bool            fPeriodLong;// является ли требуемый срок длительным (год и более)
    QString         fAddInfo;   // дополнительная информация о запросе

public:
    // CONSTRUCTORS & DESTRUCTORS
    AbstractQuery();
    virtual ~AbstractQuery();

    // FIELD ACCESS METHODS
    QueryType       queryType()             const   {return fType;}
    bool            hasFurniture()          const   {return fFurniture;}
    bool            hasWasher()             const   {return fWasher;}
    bool            hasFridge()             const   {return fFridge;}
    bool            hasTelephone()          const   {return fTelephone;}
    uint            period()                const   {return fPeriod;}
    bool            isPeriodLong()          const   {return fPeriodLong;}
    uint            basePrice()             const   {return fBasePrice;}
    bool            hasArea(QString Area)   const   {return (fAreas.find(Area) != fAreas.end());}
    bool            hasMetro(QString Metro) const   {return (fMetros.find(Metro) != fMetros.end());}
    uint            roomCount()             const   {return fRoomCount;}
    uint            squareTotal()           const   {return fSquareTotal;}
    uint            squareKitchen()         const   {return fSquareKitchen;}
    uint            squareLive()            const   {return fSquareLive;}
    QString         additionalInfo()        const   {return fAddInfo;}
    QSet<QString>   areas()                 const   {return fAreas;}
    QSet<QString>   metros()                const   {return fMetros;}

    void            setQueryType(const QueryType Value)     {fType      = Value;}
    void            setFurniture(const TriStateBool Value)  {fFurniture = Value;}
    void            setWasher(const TriStateBool Value)     {fWasher    = Value;}
    void            setFridge(const TriStateBool Value)     {fFridge    = Value;}
    void            setTelephone(const TriStateBool Value)  {fTelephone = Value;}
    void            setPeriod(const uint Value)             {(Value < 12)?fPeriod = Value:fPeriodLong = true;}
    void            setAreas(const QSet<QString> Value)     {fAreas     = Value;}
    void            setMetros(const QSet<QString> Value)    {fMetros    = Value;}
    void            setBasePrice(const uint Value)          {fBasePrice = Value;}
    void            setRoomCount(const uint Value)          {(Value == 0)?fRoomCount = 1:fRoomCount = Value;}
    void            setSquareTotal(const float Value)       {fSquareTotal = Value;}
    void            setSquareKitchen(const float Value)     {fSquareKitchen = Value;}
    void            setSquareLive(const float Value)        {fSquareLive = Value;}
    void            setAdditionalInfo(const QString Value)  {fAddInfo = Value;}

    // ОПЕРАТОРЫ
    bool operator ==(const AbstractQuery& Q);
    AbstractQuery& operator =(const AbstractQuery& Q);
};

/*====================================================================================================================*/

#endif // ABSTRACTQUERY_H
