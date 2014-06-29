#ifndef FORMPRIORITYSHOW_H
#define FORMPRIORITYSHOW_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMessageBox>
#include <QtGui>
#include "PropertyStorage.h"
#include "FormPriorityCreate.h"
#include "GlobalDataManager.h"
#include "Tools/Interfaces.h"
#include "Tools/ContainerUtils.h"

const int PQColumnAmount = 17;

const QString PQColumnNames[PQColumnAmount] = {
    "Дата создания",
    "Тип",
    "Объект",
    "Последний поиск",
    "Комнаты",
    "Районы",
    "Метро",
    "Адрес",
    "Меб.",
    "Ст. м.",
    "Тел.",
    "Хол.",
    "Стоимость",
    "Срок",
    "Контактная информация",
    "Дополнительные сведения",
    "E-mail"
};

void loadPQs();

class FormPriorityShow : public QWidget, public IControlExtractor
{
    Q_OBJECT

private:
    QTableWidget        *PQTable;           // таблица для отображения перечня приоритетных запросов
    QVBoxLayout         *TotalLayout;       // окончательное отображение всех компонентов на форме
    QMenuBar            *MenuBar;           // панель меню
    QAction             *actPrint;          // печать приоритетных запросов
    QMenu               *menuPriority;      // подменю "Приоритетные запросы"
    QAction             *actNewPriority;    // пункт меню "Создать приоритетный запрос"
    QAction             *actEditPriority;   // пункт меню "Новый приоритетный запрос"
    QAction             *actDeletePriority; // пункт меню "Удалить приоритетный запрос"
    QAction             *actSearchPriority; // пункт меню "Провести поиск"
    FormPriorityCreate  *PQCreate;          // диалоговое окно добавления нового приоритетного запроса

    void                loadMenu();         // загрузка всех видов меню формы

protected:
    void closeEvent(QCloseEvent *e);

public:
    explicit FormPriorityShow(QWidget *parent = 0);

    QObjectList* extractControls();

signals:

public slots:
    void show();
    void refreshData();
    void loadSettings();
    void saveSettings();
    void actPrintExecute();
    void actNewPriorityExecute();
    void actEditPriorityExecute();
    void actDeletePriorityExecute();
    void actSearchPriorityExecute();

};

#endif // FORMPRIORITYSHOW_H
