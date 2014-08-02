#ifndef GLOBALDATAMANAGER_H
#define GLOBALDATAMANAGER_H

#include <QMap>
#include <QList>
#include <QStringList>
#include "Queries.h"

class GlobalDataManager
{
private:
    QMap<QString, int>      fAreas;         // перечень доступных для выбора районов
    QMap<QString, int>      fMetros;        // перечень доступных для выбора станций метро
//    QList<AbstractQuery*>   fPQs;           // перечень пользовательских приоритетных запросов

    GlobalDataManager();
    GlobalDataManager(const GlobalDataManager& M);
    GlobalDataManager& operator=(GlobalDataManager& M);
    ~GlobalDataManager();

public:
    static GlobalDataManager Instance;
    QStringList             availableAreas();       // получить перечень всех доступных для выбора районов
    QStringList             availableMetros();      // получить перечень всех доступных для выбора станций метро
//    QList<AbstractQuery*> &PQs();                  // получить перечень всех пользовательских приоритетных запросов
};

#endif // GLOBALDATAMANAGER_H
