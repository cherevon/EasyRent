#include "RealEstateObject.h"


const QString ERR_NO_SOURCE_REAL_ESTATE_OBJECT = QObject::tr("Не указан объект-источник!");


void RealEstateObject::setLastError(const QString &value)
{
    fLastError = value;
}


RealEstateObject::RealEstateObject(QObject *parent): QObject(parent)
{
    fRealEstateType = REALTY_FLAT;
    fCity = "";
    fAddress = "";
    fFirstFloor = 1;
    fFloorCount = 1;
    fTotalSquare= 0.0;
    fRoomsSquare.resize(1);
    fRoomsSquare[0] = 0.0;
    fContactInfo = "";
    fAdditionalInfo = "";
}


RealEstateType RealEstateObject::realEstateType() const
{
    return fRealEstateType;
}


QString RealEstateObject::city() const
{
    return fCity;
}


QString RealEstateObject::address() const
{
    return fAddress;
}


uint RealEstateObject::floorCount() const
{
    return fFloorCount;
}


uint RealEstateObject::firstFloor() const
{
    return fFirstFloor;
}


uint RealEstateObject::roomCount() const
{
    return fRoomsSquare.size();
}


float RealEstateObject::totalSquare() const
{
    return fTotalSquare;
}


float RealEstateObject::roomSquare(const uint &roomNum) const
{
    return fRoomsSquare[roomNum];
}


QString RealEstateObject::contactInfo() const
{
    return fContactInfo;
}


QString RealEstateObject::additionalInfo() const
{
    return fAdditionalInfo;
}


uint RealEstateObject::photoCount() const
{
    return fPhotos.size();
}


QImage RealEstateObject::photo(const uint &photoNum) const
{
    return fPhotos[photoNum];
}


void RealEstateObject::deletePhoto(const uint &photoNum)
{
    fPhotos.removeAt(photoNum);
    emit changed();
}


void RealEstateObject::addPhoto(const QImage &value)
{
    fPhotos.append(value);
    emit changed();
}


void RealEstateObject::setRealEstateType(const RealEstateType &value)
{
    fRealEstateType = value;
    emit changed();
}


void RealEstateObject::setCity(const QString &value)
{
    fCity = value;
    emit changed();
}


void RealEstateObject::setAddress(const QString &value)
{
    fAddress = value;
    emit changed();
}


void RealEstateObject::setFloorCount(const uint &value)
{
    fFloorCount = value;
    emit changed();
}


void RealEstateObject::setFirstFloor(const uint &value)
{
    fFirstFloor = value;
    emit changed();
}


void RealEstateObject::setRoomCount(const uint &value)
{
    fRoomsSquare.resize(value);
    emit changed();
}


void RealEstateObject::setTotalSquare(const float &value)
{
    fTotalSquare = value;
    emit changed();
}


void RealEstateObject::setRoomSquare(const uint &roomNum, const float &value)
{
    fRoomsSquare[roomNum] = value;
    emit changed();
}


void RealEstateObject::setContactInfo(const QString &value)
{
    fContactInfo = value;
    emit changed();
}


void RealEstateObject::setAdditionalInfo(const QString &value)
{
    fAdditionalInfo = value;
    emit changed();
}


QString RealEstateObject::lastError() const
{
    return fLastError;
}


bool RealEstateObject::assign(const RealEstateObject * const source)
{
    // проверяем возможность выполнения операции
    if (source == NULL)
    {
        setLastError(ERR_NO_SOURCE_REAL_ESTATE_OBJECT);
        return false;
    }

    // копирование основной информации об объекте недвижимости
    fRealEstateType = source->fRealEstateType;
    fCity = source->fCity;
    fAddress = source->fAddress;
    fFloorCount = source->fFloorCount;
    fFirstFloor = source->fFirstFloor;
    fTotalSquare = source->fTotalSquare;
    fContactInfo = source->fContactInfo;
    fAdditionalInfo = source->fAdditionalInfo;

    // копирование информации о помещениях
    fRoomsSquare.clear();
    fRoomsSquare.append(source->fRoomsSquare);

    // копирование фотографий
    fPhotos.clear();
    fPhotos.append(source->fPhotos);

    emit changed();
    return true;
}


float RealEstateObject::totalRoomsSquare() const
{
    float res = 0;
    foreach(float roomSquare, fRoomsSquare)
    {
        res += roomSquare;
    }
    return res;
}


bool RealEstateObject::operator >(const RealEstateObject * const other)
{
    return fTotalSquare > other->fTotalSquare;
}


bool RealEstateObject::operator <(const RealEstateObject * const other)
{
    return fTotalSquare < other->fTotalSquare;
}


QString realEstateTypeToString(const RealEstateType& rt)
{
    QMap<RealEstateType, QString>::ConstIterator iter;
    for(iter = REAL_ESTATE_TYPE_STRINGS.constBegin(); iter != REAL_ESTATE_TYPE_STRINGS.constEnd(); ++iter)
    {
        if (iter.key() == rt)
            return iter.value();
    }

    return QString();
}


QStringList availableRealEstateTypesStrings()
{
    QStringList result;
    QMap<RealEstateType, QString>::ConstIterator iter;
    for(iter = REAL_ESTATE_TYPE_STRINGS.constBegin(); iter != REAL_ESTATE_TYPE_STRINGS.constEnd(); ++iter)
        result << iter.value();

    return result;
}


RealEstateType stringToRealEstateType(const QString &rt)
{
    QMap<RealEstateType, QString>::ConstIterator iter;
    for(iter = REAL_ESTATE_TYPE_STRINGS.constBegin(); iter != REAL_ESTATE_TYPE_STRINGS.constEnd(); ++iter)
    {
        if (rt.compare(iter.value(), Qt::CaseInsensitive) == 0)
            return iter.key();
    }

    return REALTY_NONE;
}
