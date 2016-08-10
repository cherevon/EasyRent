#ifndef APPLICATIONCORE_H
#define APPLICATIONCORE_H


#include <QObject>
#include "UserInterface.h"


/** Ядро приложения
 * @details Представляет собой контейнер, содержащий все ключевые системы,
 * которые могут быть использованы в работе приложения
 */
class ApplicationCore : public QObject
{
    Q_OBJECT

private:
    explicit ApplicationCore(QObject *parent = 0);

public:
    /** Получение объекта класса
     * @return
     */
    static ApplicationCore getInstance();

signals:
    /** Сигнал при смене пользовательского интерфейса
     * @param ui Новый пользовательский интерфейс
     */
    void userInterfaceChanged(UserInterface* ui);
};


#endif // APPLICATIONCORE_H
