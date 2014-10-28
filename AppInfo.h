#ifndef APPINFO_H
#define APPINFO_H

#include <QMainWindow>
#include "Interfaces.h"

class AppInfo
// stores required information about application objects
{
private:
    static IMainWindow* fMainWindow; // main window of the application

public:
    static IMainWindow* mainWindow(); // returns pointer to the main window of the application
    static void setMainWindow(IMainWindow* pMW); // changes the main form of the application to pMW (logically)
};

#endif // APPINFO_H
