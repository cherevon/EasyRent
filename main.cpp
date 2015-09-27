#include "MainWindow.h"
#include "Queries.h"
#include <QApplication>
#include <QtGui>
#include <QSqlDatabase>
#include <QtSql>

extern QList<AbstractQuery*> PQs;
QSqlDatabase db;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("EasyRent");
    a.setQuitOnLastWindowClosed(true);

//    // назначаем стиль элементам пользовательского интерфейса приложения
//    a.setStyleSheet(
//        // текстовые поля ввода (QLineEdit)
//        QString("QLineEdit\n") +
//        QString("{background-color: rgb(255, 255, 255);\n") +
//        QString("padding: 0 3px;\n") +
//        QString("border-radius: 4px;}\n") +

//        // кнопки (QPushButton)
//        QString("QPushButton\n") +
//        QString("{background-color: rgb(255, 255, 255, 0);\n") +
//        QString("border-radius: 4px;}\n") +

//        // кнопка при наведении указателя мыши на нее (QPushButton:hover)
//        QString("QPushButton:hover\n") +
//        QString("{background-color: qlineargradient(spread:pad, x1:0.522, y1:0, x2:0.507, y2:1, ") +
//        QString("stop:0 rgba(130, 251, 139, 255), stop:1 rgba(255, 255, 255, 255))}\n") +

//        // нажатая кнопка (QPushButton:pressed)
//        QString("QPushButton:pressed\n") +
//        QString("{background-color: qlineargradient(spread:pad, x1:0.522, y1:0, x2:0.507, y2:1, ") +
//        QString("stop:0 rgba(88, 171, 94, 255), stop:1 rgba(255, 255, 255, 255));}\n") +

//        // текстовые метки (QLabel)
//        QString("QLabel\n") +
//        QString("{background-color: rgb(255, 255, 255, 0)}\n") +

//        // выпадающие списки (QComboBox)
//        QString("QComboBox\n") +
//        QString("{background-color: white;\n") +
//        QString("padding: 0 3px;\n") +
//        QString("border-radius: 4px}\n") +

//        // панели статуса (QStatusBar)
//        QString("QStatusBar\n") +
//        QString("{background-color: rgb(255, 255, 255, 0);}\n") +

//        // панели инструментов (QToolBar)
//        QString("QToolBar\n") +
//        QString("{background-color: rgb(255, 255, 255, 0);}\n") +

//        // панели меню (QMenuBar)
//        QString("QMenuBar\n") +
//        QString("{background-color: rgb(255, 255, 255, 0);}\n") +

//        // пункты меню (QMenuBar::item)
//        QString("QMenuBar::item\n") +
//        QString("{background-color: rgb(255, 255, 255, 0);}\n") +

//        // выбранные пункты меню (QMenuBar::item:selected)
//        QString("QMenuBar::item:selected\n") +
//        QString("{color: rgb(255, 255, 255, 255);}\n") +

//        // выбранные пункты меню (QMenu::item:selected)
//        QString("QMenu::item:selected\n") +
//        QString("{color: rgb(255, 255, 255, 255);}\n") +

//        // грид (QTableWidget)
//        QString("QTableWidget\n") +
//        QString("{color: rgb(0, 0, 0, 0);}\n") +

//        // компонент с вкладками (QTabWidget)
//        QString("QTabWidget\n") +
//        QString("{color: rgb(0, 0, 0, 0);}\n") +

//        // все остальные компоненты пользовательского интерфейса
//        QString("* {background-color: rgb(180, 220, 255, 255);\n") +
////                qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, ") +
////        QString("fy:0.5, stop:0 rgba(210, 255, 210, 255), stop:1 rgba(160, 200, 255, 255));\n") +
//        QString("font-family: Courier;\n") +
//        QString("font-size: 10pt;}\n")
//    );

    // настраиваем соединение приложения с БД
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/EasyRent/Database/EasyRent.db");
    if (!db.open())
    {
        qDebug() << db.lastError();
        return 10;
    }

    // отображаем главное окно приложения
    MainWindow* pMainWin = new MainWindow();
    pMainWin->show();

    return a.exec();
}
