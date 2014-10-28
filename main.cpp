#include "MainWindow.h"
#include "Queries.h"
#include <QApplication>
#include <QtGui>
#include <QFile>
#include <QMap>
#include "GlobalDataManager.h"
#include "AppInfo.h"

extern QList<AbstractQuery*> PQs;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationDisplayName("EasyRent");
    QApplication::setOrganizationName("Grad Petra");
    QApplication::setApplicationName("EasyRent");
    MainWindow FormMain;

    AppInfo::setMainWindow(&FormMain);

    FormMain.show();

    return a.exec();
}
