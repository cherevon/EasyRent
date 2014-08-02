#ifndef FORMPRIORITYSHOW_H
#define FORMPRIORITYSHOW_H

#include <QWidget>

namespace Ui {
class FormPriorityShow;
}

class FormPriorityShow : public QWidget
{
    Q_OBJECT

public:
    explicit FormPriorityShow(QWidget *parent = 0);
    ~FormPriorityShow();

private:
    Ui::FormPriorityShow *ui;

public slots:
    void refreshData();
};

#endif // FORMPRIORITYSHOW_H
