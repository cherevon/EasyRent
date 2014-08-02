#include "FormPriorityCreate.h"

FormPriorityCreate::FormPriorityCreate(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("Новый приоритетный запрос");

    createWndComponents();
}

/*==========================================================================================================*/

FormPriorityCreate::FormPriorityCreate(PriorityQuery *PQ, QWidget *parent) : QWidget(parent)
// создание окна "Редактировать приоритетный запрос"
{
    // если приоритетный запрос не задан, то выходим
    if (!PQ) return;

    this->setWindowTitle("Редактирование приоритетного запроса");
    createWndComponents();

    setPriorityQuery(PQ);
}

/*====================================================================================================================*/

void FormPriorityCreate::setPriorityQuery(PriorityQuery *PQ)
{
    // перенос деталей запроса на элементы окна
    // тип запроса
    (PQ->queryType() == Queries::SDAM)? rbSdam->setChecked(true): rbSnimu->setChecked(true);

    // кол-во комнат
    eRoomsCount->setValue(PQ->rooms());

    // тип объекта
    switch (PQ->searchObjectType())
    {
        case Queries::Elite:
            rbElite->setChecked(true);
            break;
        case Queries::Flat:
            rbFlat->setChecked(true);
            break;
        case Queries::Room:
            rbRoom->setChecked(true);
            break;
        default:
            rbFlat->setChecked(true);
            break;
    }

    // наличие телефона
    cbTelephone->setChecked(PQ->hasTelephone());

    // наличие мебели
    cbFurniture->setChecked(PQ->hasFurniture());

    // наличие холодильника
    cbFridge->setChecked(PQ->hasFridge());

    // наличие стиральной машины
    cbWasher->setChecked(PQ->hasWasher());

    // срок
    cbLongPeriod->setChecked(PQ->period() == 0);
    if (PQ->period() != 0)
        ePeriod->setValue(PQ->period());

    // стоимость
    ePrice->setValue(PQ->price());

    // контактная информация
    eContact->setText(PQ->contact());

    // адрес
    eAddress->setText(PQ->address());

    // дополнительные сведения
    eAddInfo->setText(PQ->additionalInfo());

    // районы
    for(int rowNum = 0; rowNum < lwAreas->count(); ++rowNum)
    {
        if ( PQ->hasArea(lwAreas->item(rowNum)->text()) )
            lwAreas->item(rowNum)->setSelected(true);
        else
            lwAreas->item(rowNum)->setSelected(false);
    }

    // станции метро
    for(int rowNum = 0; rowNum < lwMetros->count(); ++rowNum)
    {
        if ( PQ->hasMetro(lwMetros->item(rowNum)->text()) )
            lwMetros->item(rowNum)->setSelected(true);
        else
            lwMetros->item(rowNum)->setSelected(false);
    }

    // адреса электронной почты (e-mail)

}

/*====================================================================================================================*/

