#ifndef REALESTATEQUERY_H
#define REALESTATEQUERY_H

/*
17.01.2016 Черевичко С.А.
Данный файл содержит базовый класс запроса по недвижимости
*/

#include <QVector>
#include <QDateTime>
#include <QString>


namespace RealEstate
{
    /** Тип запроса по недвижимости
    */
    enum QueryType
    {
        RENT_BUY, /**< Снять в аренду */
        RENT_SELL, /**< Сдать в аренду */
        BUY, /**< Купить */
        SELL /**< Продать */
    };


    /** Тип недвижимости
    */
    enum RealEstateType
    {
        ROOM = 0, /**< Комната */
        FLAT = 1, /**< Квартира */
        TOWNHOUSE = 2, /**< Таунхаус */
        COTTAGE = 3 /**< Коттедж */
    };
}

using namespace RealEstate;


/** Общий тип всех запросов покупки/аренды недвижимости
*/
class RealEstateQuery
{
private:
    QDateTime fCreateDate; // дата создания
    QueryType fQueryType; // тип запроса
    RealEstateType fRealEstateType; // тип объекта недвижимости
    QString fCity; // город, в котором расположен объект недвижимости
    QString fAddress; // адрес
    uint fPrice; // стоимость
    uint fFloorCount; // количество этажей
    uint fFirstFloor; // номер первого этажа, занимаемого объектом
    float fSquareTotal; // общая площадь
    QVector<float> fSquareKitchens; // площади кухонь (если их несколько)
    QVector<float> fSquareRooms; // площадь каждой комнаты
    QString fContactInfo; // контактная информация (для связи с автором запроса)
    QString fAddInfo; // дополнительная информация об объекте недвижимости

public:
    RealEstateQuery();
    virtual ~RealEstateQuery();

    /** Получение даты создания запроса
      @return Дата создания запроса
    */
    QDateTime createDate() const;
    /** Получение типа запроса
      @return Тип запроса
    */
    QueryType queryType() const;
    /** Получение типа недвижимости
      @return Тип недвижимости
    */
    RealEstateType realEstateType() const;
    /** Получение города, в котором расположен объект недвижимости
      @return Город, в котором расположен объект недвижимости
    */
    QString city() const;
    /** Получение адреса объекта недвижимости
      @return Адрес объекта недвижимости
    */
    QString address() const;
    /** Получение стоимости объекта недвижимости
      @return Стоимость объекта недвижимости
    */
    uint price() const;
    /** Получение количества этажей, занимаемых объектом недвижимости
      @return Количество этажей, занимаемых объектом недвижимости
    */
    uint floorCount() const;
    /** Получение номера первого этажа, занимаемого объектом недвижимости
      @return Номер первого этажа, занимаемого объектом недвижимости
    */
    uint firstFloor() const;
    /** Получение количества комнат объекта недвижимости
      @return Количество комнат объекта недвижимости
    */
    uint roomCount() const;
    /** Получение количества кухонь объекта недвижимости
      @return Количество кухонь объекта недвижимости
    */
    uint kitchenCount() const;
    /** Получение общей площади объекта недвижимости
      @return Общая площадь объекта недвижимости
    */
    float squareTotal() const;
    /** Получение площади кухни
      @param kitchenNum Порядковый номер кухни, площадь которой необходимо получить
      @return Площадь кухни
    */
    float squareKitchen(const uint kitchenNum) const;
    /** Получение площади комнаты
      @param roomNum Порядковый номер комнаты, площадь которой необходимо получить
      @return Площадь комнаты
    */
    float squareRoom(const uint roomNum) const;
    /** Получение контактной информации для связи с автором запроса
      @return Контактная информация для связи с автором запроса
    */
    QString contactInfo() const;
    /** Получение дополнительной информации об объекте недвижимости
      @return Дополнительная информация об объекте недвижимости
    */
    QString additionalInfo() const;

    /** Изменение даты создания запроса
        @param value Новая дата создания
    */
    void setCreateDate(const QDateTime value);
    /** Изменение типа запроса
        @param value Новый тип запроса
    */
    void setQueryType(const QueryType value);
    /** Изменение типа объекта недвижимости
        @param value Новый тип объекта недвижимости
    */
    void setRealEstateType(const RealEstateType value);
    /** Изменение города
        @param value Новый город
    */
    void setCity(const QString value);
    /** Изменение адреса
        @param value Новый адрес
    */
    void setAddress(const QString value);
    /** Изменение стоимости
        @param value Новая стоимость
    */
    void setPrice(const uint value);
    /** Изменение количества этажей
        @param value Новое количество этажей
    */
    void setFloorCount(const uint value);
    /** Изменение номера первого этажа, занимаемого объектом недвижимости
        @param value Новый номер первого этажа, занимаемого объектом недвижимости
    */
    void setFirstFloor(const uint value);
    /** Изменение количества кухонь
        @param value Новое количество кухонь
    */
    void setKitchenCount(const uint value);
    /** Изменение количества комнат
        @param value Новое количество комнат
    */
    void setRoomCount(const uint value);
    /** Изменение общей площади
        @param value Новое значение общей площади
    */
    void setSquareTotal(const float value);
    /** Изменение площади кухни
        @param kitchenNum Порядковый номер кухни, площадь которой необходимо изменить
        @param value Новое значение площади кухни
    */
    void setSquareKitchen(const uint kitchenNum, const float value);
    /** Изменение площади комнаты
        @param kitchenNum Порядковый номер комнаты, площадь которой необходимо изменить
        @param value Новое значение площади комнаты
    */
    void setSquareRoom(const uint roomNum, const float value);
    /** Изменение контактной информации для связи с автором запроса
        @param value Новая контактная информация для связи с автором запроса
    */
    void setContactInfo(const QString value);
    /** Изменение дополнительной информации об объекте недвижимости
        @param value Новая дополнительная информация об объекте недвижимости
    */
    void setAdditionalInfo(const QString value);

    /** Проверка, подходит ли запрос Q для данного запроса
        @param Q Запрос, с которым осуществляется сравнение
    */
    bool fits(const RealEstateQuery& Q) const;

    /** Проверка, являются ли запросы одинаковыми
        @param Q Запрос, с которым осуществляется сравнение
    */
    bool operator ==(const RealEstateQuery& Q) const;
    /** Копирование параметров запроса
        @param Q Запрос, из которого осуществляется копирование
    */
    RealEstateQuery& operator =(const RealEstateQuery& Q);
};


/** Преобразование типа запроса в строку
 * @param queryT Тип запроса, который необходимо преобразовать в строку
 * @returns Тип запроса в виде строки
 */
QString queryTypeToString(const QueryType& queryT);


/** Преобразование типа недвижимости в строку
 * @param rt Тип недвижимости, который необходимо преобразовать в строку
 * @returns Тип недвижимости в виде строки
 */
QString realEstateTypeToString(const RealEstateType& rt);


#endif // REALESTATEQUERY_H
