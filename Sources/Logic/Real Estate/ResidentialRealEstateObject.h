#ifndef RESIDENTIALREALESTATEOBJECT_H
#define RESIDENTIALREALESTATEOBJECT_H


#include <QVector>
#include "RealEstateObject.h"


/// Объект жилой недвижимости
class ResidentialRealEstateObject : public RealEstateObject
{
    Q_OBJECT

private:
    /// Площади кухонь
    QVector<float> fKitchensSquare;

public:
    explicit ResidentialRealEstateObject(QObject *parent = 0);

    /** Получение количества кухонь
     * @return Количество кухонь
     */
    uint kitchenCount();
    /** Получение площади кухни
     * @param kitchenNum Порядковый номер кухни
     * @return Площадь указанной кухни
     */
    float kitchenSquare(const int &kitchenNum);
    /** Получение суммарной площади всех кухонь
     * @return Суммарная площадь всех кухонь
     */
    float totalKitchensSquare();

    /** Смена количества кухонь
     * @param value Новое количество кухонь
     * @remarks При увеличении количества кухонь, площади добавленных ранее кухонь сохранятся
     */
    void setKitchenCount(const float &value);
    /** Смена площади кухни
     * @param kitchenNum Порядковый номер кухни
     * @param value Новое значение площади кухни
     */
    void setKitchenSquare(const int &kitchenNum, const float &value);

    bool assign(const RealEstateObject * const source);
};


#endif // RESIDENTIALREALESTATEOBJECT_H
