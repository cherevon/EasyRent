#ifndef RESPONSEQUERY_H
#define RESPONSEQUERY_H

#include <QDateTime>
#include "AbstractQuery.h"

/*====================================================================================================================*/

class ResponseQuery: public AbstractQuery
{
private:
    QDateTime   fUpdateTime;  // дата обновления
    QString     fAgent;       // агент
    double      fs_o;         // общая площадь
    double      fs_j;         // жилая площадь
    double      fs_k;         // площадь кухни

public:
    // CONSTRUCTORS
    ResponseQuery();

    // FIELD ACCESS METHODS
    QDateTime   updateTime()            const           {return fUpdateTime;}
    QString     agent()                 const           {return fAgent;}
    double      s_O()                   const           {return fs_o;}
    double      s_J()                   const           {return fs_j;}
    double      s_K()                   const           {return fs_k;}
    void        setUpdateTime(const QDateTime Value)    {fUpdateTime = Value;}
    void        setAgent(const QString Value)           {fAgent = Value;}
    void        setS_O(const double Value)              {fs_o = Value;}
    void        setS_J(const double Value)              {fs_j = Value;}
    void        setS_K(const double Value)              {fs_k = Value;}

    // OPERATORS
    bool operator ==(const ResponseQuery& Q);
    ResponseQuery& operator =(const ResponseQuery& Q);

    // METHODS
    virtual void readBinary(QFile &f);
    virtual void writeBinary(QFile &f) const;
};

/*====================================================================================================================*/

#endif // RESPONSEQUERY_H
