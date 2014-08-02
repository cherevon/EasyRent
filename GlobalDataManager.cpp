#include "GlobalDataManager.h"

/*============================================================================================*/

GlobalDataManager GlobalDataManager::Instance;

/*============================================================================================*/

GlobalDataManager::GlobalDataManager()
{
    // инициализация районов
    fAreas["Адмиралтейский"]      = 0;
    fAreas["Выборгский"]          = 0;
    fAreas["Василеостровский"]    = 0;
    fAreas["Калининский"]         = 0;
    fAreas["Кировский"]           = 0;
    fAreas["Красногвардейский"]   = 0;
    fAreas["Красносельский"]      = 0;
    fAreas["Московский"]          = 0;
    fAreas["Невский"]             = 0;
    fAreas["Петроградский"]       = 0;
    fAreas["Приморский"]          = 0;
    fAreas["Фрунзенский"]         = 0;
    fAreas["Центральный"]         = 0;
    fAreas["Область"]             = 0;
    fAreas["Всеволожский"]        = 0;
    fAreas["Колпинский"]          = 0;
    fAreas["Кронштадтский"]       = 0;
    fAreas["Курортный"]           = 0;
    fAreas["Петродворцовый"]      = 0;
    fAreas["Пушкинский"]          = 0;

    // инициализация станций метро
    fMetros["Автово"]               = 0;
    fMetros["Адмиралтейская"]       = 0;
    fMetros["Академическая"]        = 0;
    fMetros["Балтийская"]           = 0;
    fMetros["Бухарестская"]         = 0;
    fMetros["Василеостровская"]     = 0;
    fMetros["Владимирская"]         = 0;
    fMetros["Волковская"]           = 0;
    fMetros["Выборгская"]           = 0;
    fMetros["Горьковская"]          = 0;
    fMetros["Гостиный двор"]        = 0;
    fMetros["Гражданский пр."]      = 0;
    fMetros["Девяткино"]            = 0;
    fMetros["Достоевская"]          = 0;
    fMetros["Елизаровская"]         = 0;
    fMetros["Звездная"]             = 0;
    fMetros["Звенигородская"]       = 0;
    fMetros["Кировский завод"]      = 0;
    fMetros["Комендантский пр."]    = 0;
    fMetros["Крестовский о-в"]      = 0;
    fMetros["Купчино"]              = 0;
    fMetros["Ладожская"]            = 0;
    fMetros["Ленинский пр."]        = 0;
    fMetros["Лесная"]               = 0;
    fMetros["Лиговский пр."]        = 0;
    fMetros["Ломоносовская"]        = 0;
    fMetros["Маяковская"]           = 0;
    fMetros["Международная"]        = 0;
    fMetros["Московская"]           = 0;
    fMetros["Московские ворота"]    = 0;
    fMetros["Нарвская"]             = 0;
    fMetros["Невский пр."]          = 0;
    fMetros["Новочеркасская"]       = 0;
    fMetros["Обводный канал"]       = 0;
    fMetros["Обухово"]              = 0;
    fMetros["Озерки"]               = 0;
    fMetros["Парк победы"]          = 0;
    fMetros["Парнас"]               = 0;
    fMetros["Петроградская"]        = 0;
    fMetros["Пионерская"]           = 0;
    fMetros["пл. Ал. Невского"]     = 0;
    fMetros["пл. Восстания"]        = 0;
    fMetros["пл. Ленина"]           = 0;
    fMetros["пл. Мужества"]         = 0;
    fMetros["Политехническая"]      = 0;
    fMetros["пр. Большевиков"]      = 0;
    fMetros["пр. Ветеранов"]        = 0;
    fMetros["пр. Просвещения"]      = 0;
    fMetros["Приморская"]           = 0;
    fMetros["Пролетарская"]         = 0;
    fMetros["Пушкинская"]           = 0;
    fMetros["Рыбацкое"]             = 0;
    fMetros["Садовая"]              = 0;
    fMetros["Сенная пл."]           = 0;
    fMetros["Спасская"]             = 0;
    fMetros["Спортивная"]           = 0;
    fMetros["Старая деревня"]       = 0;
    fMetros["Технологический ин-т"] = 0;
    fMetros["Удельная"]             = 0;
    fMetros["ул. Дыбенко"]          = 0;
    fMetros["Фрунзенская"]          = 0;
    fMetros["Черная речка"]         = 0;
    fMetros["Чернышевская"]         = 0;
    fMetros["Чкаловская"]           = 0;
    fMetros["Электросила"]          = 0;
}

/*============================================================================================*/

GlobalDataManager::~GlobalDataManager()
{
    // сохранение приоритетных запросов
//    QFile PQFile("I:\\priorities.pq");
//    if (PQFile.open(QIODevice::WriteOnly))
//    {
//        QList<AbstractQuery*>::iterator iter;
//        for(iter = fPQs.begin(); iter != fPQs.end(); ++iter)
//            (*iter)->writeBinary(PQFile);
//        PQFile.close();
//    }
}

/*============================================================================================*/

QStringList GlobalDataManager::availableAreas()
{
    QStringList result;

    QMap<QString, int>::const_iterator iter;
    for(iter = fAreas.constBegin(); iter != fAreas.constEnd(); ++iter)
        result.push_back(iter.key());

    return result;
}

/*============================================================================================*/

QStringList GlobalDataManager::availableMetros()
{
    QStringList result;

    QMap<QString, int>::const_iterator iter;
    for(iter = fMetros.constBegin(); iter != fMetros.constEnd(); ++iter)
        result.push_back(iter.key());

    return result;
}

/*============================================================================================*/

//QList<AbstractQuery *> &GlobalDataManager::PQs()
//{
//    return fPQs;
//}

/*============================================================================================*/
