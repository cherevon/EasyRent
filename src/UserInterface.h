#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QObject>

class UserInterface : public QObject
{
    Q_OBJECT
public:
    explicit UserInterface(QObject *parent = 0);

signals:

public slots:
};

#endif // USERINTERFACE_H