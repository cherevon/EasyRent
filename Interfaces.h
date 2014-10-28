#ifndef INTERFACES_H
#define INTERFACES_H

#include <QObjectList>

class IControlExtractor
// interface for widgets that can extract their controls to main form
{
public:
    virtual QObjectList extractControls() = 0; // returns controls to be placed on the main window
};

class IMainWindow
// interface for the main window of the application
{
public:
    virtual void addUserWindow(QWidget* pwgt) = 0; // inserts new widget
    virtual void addToolbarAction(QAction* pAct) = 0; // adds new action to the ToolBar
};

#endif // INTERFACES_H
