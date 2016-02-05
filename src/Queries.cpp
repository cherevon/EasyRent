#include "Queries.h"

Query::Query()
{
    fType       = SDAM;
    fAreas      = QSet<QString>();
    fMetros     = QSet<QString>();
    fRooms      = 1;
    fAddress    = "";
    fFurniture  = fWasher = fFridge = fTelephone = true;
    fPrice      = 10000;
    fContact    = "";
    fAddInfo    = "";
}

//----------------------------------------------------------------

Query::Query(Query &Q)
{
    fType       = Q.fType;
    fAreas      = Q.fAreas;
    fMetros     = Q.fMetros;
    fRooms      = Q.fRooms;
    fAddress    = Q.fAddress;
    fFurniture  = Q.fFurniture;
    fWasher     = Q.fWasher;
    fFridge     = Q.fFridge;
    fTelephone  = Q.fTelephone;
    fPrice      = Q.fPrice;
    fPeriod     = Q.fPeriod;
    fContact    = Q.fContact;
    fAddInfo    = Q.fAddInfo;
}

//----------------------------------------------------------------

Query::Query(QueryType      Type,
             QSet<QString>  Areas,
             QSet<QString>  Metros,
             uint           Rooms,
             QString        Address,
             bool           Furniture,
             bool           Washer,
             bool           Fridge,
             bool           Telephone,
             uint           Price,
             uint           Period,
             QString        Contact,
             QString        AdditionalInfo)
{
    fType       = Type;
    fAreas      = Areas;
    fMetros     = Metros;
    fRooms      = Rooms;
    fAddress    = Address;
    fFurniture  = Furniture;
    fWasher     = Washer;
    fFridge     = Fridge;
    fTelephone  = Telephone;
    fPrice      = Price;
    fPeriod     = Period;
    fContact    = Contact;
    fAddInfo    = AdditionalInfo;
}

//----------------------------------------------------------------

PriorityQuery::PriorityQuery(): Query()
{
    fCreateTime = QDateTime::currentDateTime();
    fCodeName   = "";
    fObjectType = Flat;
    fLastSearch = QDateTime();
}

//----------------------------------------------------------------

PriorityQuery::PriorityQuery(PriorityQuery &Q): Query(Q)
{
    fCreateTime = Q.fCreateTime;
    fCodeName   = Q.fCodeName;
    fObjectType = Q.fObjectType;
    fLastSearch = Q.fLastSearch;
}

//----------------------------------------------------------------

PriorityQuery::PriorityQuery(
        QDateTime       CreateTime,
        QString         CodeName,
        QueryType       Type,
        ObjType         ObjectType,
        QSet<QString>   Areas,
        QSet<QString>   Metros,
        uint            Rooms,
        QString         Address,
        bool            Furniture,
        bool            Washer,
        bool            Fridge,
        bool            Telephone,
        uint            Price,
        uint            Period,
        QString         Contact,
        QString         AdditionalInfo,
        QDateTime       LastSearch): Query(Type, Areas, Metros, Rooms, Address, Furniture, Washer, Fridge, Telephone, Price, Period, Contact, AdditionalInfo)
{
    fCreateTime = CreateTime;
    fCodeName   = CodeName;
    fObjectType = ObjectType;
    fLastSearch = LastSearch;
}

//----------------------------------------------------------------

ResponseQuery::ResponseQuery(): Query()
{
    fUpdateTime = QDateTime::currentDateTime();
    fAgent      = "";
    fs_o        = -1;
    fs_j        = -1;
    fs_k        = -1;
}

//----------------------------------------------------------------

ResponseQuery::ResponseQuery(ResponseQuery &Q): Query(Q)
{
    fUpdateTime = Q.fUpdateTime;
    fAgent      = Q.fAgent;
    fs_o        = Q.fs_o;
    fs_j        = Q.fs_j;
    fs_k        = Q.fs_k;
}

//----------------------------------------------------------------

ResponseQuery::ResponseQuery(
        QDateTime UpdateTime,
        QueryType Type,
        QSet<QString> Areas,
        QSet<QString> Metros,
        uint Rooms,
        double s_o,
        double s_j,
        double s_k,
        QString Address,
        bool    Furniture,
        bool    Washer,
        bool    Fridge,
        bool    Telephone,
        uint    Price,
        uint    Period,
        QString Agent,
        QString Contact,
        QString AdditionalInfo): Query(Type, Areas, Metros, Rooms, Address, Furniture, Washer, Fridge, Telephone, Price, Period, Contact, AdditionalInfo)
{
    fUpdateTime = UpdateTime;
    fAgent      = Agent;
    fs_o        = s_o;
    fs_j        = s_j;
    fs_k        = s_k;
}

