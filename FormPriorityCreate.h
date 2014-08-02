#ifndef FORMPRIORITYCREATE_H
#define FORMPRIORITYCREATE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QSpinBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QListWidget>
#include <QLabel>
#include <QStringList>
#include <QLineEdit>
#include <QtAlgorithms>
#include <math.h>
#include "Queries.h"

class FormPriorityCreate : public QWidget
{
    Q_OBJECT
private:
    QPushButton     *bCreatePQ;     // "Создать приоритетный запрос"
    QGroupBox       *gbType;        // группа радиокнопок "Тип"
    QRadioButton    *rbSdam;        // "Сдам" (группа "Тип")
    QRadioButton    *rbSnimu;       // "Сниму" (группа "Тип")
    QGroupBox       *gbObject;      // группа радиокнопок "Объект"
    QRadioButton    *rbFlat;        // "Квартира" (группа "Объект")
    QRadioButton    *rbRoom;        // "Комната" (группа "Объект")
    QRadioButton    *rbElite;       // "Элитное" (группа "Объект")
    QSpinBox        *eRoomsCount;   // "Количество комнат"
    QListWidget     *lwAreas;       // "Районы"
    QListWidget     *lwMetros;      // "Метро"
    QCheckBox       *cbTelephone;   // "Телефон"
    QCheckBox       *cbFridge;      // "Холодильник"
    QCheckBox       *cbWasher;      // "Стиральная машина"
    QCheckBox       *cbFurniture;   // "Мебель"
    QGroupBox       *gbFeatures;    // группа условий (хол - тел - мебель - стиралка)
    QGroupBox       *gbPeriod;      // группа "Срок"
    QSpinBox        *ePeriod;       // Срок (поле ввода)
    QCheckBox       *cbLongPeriod;  // "Длительный срок"
    QSpinBox        *ePrice;        // "Стоимость"
    QLineEdit       *eContact;      // "Контакт"
    QLineEdit       *eAddInfo;      // "Дополнительная информация"
    QLineEdit       *eAddress;      // "Адрес"

    void createWndComponents();

public:
    explicit FormPriorityCreate(QWidget *parent = 0);
    explicit FormPriorityCreate(PriorityQuery *PQ, QWidget *parent = 0);

signals:
    void newPQCreated();

public slots:
    void bCreatePQPressed();                    // нажатие кнопки "Создать приоритетный запрос"
    void setPriorityQuery(PriorityQuery* PQ);   // заполнение формы данными из приоритетного запроса

};

#endif // FORMPRIORITYCREATE_H
