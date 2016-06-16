#include "DlgRealEstateQueryEditor.h"
#include "ui_DlgUserQueryEditor.h"
#include <QStringListModel>
#include "ResidentialRealEstateObject.h"


void DlgRealEstateQueryEditor::loadQueryDataFromUI() const
{
    if (!fRefreshingInfo)
    {
        // тип запроса
        fEditQuery->setQueryType(stringToQueryType(ui->cbQueryType->currentText()));
        // стоимость
        fEditQuery->setPrice(ui->spinPrice->value());

        RealEstateObject* searchRealEstate = fEditQuery->searchObject();
        // город
        searchRealEstate->setCity(ui->cbCity->currentText());
        // вид объекта недвижимости
        searchRealEstate->setRealEstateType(stringToRealEstateType(ui->cbRealEstateType->currentText()));
        // адрес
        searchRealEstate->setAddress(ui->eAddress->text());
        // контактная информация
        searchRealEstate->setAdditionalInfo(ui->eContact->text());
        // общая площадь
        searchRealEstate->setTotalSquare(ui->spinTotalSquare->value());
        // первый занимаемый этаж
        searchRealEstate->setFirstFloor(ui->spinFirstFloor->value());
        // последний занимаемый этаж
        searchRealEstate->setFloorCount(ui->spinLastFloor->value() - ui->spinFirstFloor->value() + 1);
        // дополнительные сведения
        searchRealEstate->setAdditionalInfo(ui->eAdditionalInfo->toPlainText());
    }
}


void DlgRealEstateQueryEditor::updateLastFloorLimits() const
{
    ui->spinLastFloor->setMinimum(ui->spinFirstFloor->value());
}


DlgRealEstateQueryEditor::DlgRealEstateQueryEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DlgRealEstateQueryEditor)
{
    ui->setupUi(this);

    fRefreshingInfo = false;

    // загрузка доступных типов запросов для поиска недвижимости
    QStringListModel* availableQueryTypes = new QStringListModel(ui->cbQueryType);
    availableQueryTypes->setStringList(availableQueryTypesStrings());
    ui->cbQueryType->setModel(availableQueryTypes);

    // загрузка доступных типов объектов недвижимости
    QStringListModel* availableRealEstateTypes = new QStringListModel(ui->cbRealEstateType);
    availableRealEstateTypes->setStringList(availableRealEstateTypesStrings());
    ui->cbRealEstateType->setModel(availableRealEstateTypes);

    // инициализация запросов, с которыми происходит работа
    fInitialQuery = NULL;
    fEditQuery = new RealEstateQuery(this);
    fEditQuery->setSearchObject(new ResidentialRealEstateObject(fEditQuery));

    // подключаем обработчики событий
    connect(ui->cbQueryType, SIGNAL(currentTextChanged(QString)), SLOT(loadQueryDataFromUI()));
    connect(ui->cbRealEstateType, SIGNAL(currentTextChanged(QString)), SLOT(loadQueryDataFromUI()));
    connect(ui->cbCity, SIGNAL(currentTextChanged(QString)), SLOT(loadQueryDataFromUI()));
    connect(ui->eAddress, SIGNAL(textChanged(QString)), SLOT(loadQueryDataFromUI()));
    connect(ui->eContact, SIGNAL(textChanged(QString)), SLOT(loadQueryDataFromUI()));
    connect(ui->spinPrice, SIGNAL(valueChanged(int)), SLOT(loadQueryDataFromUI()));
    connect(ui->spinTotalSquare, SIGNAL(valueChanged(double)), SLOT(loadQueryDataFromUI()));
    connect(ui->spinFirstFloor, SIGNAL(valueChanged(int)), SLOT(loadQueryDataFromUI()));
    connect(ui->spinFirstFloor, SIGNAL(valueChanged(int)), SLOT(updateLastFloorLimits()));
    connect(ui->spinLastFloor, SIGNAL(valueChanged(int)), SLOT(loadQueryDataFromUI()));
    connect(ui->eAdditionalInfo, SIGNAL(textChanged()), SLOT(loadQueryDataFromUI()));
    connect(ui->bSave, SIGNAL(clicked()), SLOT(save()));
    connect(ui->bCancel, SIGNAL(clicked()), SLOT(cancel()));

    refreshInfo();
}


DlgRealEstateQueryEditor::~DlgRealEstateQueryEditor()
{
    delete ui;
}


RealEstateQuery *DlgRealEstateQueryEditor::editQuery() const
{
    return fEditQuery;
}


void DlgRealEstateQueryEditor::setEditQuery(RealEstateQuery *value)
{
    fInitialQuery = value;
    fEditQuery->assign(fInitialQuery);
    fEditQuery->searchObject()->assign(fInitialQuery->searchObject());

    refreshInfo();
}


void DlgRealEstateQueryEditor::refreshInfo()
{
    fRefreshingInfo = true;

    // тип запроса
    ui->cbQueryType->setCurrentText(queryTypeToString(fEditQuery->queryType()));
    // стоимость
    ui->spinPrice->setValue(fEditQuery->price());

    RealEstateObject* searchRealEstate = fEditQuery->searchObject();
    // город
    ui->cbCity->setCurrentText(searchRealEstate->city());
    // вид объекта недвижимости
    ui->cbRealEstateType->setCurrentText(realEstateTypeToString(searchRealEstate->realEstateType()));
    // адрес
    ui->eAddress->setText(searchRealEstate->address());
    // контактная информация
    ui->eContact->setText(searchRealEstate->contactInfo());
    // общая площадь
    ui->spinTotalSquare->setValue(searchRealEstate->totalSquare());
    // первый занимаемый этаж
    ui->spinFirstFloor->setValue(searchRealEstate->firstFloor());
    // последний занимаемый этаж
    ui->spinLastFloor->setValue(searchRealEstate->firstFloor() + searchRealEstate->floorCount() - 1);
    // дополнительные сведения
    ui->eAdditionalInfo->setPlainText(searchRealEstate->additionalInfo());

    fRefreshingInfo = false;
}


void DlgRealEstateQueryEditor::save()
{
    if (fInitialQuery != NULL)
    {
        fInitialQuery->assign(fEditQuery);
        fInitialQuery->searchObject()->assign(fEditQuery->searchObject());
    }

    emit saved();
}


void DlgRealEstateQueryEditor::cancel()
{
    if (fInitialQuery != NULL)
    {
        fEditQuery->assign(fInitialQuery);
        fEditQuery->searchObject()->assign(fInitialQuery->searchObject());
    }

    emit cancelled();
}