void FormPriorityCreate::createWndComponents()
// создание и соединение всех компонентов окна
{
    // группа радиокнопок "Тип" - НАЧАЛО
        gbType = new QGroupBox("Тип");
        rbSdam = new QRadioButton("Сдам", gbType);
        rbSnimu = new QRadioButton("Сниму", gbType);
        rbSdam->setChecked(true);

        gbType->setLayout(new QVBoxLayout());
        gbType->layout()->addWidget(rbSdam);
        gbType->layout()->addWidget(rbSnimu);
    // группа радиокнопок "Тип" - КОНЕЦ

    // группа радиокнопок "Объект" - НАЧАЛО
        gbObject    = new QGroupBox("Объект");
        rbFlat      = new QRadioButton("Квартира", gbObject);
        rbRoom      = new QRadioButton("Комната", gbObject);
        rbElite     = new QRadioButton("Элитное", gbObject);
        rbFlat->setChecked(true);

        gbObject->setLayout(new QVBoxLayout());
        gbObject->layout()->addWidget(rbFlat);
        gbObject->layout()->addWidget(rbRoom);
        gbObject->layout()->addWidget(rbElite);
    // группа радиокнопок "Объект" - КОНЕЦ

    // количество комнат - НАЧАЛО
        eRoomsCount = new QSpinBox(this);
        eRoomsCount->setValue(1);
        eRoomsCount->setMaximum(100);
        eRoomsCount->setMinimum(1);

        QVBoxLayout *layRoomCount = new QVBoxLayout();
        layRoomCount->addWidget(new QLabel("Кол-во комнат"));
        layRoomCount->addWidget(eRoomsCount);
        layRoomCount->insertStretch(0, 1);
    // количество комнат - КОНЕЦ

    // группа чекбоксов "Условия" - НАЧАЛО
        gbFeatures  = new QGroupBox();
        cbTelephone = new QCheckBox("Телефон", gbFeatures);
        cbFridge    = new QCheckBox("Холодильник", gbFeatures);
        cbWasher    = new QCheckBox("Стиральная машина", gbFeatures);
        cbFurniture = new QCheckBox("Мебель", gbFeatures);

        gbFeatures->setLayout(new QVBoxLayout());
        gbFeatures->layout()->addWidget(cbTelephone);
        gbFeatures->layout()->addWidget(cbFridge);
        gbFeatures->layout()->addWidget(cbWasher);
        gbFeatures->layout()->addWidget(cbFurniture);
        gbFeatures->adjustSize();
        gbFeatures->setMaximumSize(gbFeatures->size());

        QVBoxLayout *laygbFeatures = new QVBoxLayout();
        laygbFeatures->addWidget(gbFeatures);
        laygbFeatures->addStretch(1);
    // группа чекбоксов "Условия" - КОНЕЦ

    // список районов, стоимость, контакт, адрес, доп инфо - НАЧАЛО
        lwAreas = new QListWidget(this);
//        QStringList Areas = GlobalDataManager::Instance.availableAreas();
//        lwAreas->addItems(Areas);
        lwAreas->setSelectionMode(QAbstractItemView::MultiSelection);

        int IntMax = round( pow(2, sizeof(int)*8 - 2));
        ePrice = new QSpinBox(this);
        ePrice->setMinimum(0);
        ePrice->setMaximum(IntMax);
        ePrice->setValue(20000);
        ePrice->setSingleStep(100);
        ePrice->setSuffix(" руб.");

        eContact = new QLineEdit(this);
        eAddInfo = new QLineEdit(this);
        eAddress = new QLineEdit(this);
    // список районов, стоимость, контакт, адрес, доп инфо - НАЧАЛО

    // список станций метро - НАЧАЛО
        lwMetros = new QListWidget(this);
//        QStringList Metros = GlobalDataManager::Instance.availableMetros();
//        lwMetros->addItems(Metros);
        lwMetros->setSelectionMode(QAbstractItemView::MultiSelection);
        lwMetros->setLayoutMode(QListView::Batched);
    // список станций метро - КОНЕЦ

    // группа "Срок" - НАЧАЛО
        gbPeriod = new QGroupBox("Срок");
        ePeriod = new QSpinBox(gbPeriod);
        ePeriod->setValue(1);
        ePeriod->setMinimum(1);
        ePeriod->setMaximum(11);
        ePeriod->setEnabled(false);
        cbLongPeriod = new QCheckBox("Длительный", gbPeriod);
        cbLongPeriod->setChecked(true);

        gbPeriod->setLayout(new QVBoxLayout());
        gbPeriod->layout()->addWidget(ePeriod);
        gbPeriod->layout()->addWidget(cbLongPeriod);
        gbPeriod->adjustSize();
        gbPeriod->setMaximumSize(gbPeriod->size());
        laygbFeatures->addWidget(gbPeriod);
    // группа "Срок" - КОНЕЦ

    bCreatePQ = new QPushButton("Создать приоритетный запрос", this);

    QGridLayout *layTotal = new QGridLayout(this);
    layTotal->addWidget(gbType,                         0, 0, 2, 1);
    layTotal->addWidget(gbObject,                       0, 2, 2, 1);
    layTotal->addLayout(layRoomCount,                   1, 1, 1, 1);
    layTotal->addWidget(new QLabel("Районы:"),          2, 1, 1, 2, Qt::AlignCenter);
    layTotal->addLayout(laygbFeatures,                  3, 0, 1, 1);
    layTotal->addWidget(lwAreas,                        3, 1, 2, 2);
    layTotal->addWidget(gbPeriod,                       4, 0, 1, 1);
    layTotal->addWidget(new QLabel("Метро:"),           5, 1, 1, 2, Qt::AlignCenter);
    layTotal->addWidget(lwMetros,                       6, 1, 3, 2);
    layTotal->addWidget(new QLabel("Стоимость:"),       7, 0, 1, 1);
    layTotal->addWidget(ePrice,                         8, 0, 1, 1);
    layTotal->addWidget(new QLabel("Контакт:"),         9, 0, 1, 1);
    layTotal->addWidget(new QLabel("Адрес:"),           9, 1, 1, 2);
    layTotal->addWidget(eContact,                       10, 0, 1, 1);
    layTotal->addWidget(eAddress,                       10, 1, 1, 2);
    layTotal->addWidget(new QLabel("Дополнительная информация:"), 11, 0, 1, 4);
    layTotal->addWidget(eAddInfo,                       12, 0, 1, 4);
    layTotal->addWidget(bCreatePQ,                      13, 0, 1, 4);

    connect(cbLongPeriod,   SIGNAL(clicked(bool)), ePeriod, SLOT(setDisabled(bool)));
    connect(bCreatePQ,      SIGNAL(clicked()),              SLOT(bCreatePQPressed()));
}

