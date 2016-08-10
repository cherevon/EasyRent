#include "Task.h"


Task::Task(QObject *parent) : QObject(parent)
{
}


QString Task::title() const
{
    return fTitle;
}


QString Task::description() const
{
    return fDescription;
}


QIcon Task::icon() const
{
    return fIcon;
}


void Task::setTitle(QString &newTitle)
{
    fTitle = newTitle;
    emit changed();
}


void Task::setDescription(QString &newDescription)
{
    fDescription = newDescription;
    emit changed();
}


void Task::setIcon(QIcon &newIcon)
{
    fIcon = newIcon;
}


void Task::execute()
{
    emit executionProgress(MIN_PERCENT_VALUE);
    emit executionProgress(MAX_PERCENT_VALUE);
}
