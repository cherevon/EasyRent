#ifndef REALESTATEQUERY_H
#define REALESTATEQUERY_H


#include <QObject>
#include <QMap>
#include "RealEstateObject.h"


enum QueryType
{
    /// Пустышка
    QUERY_NONE,
    /// Продажа
    QUERY_SELL,
    /// Покупка
    QUERY_BUY,
    /// Продажа в аренду
    QUERY_SELL_RENT,
    /// Покупка в аренду
    QUERY_BUY_RENT
};


/// Количество подходящих пар типов запросов в таблице
const int QUERY_MATCHES_COUNT = 6;
/// Таблица подходящих типов запросов
const QueryType QUERY_MATCHES_TABLE[6][2] =
    {
        {QUERY_SELL, QUERY_BUY},
        {QUERY_SELL, QUERY_BUY_RENT},
        {QUERY_SELL_RENT, QUERY_BUY_RENT},
        {QUERY_BUY, QUERY_SELL},
        {QUERY_BUY_RENT, QUERY_SELL},
        {QUERY_BUY_RENT, QUERY_SELL_RENT}
    };

/// Соответствие типов запросов и строк для их отображения
const QMap<QueryType, QString> QUERY_TYPE_STRINGS =
{
    {QUERY_SELL, QObject::tr("Продажа")},
    {QUERY_BUY, QObject::tr("Покупка")},
    {QUERY_SELL_RENT, QObject::tr("Продажа (аренда)")},
    {QUERY_BUY_RENT, QObject::tr("Покупка (аренда)")}
};


/// Запрос для поиска объекта недвижимости
class RealEstateQuery : public QObject
{
    Q_OBJECT

private:
    /// Идентификатор запроса
    QString fID;
    /// Тип запроса
    QueryType fQueryType;
    /// Дата создания запроса
    QDateTime fCreateDate;
    /// Стоимость объекта недвижимости
    uint fPrice;
    /// Источник, из которого получен запрос
    QString fSource;
    /// Параметры искомого объекта недвижимости
    RealEstateObject* fSearchObject;
    /// Информация о последней возникшей ошибке
    QString fLastError;

protected:
    /** Смена информации о последней возникшей ошибке
     * @param value Новая информация о последней возникшей ошибке
     */
    void setLastError(const QString &value);

public:
    explicit RealEstateQuery(QObject *parent = 0);

    /** Получение идентификатора запроса
     * @return Идентификатор запроса
     * @remarks Позволяет уникальным образом идентифицировать запрос в источнике
     */
    QString ID() const;
    /** Получение искомого объекта недвижимости
     * @return Искомый объект недвижимости
     */
    RealEstateObject *searchObject() const;
    /** Получение источника, из которого получен запрос
     * @return Источник, из которого получен запрос
     */
    QString source() const;
    /** Получение стоимости объекта недвижимости
     * @return Стоимость объекта недвижимости
     */
    uint price() const;
    /** Получение даты создания запроса
     * @return Дата создания запроса
     */
    QDateTime createDate() const;
    /** Получение типа запроса
     * @return Тип запроса
     */
    QueryType queryType() const;

    /** Смена идентификатора запроса
     * @param value Новый идентификатор запроса
     */
    void setID(const QString &value);
    /** Смена искомого объекта недвижимости
     * @param value Новый искомый объект недвижимости
     */
    void setSearchObject(RealEstateObject * const value);
    /** Смена даты создания запроса
     * @param value Новая дата создания запроса
     */
    void setCreateDate(const QDateTime &value);
    /** Смена стоимости объекта недвижимости
     * @param value Новая стоимость объекта недвижимости
     */
    void setPrice(const uint &value);
    /** Смена источника, из которого получен запрос
     * @param value Новый источник, из которого получен запрос
     */
    void setSource(const QString &value);
    /** Смена типа запроса
     * @param value Новый тип запроса
     */
    void setQueryType(const QueryType &value);

    /** Получение информации о последней возникшей ошибке
     * @return Информация о последней возникшей ошибке
     */
    QString lastError() const;
    /** Проверка подходит ли query для этого запроса
     * @param query Запрос по жилой недвижимости, с которым производится сравнение
     * @retval true query подходит для этого запроса
     * @retval false query не подходит для этого запроса
     */
    bool matches(const RealEstateQuery * const query) const;
    /** Присвоение параметрам этого запроса значений из запроса-источника
     * @param source запрос-источник
     * @retval true Присвоение параметров прошло успешно
     * @retval false Присвоение параметров не удалось. Информацию об ошибке можно узнать при помощи lastError
     * @remarks В случае неудачи присвоения параметров, состояние этого запроса не изменяется
     * @see lastError
     */
    virtual bool assign(const RealEstateQuery * const source);
};


/** Преобразование строки в тип запроса
 * @param str Строка, которую необходимо преобразовать к типу запроса
 * @return Тип запроса
 */
QueryType stringToQueryType(const QString & str);
/** Преобразование типа запроса в строку
 * @param queryt Тип запроса, который необходимо преобразовать в строку
 * @returns Тип запроса в виде строки
 */
QString queryTypeToString(const QueryType& queryt);
/** Получение строк для всех доступных типов запросов
 * @return Строки для всех доступных типов запросов
 */
QStringList availableQueryTypesStrings();


#endif // REALESTATEQUERY_H
