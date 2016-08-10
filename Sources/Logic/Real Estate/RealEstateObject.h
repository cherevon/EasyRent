#ifndef REALESTATEOBJECT_H
#define REALESTATEOBJECT_H


#include <QVector>
#include <QDateTime>
#include <QString>
#include <QList>
#include <QImage>
#include <QMap>


/// Тип недвижимости
enum RealEstateType
{
    /// Пустышка
    REALTY_NONE,
    /// Комната
    REALTY_ROOM,
    /// Квартира
    REALTY_FLAT,
    /// Таунхаус
    REALTY_TOWNHOUSE,
    /// Коттедж
    REALTY_COTTAGE
};


/// Соответствие типов недвижимости и строк для их отображения
const QMap<RealEstateType, QString> REAL_ESTATE_TYPE_STRINGS =
{
    {REALTY_ROOM, QObject::tr("Комната")},
    {REALTY_FLAT, QObject::tr("Квартира")},
    {REALTY_TOWNHOUSE, QObject::tr("Таунхаус")},
    {REALTY_COTTAGE, QObject::tr("Коттедж")}
};


/// Объект недвижимости
class RealEstateObject: public QObject
{
    Q_OBJECT

private:
    /// Тип объекта недвижимости
    RealEstateType fRealEstateType;
    /// Город, в котором расположен объект недвижимости
    QString fCity;
    /// Адрес, по которому расположен объект недвижимости
    QString fAddress;
    /// Количество занимаемых этажей
    uint fFloorCount;
    /// Номер первого занимаемого этажа
    uint fFirstFloor;
    /// Общая площадь
    float fTotalSquare;
    /// Площади всех помещений
    QVector<float> fRoomsSquare;
    /// Контактная информация для связи с владельцем объекта недвижимости
    QString fContactInfo;
    /// Дополнительные сведения
    QString fAdditionalInfo;
    /// Фотографии
    QList<QImage> fPhotos;
    /// Информация о последней возникшей ошибке
    QString fLastError;

protected:
    /** Смена информации о последней возникшей ошибке
     * @param value Новая информация о последней возникшей ошибке
     */
    void setLastError(const QString &value);

public:
    explicit RealEstateObject(QObject* parent = 0);

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
    /** Получение общей площади объекта недвижимости
      @return Общая площадь объекта недвижимости
    */
    float totalSquare() const;
    /** Получение площади указанной комнаты
      @param roomNum Порядковый номер комнаты, площадь которой необходимо получить
      @return Площадь указанной комнаты
    */
    float roomSquare(const uint &roomNum) const;
    /** Получение контактной информации для связи с автором запроса
      @return Контактная информация для связи с автором запроса
    */
    QString contactInfo() const;
    /** Получение дополнительной информации об объекте недвижимости
      @return Дополнительная информация об объекте недвижимости
    */
    QString additionalInfo() const;
    /** Получение количества фотографий объекта недвижимости
     * @return Количество фотографий объекта недвижимости
     */
    uint photoCount() const;
    /** Получение фотографии объекта недвижимости
     * @param photoNum Порядковый номер фотографии
     * @return Фотография объекта недвижимости с указанным порядковым номером
     */
    QImage photo(const uint &photoNum) const;
    /** Получение общей площади всех помещений
     * @return Общая площадь всех помещений
     */
    float totalRoomsSquare() const;

    /** Удаление фотографии
     * @param photoNum Порядковый номер удаляемой фотографии
     */
    void deletePhoto(const uint &photoNum);
    /** Добавление фотографии
     * @param value Добавляемая фотография
     */
    void addPhoto(const QImage &value);
    /** Изменение типа объекта недвижимости
        @param value Новый тип объекта недвижимости
    */
    void setRealEstateType(const RealEstateType &value);
    /** Изменение города
        @param value Новый город
    */
    void setCity(const QString &value);
    /** Изменение адреса
        @param value Новый адрес
    */
    void setAddress(const QString &value);
    /** Изменение количества этажей
        @param value Новое количество этажей
    */
    void setFloorCount(const uint &value);
    /** Изменение номера первого этажа, занимаемого объектом недвижимости
        @param value Новый номер первого этажа, занимаемого объектом недвижимости
    */
    void setFirstFloor(const uint &value);
    /** Изменение количества комнат
        @param value Новое количество комнат
    */
    void setRoomCount(const uint &value);
    /** Изменение общей площади объекта недвижимости
        @param value Новое значение общей площади
    */
    void setTotalSquare(const float &value);
    /** Изменение площади комнаты
        @param roomNum Порядковый номер комнаты, площадь которой необходимо изменить
        @param value Новое значение площади комнаты
    */
    void setRoomSquare(const uint &roomNum, const float &value);
    /** Изменение контактной информации для связи с автором запроса
        @param value Новая контактная информация для связи с автором запроса
    */
    void setContactInfo(const QString &value);
    /** Изменение дополнительной информации об объекте недвижимости
        @param value Новая дополнительная информация об объекте недвижимости
    */
    void setAdditionalInfo(const QString &value);

    /** Получение информации о последней возникшей ошибке
     * @return Информация о последней возникшей ошибке
     */
    QString lastError() const;
    /** Присвоение параметрам этого объекта недвижимости значений из объекта-источника
     * @param source Объект-источник
     * @retval true Присвоение параметров прошло успешно
     * @retval false Присвоение параметров не удалось. Информацию об ошибке можно узнать при помощи lastError
     * @remarks В случае неудачи присвоения параметров, состояние этого объекта недвижимости не изменяется
     * @see lastError
     */
    virtual bool assign(const RealEstateObject * const source);

    /** Проверка лучше ли этот объект недвижимости, чем other
     * @param other Объект недвижимости, с которым происходит сравнение
     * @retval true Этот объект недвижимости лучше other
     * @retval false Этот объект недвижимости не лучше other
     */
    virtual bool operator > (const RealEstateObject* const other);
    /** Проверка хуже ли этот объект недвижимости, чем other
     * @param other Объект недвижимости, с которым происходит сравнение
     * @retval true Этот объект недвижимости хуже other
     * @retval false Этот объект недвижимости не хуже other
     */
    virtual bool operator < (const RealEstateObject* const other);

signals:
    /// Сигнал, возникающий при изменении объекта недвижимости
    void changed();
};


/** Преобразование строки в тип недвижимости
 * @param rt Тип недвижимости в виде строки
 * @return Тип недвижимости, который соответствует указанной строке
 */
RealEstateType stringToRealEstateType(const QString & rt);
/** Преобразование типа недвижимости в строку
 * @param rt Тип недвижимости, который необходимо преобразовать в строку
 * @returns Тип недвижимости в виде строки
 */
QString realEstateTypeToString(const RealEstateType& rt);
/** Получение строк для всех доступных типов объектов недвижимости
 * @return Строки для всех доступных типов объектов недвижимости
 */
QStringList availableRealEstateTypesStrings();


#endif // REALESTATEOBJECT_H
