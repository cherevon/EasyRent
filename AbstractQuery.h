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
    enum QueryType {SDAM, SNIMU};       // тип запроса
}

using namespace Queries;

/*====================================================================================================================*/

class AbstractQuery
{
private:
    QueryType fType;                        // тип запроса (СДАМ/СНИМУ)
    QSet<QString> fAreas;                   // районы СПИСОК
    QSet<QString> fMetros;                  // станции метро СПИСОК
    uint    fRooms;                         // количество комнат
    QString fAddress;                       // адрес
    bool    fFurniture;                     // наличие мебели
    bool    fWasher;                        // наличие стиральной машины
    bool    fTelephone;                     // наличие телефона
    bool    fFridge;                        // наличие холодильника
    uint    fPrice;                         // стоимость
    uint    fPeriod;                        // срок
    QString fContact;                       // контактная информация
    QString fAddInfo;                       // дополнительная информация

    friend QDataStream& operator <<(QDataStream& stream, const AbstractQuery& Q);
    friend QDataStream& operator >>(QDataStream& stream, AbstractQuery& Q);

public:
    // порядок размещения полей запроса по умолчанию
    static QMap<QString, int> defaultColumnSequence;

    // количество полей в запросе
    static const int        ABSTR_QUERY_FIELD_COUNT = 13;

    // наименования полей для поиска по ассоциативному массиву
    static const QString    QUERY_TYPE_SIGN;
    static const QString    AREAS_SIGN;
    static const QString    METROS_SIGN;
    static const QString    ROOMS_SIGN;
    static const QString    ADDRESS_SIGN;
    static const QString    FURNITURE_SIGN;
    static const QString    WASHER_SIGN;
    static const QString    TELEPHONE_SIGN;
    static const QString    FRIDGE_SIGN;
    static const QString    PRICE_SIGN;
    static const QString    PERIOD_SIGN;
    static const QString    CONTACT_SIGN;
    static const QString    ADDITIONAL_INFO_SIGN;

    // CONSTRUCTORS & DESTRUCTORS
    AbstractQuery();
    virtual ~AbstractQuery();

    // FIELD ACCESS METHODS
    QueryType       queryType()             const           {return fType;}
    uint            rooms()                 const           {return fRooms;}
    QString         address()               const           {return fAddress;}
    bool            hasFurniture()          const           {return fFurniture;}
    bool            hasWasher()             const           {return fWasher;}
    bool            hasFridge()             const           {return fFridge;}
    bool            hasTelephone()          const           {return fTelephone;}
    uint            price()                 const           {return fPrice;}
    uint            period()                const           {return fPeriod;}
    QString         contact()               const           {return fContact;}
    QString         additionalInfo()        const           {return fAddInfo;}
    bool            hasArea(QString Area)   const           {return (fAreas.find(Area) != fAreas.end());}
    bool            hasMetro(QString Metro) const           {return (fMetros.find(Metro) != fMetros.end());}

    QSet<QString>   areas() const                           {return fAreas;}
    QSet<QString>   metros() const                          {return fMetros;}

    void            setQueryType(const QueryType Value)     {fType      = Value;}
    void            setRooms(const uint Value)              {fRooms     = Value;}
    void            setAddress(const QString Value)         {fAddress   = Value;}
    void            setFurniture(const bool Value)          {fFurniture = Value;}
    void            setWasher(const bool Value)             {fWasher    = Value;}
    void            setFridge(const bool Value)             {fFridge    = Value;}
    void            setTelephone(const bool Value)          {fTelephone = Value;}
    void            setPrice(const uint Value)              {fPrice     = Value;}
    void            setPeriod(const uint Value)             {fPeriod    = Value;}
    void            setContact(const QString Value)         {fContact   = Value;}
    void            setAdditionalInfo(const QString Value)  {fAddInfo   = Value;}
    void            setAreas(const QSet<QString> Value)     {fAreas     = Value;}
    void            setMetros(const QSet<QString> Value)    {fMetros    = Value;}

    // ОПЕРАТОРЫ
    bool operator ==(const AbstractQuery& Q);
    AbstractQuery& operator =(const AbstractQuery& Q);

    // МЕТОДЫ
    virtual void writeBinary(QFile& f) const = 0;   // запись данных в поток в двоичном виде
    virtual void readBinary(QFile &f);              // чтение данных из двоичного потока
    virtual bool writeInTableWidget(QTableWidget *table, const int row, const QMap<QString, int> *pColumnNames = NULL) const;
};

/*====================================================================================================================*/

#endif // ABSTRACTQUERY_H