//----------------------------------------------------------------

bool Query::operator ==(const Query& Q)
{
    if (this == &Q) return true;
    return (
                fType       == Q.fType &&
                fAreas      == Q.fAreas &&
                fMetros     == Q.fMetros &&
                fRooms      == Q.fRooms &&
                fAddress    == Q.fAddress &&
                fFurniture  == Q.fFurniture &&
                fWasher     == Q.fWasher &&
                fFridge     == Q.fFridge &&
                fTelephone  == Q.fTelephone &&
                fPrice      == Q.fPrice &&
                fPeriod     == Q.fPeriod &&
                fContact    == Q.fContact &&
                fAddInfo    == Q.fAddInfo
            );
}

//----------------------------------------------------------------

Query& Query::operator =(const Query& Q)
{
    if (this == &Q) return *this;
    fType       = Q.fType;
    fAreas      = Q.fAreas;
    fMetros     = Q.fMetros;
    fRooms      = Q.fRooms;
    fAddress    = Q.fAddress;
    fFurniture  = Q.fFurniture;
    fWasher     = Q.fWasher;
    fFridge     = Q.fFridge;
    fTelephone  = Q.fTelephone;
    fPrice      = Q.fPrice;
    fPeriod     = Q.fPeriod;
    fContact    = Q.fContact;
    fAddInfo    = Q.fAddInfo;

    return *this;
}

//----------------------------------------------------------------

void Query::writeBinary(QFile &f) const
{
    // запись простых типов данных
    f.write((char*)&fType,      sizeof(fType));
    f.write((char*)&fRooms,     sizeof(fRooms));
    f.write((char*)&fFurniture, sizeof(fFurniture));
    f.write((char*)&fFridge,    sizeof(fFridge));
    f.write((char*)&fWasher,    sizeof(fWasher));
    f.write((char*)&fTelephone, sizeof(fTelephone));
    f.write((char*)&fPrice,     sizeof(fPrice));
    f.write((char*)&fPeriod,    sizeof(fPeriod));

    // запись строк
    QString::size_type sSize;
    sSize = fAddress.size()+1;
    f.write((char*)&sSize, sizeof(QString::size_type));
    f.write((char*)&fAddress, sSize);

    sSize = fContact.size()+1;
    f.write((char*)&sSize, sizeof(QString::size_type));
    f.write((char*)&fContact, sSize);

    sSize = fAddInfo.size()+1;
    f.write((char*)&sSize, sizeof(QString::size_type));
    f.write((char*)&fAddInfo, sSize);

    // запись списков
    QSet<QString>::const_iterator iter;
    QSet<QString>::size_type setSize;
    setSize = fAreas.size();
    f.write((char*)&setSize, sizeof(setSize));
    for(iter = fAreas.begin(); iter != fAreas.end(); ++iter)
    {
        sSize = iter->size()+1;
        f.write((char*)&sSize, sizeof(QString::size_type));
        f.write((char*)&*(iter), sSize);
    }

    setSize = fMetros.size();
    f.write((char*)&setSize, sizeof(setSize));
    for(iter = fMetros.begin(); iter != fMetros.end(); ++iter)
    {
        sSize = iter->size()+1;
        f.write((char*)&sSize, sizeof(QString::size_type));
        f.write((char*)&*(iter), sSize);
    }
}

//----------------------------------------------------------------