/*====================================================================================================================*/

void FormPriorityCreate::bCreatePQPressed()
// нажатие кнопки "Создать приоритетный запрос"
{
    PriorityQuery *NewPQ = new PriorityQuery();

    // наполнение нового запроса данными
    NewPQ->setAdditionalInfo(eAddInfo->text());
    NewPQ->setAddress(eAddress->text());

    NewPQ->setContact(eContact->text());
    NewPQ->setCreateTime( QDateTime(QDateTime::currentDateTime()) );
    NewPQ->setFridge(cbFridge->isChecked());
    NewPQ->setFurniture(cbFurniture->isChecked());
    NewPQ->setWasher(cbWasher->isChecked());
    NewPQ->setTelephone(cbTelephone->isChecked());
    NewPQ->setLastSearchTime(QDateTime());

    // срок
    if (cbLongPeriod->isChecked())
        NewPQ->setPeriod(0);
    else
        NewPQ->setPeriod(ePeriod->value());
    NewPQ->setPrice(ePrice->value());

    // тип запроса
    if (rbSdam->isChecked())
        NewPQ->setQueryType(Queries::SDAM);
    else
        NewPQ->setQueryType(Queries::SNIMU);

    NewPQ->setRooms(eRoomsCount->value());

    // тип искомого объекта
    if (rbFlat->isChecked())
        NewPQ->setSearchObjectType(Queries::Flat);
    else if (rbRoom->isChecked())
        NewPQ->setSearchObjectType(Queries::Room);
    else
        NewPQ->setSearchObjectType(Queries::Elite);

    // районы и станции метро
    QList<QListWidgetItem*> temp = lwAreas->selectedItems();
    QList<QListWidgetItem*>::const_iterator iter;
    for(iter = temp.constBegin(); iter != temp.constEnd(); ++iter)
        NewPQ->areas().insert((*iter)->text());

    temp = lwMetros->selectedItems();
    for(iter = temp.constBegin(); iter != temp.constEnd(); ++iter)
        NewPQ->metros().insert((*iter)->text());

    // если приоритетный запрос действительно новый, то добавляем его
    //if (qFind(GlobalDataManager::Instance.PQs(), NewPQ) != GlobalDataManager::Instance.PQs().end())
//    if (GlobalDataManager::Instance.PQs().indexOf(NewPQ) == -1)
//    {
//        GlobalDataManager::Instance.PQs().push_front(NewPQ);
//        // вызываем сигнал, что был создан новый приоритетный запрос
//        emit newPQCreated();
//    }
}

/*==========================================================================================================*/
