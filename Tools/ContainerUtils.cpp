#include "ContainerUtils.h"

/*====================================================================================================================*/

ContainerUtils::ContainerUtils()
{
}

/*====================================================================================================================*/

QString ContainerUtils::commaText(const QSet<QString> &initSet)
// возвращает все значения, содержащиеся во множестве строк, разделенные запятой
{
    QString result = "";
    QSet<QString>::const_iterator currentStr;
    for(currentStr = initSet.constBegin(); currentStr != initSet.constEnd(); ++currentStr)
        result += *currentStr + ", ";

    if (!result.isEmpty()) result.remove(result.length() - 2, 2);
    return result;
}

/*====================================================================================================================*/
