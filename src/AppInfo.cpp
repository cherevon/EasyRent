#include "AppInfo.h"

IMainWindow* AppInfo::fMainWindow = NULL;

IMainWindow* AppInfo::mainWindow()
{
    return fMainWindow;
}

void AppInfo::setMainWindow(IMainWindow *pMW)
{
    fMainWindow = pMW;
}
