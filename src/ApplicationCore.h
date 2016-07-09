#ifndef APPLICATIONCORE_H
#define APPLICATIONCORE_H

#include <QObject>

class ApplicationCore : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationCore(QObject *parent = 0);

signals:

public slots:
};

#endif // APPLICATIONCORE_H