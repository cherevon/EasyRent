#ifndef FORMPRIORITYSHOW_H
#define FORMPRIORITYSHOW_H

#include <QWidget>
#include "Queries.h"
#include "Tools/ContainerUtils.h"
#include "Interfaces.h"
#include "FormPriorityCreate.h"

namespace Ui {
class FormPriorityShow;
}

class FormPriorityShow : public QWidget, public IControlExtractor
{
    Q_OBJECT

public:
    explicit FormPriorityShow(QWidget *parent = 0);
    ~FormPriorityShow();

private:
    int fCreateTimeColumn;  // column number to display the creation time of PQ
    int fQueryTypeColumn;   // column number to display the query type
    int fObjectTypeColumn;  // column number to display required object type
    int fLastSearchColumn;  // column number to display the time of the last search
    int fEMailsColumn;      // column number to display e-mails, on which the program should send a message about PQ changes
    int fAreasColumn;       // column number to display areas
    int fMetrosColumn;      // column number to display metros
    int fRoomsColumn;       // column number to display rooms amount
    int fAddressColumn;     // column number to display the address
    int fFurnitureColumn;   // column number to display if furniture included
    int fWasherColumn;      // column number to display if washer included
    int fTelephoneColumn;   // column number to display if telephone included
    int fFridgeColumn;      // column number to display if fridge included
    int fPriceColumn;       // column number to display price
    int fPeriodColumn;      // column number to display rent period
    int fContactColumn;     // column number to display contact information
    int fAddInfoColumn;     // column number to display additional information

    Ui::FormPriorityShow *ui;

    void connectEvents();

public:
    /*IControlExtractor*/
    QObjectList extractControls();

public slots:
    virtual void refreshData();
    virtual void appendPQ(const PriorityQuery * const PQ);
    virtual void createPQ();
};

#endif // FORMPRIORITYSHOW_H
