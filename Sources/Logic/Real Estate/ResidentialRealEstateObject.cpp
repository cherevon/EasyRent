#include "ResidentialRealEstateObject.h"


const QString ERR_INCORRECT_SOURCE_OBJECT_TYPE = QObject::tr("Некорректный тип объекта-источника!");


ResidentialRealEstateObject::ResidentialRealEstateObject(QObject *parent) : RealEstateObject(parent)
{
    fKitchensSquare.resize(1);
}


uint ResidentialRealEstateObject::kitchenCount()
{
    return fKitchensSquare.size();
}


float ResidentialRealEstateObject::kitchenSquare(const int &kitchenNum)
{
    return fKitchensSquare[kitchenNum];
}


float ResidentialRealEstateObject::totalKitchensSquare()
{
    float totalSquare = 0.0;
    foreach(float square, fKitchensSquare)
        totalSquare += square;
    return totalSquare;
}


void ResidentialRealEstateObject::setKitchenCount(const float &value)
{
    fKitchensSquare.resize(value);
}


void ResidentialRealEstateObject::setKitchenSquare(const int &kitchenNum, const float &value)
{
    fKitchensSquare[kitchenNum] = value;
}


bool ResidentialRealEstateObject::assign(const RealEstateObject * const source)
{
    bool result = RealEstateObject::assign(source);
    if (!result)
        return result;

    // проверяем корректность типа объекта-источника
    const ResidentialRealEstateObject* const correctSource = qobject_cast<const ResidentialRealEstateObject * const>(source);
    if (correctSource == NULL)
    {
        setLastError(ERR_INCORRECT_SOURCE_OBJECT_TYPE);
        return false;
    }

    // копирование информации о кухнях
    fKitchensSquare.clear();
    fKitchensSquare.append(correctSource->fKitchensSquare);

    return true;
}
