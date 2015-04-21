#include "MainWindow.h"
#include "Queries.h"
#include <QApplication>
#include <QtGui>
#include <QFile>
#include <QMap>
#include "GlobalDataManager.h"
#include "AppInfo.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QException>
#include <QDebug>

extern QList<AbstractQuery*> PQs;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationDisplayName("EasyRent");
//    QApplication::setOrganizationName("Grad Petra");
    QApplication::setApplicationName("EasyRent");

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={SQL SERVER};Server=CSA\\SQLEXPRESS;Database=EasyRent;Integrated Security=false;");
    if (!db.open())
    {
        QException e;
        e.raise();
        return 10;
    }

    MainWindow FormMain;

    AppInfo::setMainWindow(&FormMain);

    FormMain.show();

    return a.exec();
}
