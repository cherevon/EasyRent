#ifndef CONTAINERUTILS_H
#define CONTAINERUTILS_H

#include <QSet>
#include <QString>

/*====================================================================================================================*/

class ContainerUtils
{
private:
    ContainerUtils();

public:
    static QString commaText(const QSet<QString> &initSet);
};

/*====================================================================================================================*/

#endif // CONTAINERUTILS_H
