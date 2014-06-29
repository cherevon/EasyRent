#include "MainForm.h"
#include "Queries.h"
#include <QApplication>
#include <QtGui>
#include <QFile>
#include <QMap>
#include "GlobalDataManager.h"

//------------------------------------------------------------

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationDisplayName("EasyRent");
    QApplication::setOrganizationName("Grad Petra");
    QApplication::setApplicationName("EasyRent");
    MainForm FormMain;
    FormMain.show();

    return a.exec();
}
