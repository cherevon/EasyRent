#include "ResponseQuery.h"

/*====================================================================================================================*/

ResponseQuery::ResponseQuery(): AbstractQuery()
{
    fUpdateTime = QDateTime::currentDateTime();
    fAgent      = "";
    fs_o        = -1;
    fs_j        = -1;
    fs_k        = -1;
}

/*====================================================================================================================*/

void ResponseQuery::readBinary(QFile &f)
{
    AbstractQuery::readBinary(f);

    long len;
    QString s;

    f.read((char*)&len, sizeof(len));
    f.read((char*)&s, len);
    fUpdateTime.fromString(s);

    f.read((char*)&len, sizeof(len));
    f.read((char*)&fAgent, len);

    f.read((char*)&fs_o, sizeof(fs_o));
    f.read((char*)&fs_j, sizeof(fs_j));
    f.read((char*)&fs_k, sizeof(fs_k));
}

/*====================================================================================================================*/

void ResponseQuery::writeBinary(QFile &f) const
{
    AbstractQuery::writeBinary(f);

    long len;
    QString s;

    len = fUpdateTime.toString().length() + 1;
    s = fUpdateTime.toString();
    f.write((char*)&len, sizeof(len));
    f.write((char*)&s, len);

    ///fdgdfgdgadhgsgajbjbajgwekoj
    len = fAgent.length() + 1;
    s = fAgent;
    f.write((char*)&len, sizeof(len));
    f.write((char*)&s, len);

    f.write((char*)&fs_o, sizeof(fs_o));
    f.write((char*)&fs_j, sizeof(fs_j));
    f.write((char*)&fs_k, sizeof(fs_k));

    f.flush();
}

/*====================================================================================================================*/

bool ResponseQuery::operator ==(const ResponseQuery &Q)
{
    return (AbstractQuery::operator ==(Q)) &&
            fUpdateTime == Q.fUpdateTime &&
            fAgent      == Q.fAgent      &&
            fs_o        == Q.fs_o        &&
            fs_k        == Q.fs_k        &&
            fs_j        == Q.fs_j;
}

/*====================================================================================================================*/
