#ifndef FORMPRIORITYCREATE_H
#define FORMPRIORITYCREATE_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class FormPriorityCreate;
}

class FormPriorityCreate : public QWidget
{
    Q_OBJECT

public:
    explicit FormPriorityCreate(QWidget *parent = 0);
    ~FormPriorityCreate();

private:
    Ui::FormPriorityCreate *ui;
private slots:
    // загрузка перечня станций метро для города с указанным названием
    void loadMetros(QString cityName);
    // загрузка перечня районов для города с указанным названием
    void loadAreas(QString cityName);
    // сохранение приоритетного запроса
    void savePQ();
};

#endif // FORMPRIORITYCREATE_H
