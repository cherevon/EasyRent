#ifndef REALESTATEQUERY_H
#define REALESTATEQUERY_H

/*
17.01.2016 Черевичко С.А.
Данный модуль содержит базовый класс запроса по недвижимости
*/

#include <vector>


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
    enum ObjectType
    {
        ROOM, /**< Комната */
        FLAT, /**< Квартира */
        COTTAGE, /**< Коттедж */
        TOWNHOUSE /**< Таунхаус */
    };
}

using namespace RealEstate;
using namespace std;
typedef unsigned int uint;
typedef unsigned float ufloat;


/** Общий тип всех запросов покупки/аренды недвижимости
*/
class RealEstateQuery
{
private:
    time_t fCreateDate; // дата создания
    QueryType fQueryType; // тип запроса
    ObjectType fObjectType; // тип объекта недвижимости
    string fCity; // город, в котором расположен объект недвижимости
    string fAddress; // адрес
    uint fPrice; // стоимость
    uint fFloorCount; // количество этажей
    uint fFirstFloor; // номер первого этажа, занимаемого объектом
    uint fRoomCount; // количество комнат
    uint fKitchenCount; // количество кухонь
    ufloat fSquareTotal; // общая площадь
    vector<ufloat> fSquareKitchens; // площади кухонь (если их несколько)
    vector<ufloat> fSquareRooms; // площадь каждой комнаты
    string fContactInfo; // контактная информация (для связи с автором запроса)
    string fAddInfo; // дополнительная информация об объекте недвижимости

public:
    RentQuery();
    virtual ~RentQuery();

    /** Получение даты создания запроса
      @return Дата создания запроса
    */
    time_t createDate() const;
    /** Получение типа запроса
      @return Тип запроса
    */
    QueryType queryType() const;
    /** Получение типа недвижимости
      @return Тип недвижимости
    */
    ObjectType objectType() const;
    /** Получение города, в котором расположен объект недвижимости
      @return Город, в котором расположен объект недвижимости
    */
    string city() const;
    /** Получение адреса объекта недвижимости
      @return Адрес объекта недвижимости
    */
    string address() const;
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
    ufloat squareTotal() const;
    /** Получение площади кухни
      @param kitchenNum Порядковый номер кухни, площадь которой необходимо получить
      @return Площадь кухни
    */
    ufloat squareKitchen(const uint kitchenNum) const;
    /** Получение площади комнаты
      @param roomNum Порядковый номер комнаты, площадь которой необходимо получить
      @return Площадь комнаты
    */
    ufloat squareRoom(const uint roomNum) const;
    /** Получение контактной информации для связи с автором запроса
      @return Контактная информация для связи с автором запроса
    */
    string contactInfo() const;
    /** Получение дополнительной информации об объекте недвижимости
      @return Дополнительная информация об объекте недвижимости
    */
    string additionalInfo() const;




    /** Изменение даты создания запроса
        @param value Новая дата создания
    */
    void setCreateDate(const time_t value);
    /** Изменение типа запроса
        @param value Новый тип запроса
    */
    void setQueryType(const QueryType value);
    /** Изменение типа объекта недвижимости
        @param value Новый тип объекта недвижимости
    */
    void setObjectType(const ObjectType value);
    /** Изменение города
        @param value Новый город
    */
    void setCity(const string value);
    /** Изменение адреса
        @param value Новый адрес
    */
    void setAddress(const string value);
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
    void setSquareTotal(const ufloat value);
    /** Изменение площади кухни
        @param kitchenNum Порядковый номер кухни, площадь которой необходимо изменить
        @param value Новое значение площади кухни
    */
    void setSquareKitchen(const uint kitchenNum, const ufloat value);
    /** Изменение площади комнаты
        @param kitchenNum Порядковый номер комнаты, площадь которой необходимо изменить
        @param value Новое значение площади комнаты
    */
    void setSquareRoom(const uint roomNum, const ufloat value);
    /** Изменение контактной информации для связи с автором запроса
        @param value Новая контактная информация для связи с автором запроса
    */
    void setContactInfo(const string value);
    /** Изменение дополнительной информации об объекте недвижимости
        @param value Новая дополнительная информация об объекте недвижимости
    */
    void setAdditionalInfo(const string value);

    // проверка подходит ли указанный запрос для данного
    bool matches(RealEstateQuery* query);

    // проверка запросов на идентичность
    bool operator ==(const RealEstateQuery& Q);
    // копирование параметров из запроса, указанного в параметре
    RealEstateQuery& operator =(const RealEstateQuery& Q);
};

/*====================================================================================================================*/

#endif // REALESTATEQUERY_H