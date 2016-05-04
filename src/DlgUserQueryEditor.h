#ifndef DLGUSERQUERYEDITOR_H
#define DLGUSERQUERYEDITOR_H

#include <QDialog>

namespace Ui {
class DlgUserQueryEditor;
}

class DlgUserQueryEditor : public QDialog
{
    Q_OBJECT

public:
    explicit DlgUserQueryEditor(QWidget *parent = 0);
    ~DlgUserQueryEditor();

private:
    Ui::DlgUserQueryEditor *ui;
};

#endif // DLGUSERQUERYEDITOR_H
