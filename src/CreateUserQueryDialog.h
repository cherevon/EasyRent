#ifndef CREATEUSERQUERYDIALOG_H
#define CREATEUSERQUERYDIALOG_H

#include <QDialog>

namespace Ui {
class CreateUserQueryDialog;
}

class CreateUserQueryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateUserQueryDialog(QWidget *parent = 0);
    ~CreateUserQueryDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CreateUserQueryDialog *ui;
};

#endif // CREATEUSERQUERYDIALOG_H
