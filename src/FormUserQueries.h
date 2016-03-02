#ifndef FORMUSERQUERIES_H
#define FORMUSERQUERIES_H

#include <QWidget>
#include <QStringListModel>
#include "RealEstateQueryModel.h"

namespace Ui {
class FormUserQueries;
}

class FormUserQueries : public QWidget
{
    Q_OBJECT

public:
    explicit FormUserQueries(QWidget *parent = 0);
    ~FormUserQueries();

    void refreshData();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::FormUserQueries *ui;

public slots:
    void newUserQuery();
};

#endif // FORMUSERQUERIES_H
