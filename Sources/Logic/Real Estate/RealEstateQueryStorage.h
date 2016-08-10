#ifndef REALESTATEQUERYSTORAGE_H
#define REALESTATEQUERYSTORAGE_H


#include <QList>
#include "RealEstateQuery.h"


/// Хранилище пользовательских запросов для поиска недвижимости
class RealEstateQueryStorage
{
public:
    /** Сохранение запроса
     * @param query Сохраняемый запрос
     */
    virtual void save(const RealEstateQuery* const query) const = 0;
    /** Сохранение запросов
     * @param queries Сохраняемые запросы
     */
    virtual void save(const QList<RealEstateQuery*> queries) const = 0;

    /** Загрузка запроса
     * @param queryID Идентификатор загружаемого запроса
     * @return Загруженный запрос с идентификатором queryID
     */
    virtual RealEstateQuery* load(const int queryID) const = 0;
    /** Загрузка всех запросов
     * @return Все запросы
     */
    virtual QList<RealEstateQuery*> loadAll() const = 0;
};


#endif // REALESTATEQUERYSTORAGE_H
