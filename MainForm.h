#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QMdiArea>
#include <QMenuBar>
#include "FormPriorityShow.h"

class MainForm : public QMainWindow
{
    Q_OBJECT

private:
    QMdiArea            *MdiArea;
    FormPriorityShow    *FormPQ;    // форма для просмотра пользовательских приоритетных запросов

protected:
    void closeEvent(QCloseEvent* e);

public:
    explicit MainForm(QWidget *parent = 0);

signals:

public slots:
    void triggeredShowPQ();
    void destroyedFormPriorityShow();
    void loadSettings();
    void saveSettings();
};

#endif // MAINFORM_H