void Query::readBinary(QFile &f)
{
    // чтение простых типов данных
    f.read((char*)&fType,      sizeof(fType));
    f.read((char*)&fRooms,     sizeof(fRooms));
    f.read((char*)&fFurniture, sizeof(fFurniture));
    f.read((char*)&fFridge,    sizeof(fFridge));
    f.read((char*)&fWasher,    sizeof(fWasher));
    f.read((char*)&fTelephone, sizeof(fTelephone));
    f.read((char*)&fPrice,     sizeof(fPrice));
    f.read((char*)&fPeriod,    sizeof(fPeriod));

    // чтение строк
    char* s;
    QString::size_type sSize=0;

    f.read((char*)&sSize, sizeof(sSize));
    s = new char[sSize];
    f.read(s, sSize);
    fAddress = s;
    delete [] s;

    f.read((char*)&sSize, sizeof(sSize));
    s = new char[sSize];
    f.read(s, sSize);
    fContact = s;
    delete [] s;

    f.read((char*)&sSize, sizeof(sSize));
    s = new char[sSize];
    f.read(s, sSize);
    fAddInfo = s;
    delete [] s;

    // чтение списков
    QString temp;
    QSet<QString>::size_type SetSize=0;
    f.read((char*)&SetSize, sizeof(SetSize));
    fAreas.clear();
    for(long i=1; i<=SetSize; ++i)
    {
        f.read((char*)&sSize, sizeof(sSize));
        s = new char[sSize];
        f.read(s, sSize);
        temp = s;
        fAreas.insert(temp);
        delete [] s;
    }

    f.read((char*)&SetSize, sizeof(SetSize));
    fMetros.clear();
    for(long i=1; i<=SetSize; ++i)
    {
        f.read((char*)&sSize, sizeof(sSize));
        s = new char[sSize];
        f.read(s, sSize);
        temp = s;
        fMetros.insert(temp);
        delete [] s;
    }

    f.flush();
}

//----------------------------------------------------------------

bool PriorityQuery::operator ==(const PriorityQuery& Q)
{
    return (
        (Query::operator == (Q)) &&
        fCreateTime == Q.fCreateTime &&
        fCodeName   == Q.fCodeName &&
        fObjectType == Q.fObjectType &&
        fLastSearch == Q.fLastSearch
    );
}

//----------------------------------------------------------------

PriorityQuery& PriorityQuery::operator =(const PriorityQuery& Q)
{
    Query::operator =(Q);
    fCreateTime = Q.fCreateTime;
    fCodeName   = Q.fCodeName;
    fObjectType = Q.fObjectType;
    fLastSearch = Q.fLastSearch;

    return *this;
}

//----------------------------------------------------------------

void operator <<(ostream& f, const Query& Q)
// Вывод запроса в поток в текстовом виде
{
    QString s = (Q.fType==SDAM)?"СДАМ":"СНИМУ";
    QSet<QString>::const_iterator iter;

    f << "Тип: "           << s.toStdString() << endl;
    f << "Кол-во комнат: " << Q.fRooms << endl;
    f << "Адрес: "         << Q.fAddress.toStdString() << endl;

    f << "Районы: "        << endl;
    for(iter=Q.fAreas.begin(); iter!=Q.fAreas.end(); ++iter)
    {
        f << "       " << iter->toStdString() << endl;
    }

    f << "Метро: " << endl;
    for(iter=Q.fMetros.begin(); iter!=Q.fMetros.end(); ++iter)
    {
        f << "       " << iter->toStdString() << endl;
    }

    s = (Q.fTelephone)?"+":"-";
    f << "Телефон: "       << s.toStdString() << endl;
    s = (Q.fFridge)?"+":"-";
    f << "Холодильник: "   << s.toStdString() << endl;
    s = (Q.fFurniture)?"+":"-";
    f << "Мебель: "        << s.toStdString() << endl;
    s = (Q.fWasher)?"+":"-";
    f << "Стиральная машина: "         << s.toStdString() << endl;

    f << "Стоимость: "                 << Q.fPrice   << endl;
    f << "Срок: "                      << Q.fPeriod  << endl;
    f << "Контакт: "                   << Q.fContact.toStdString() << endl;
    f << "Дополнительные сведения: "   << Q.fAddInfo.toStdString() << endl;
}

//----------------------------------------------------------------

void PriorityQuery::readBinary(QFile &f)
{
    Query::readBinary(f);

    long int len;
    QString s;

    f.read((char*)&len, sizeof(len));
    f.read((char*)&s, len);
    fCreateTime.fromString(s);

    f.read((char*)&len, sizeof(len));
    f.read((char*)&s, len);
    fLastSearch.fromString(s);

    f.read((char*)&fObjectType, sizeof(ObjType));
}

//----------------------------------------------------------------

void PriorityQuery::writeBinary(QFile &f) const
{
    Query::writeBinary(f);

    long int len;
    QString s;

    len = fCreateTime.toString().length() + 1;
    s = fCreateTime.toString();
    f.write((char*)&len, sizeof(len));
    f.write((char*)&s, len);

    len = fLastSearch.toString().length() + 1;
    s = fLastSearch.toString();
    f.write((char*)&len, sizeof(len));
    f.write((char*)&s, len);

    f.write((char*)&fObjectType, sizeof(ObjType));

    f.flush();
}
