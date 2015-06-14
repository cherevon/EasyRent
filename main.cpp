#include "MainWindow.h"
#include "Queries.h"
#include <QApplication>
#include <QtGui>
#include "AppInfo.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include "AuthWidget.h"

extern QList<AbstractQuery*> PQs;
QSqlDatabase db;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("EasyRent");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/EasyRent/Database/EasyRent.db");
    if (!db.open())
    {
        qDebug() << db.lastError();
        return 10;
    }

    AuthWidget* auth = new AuthWidget();
    auth->setWindowTitle("Авторизация EasyRent");
    auth->setWindowModality(Qt::ApplicationModal);
    auth->show();

    return a.exec();
}
