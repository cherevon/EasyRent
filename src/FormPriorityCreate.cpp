#include "FormPriorityCreate.h"
#include "ui_FormPriorityCreate.h"

FormPriorityCreate::FormPriorityCreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPriorityCreate)
{
    ui->setupUi(this);

    connect(ui->cbCity, SIGNAL(currentIndexChanged(QString)), SLOT(loadMetros(QString)));
    connect(ui->cbCity, SIGNAL(currentIndexChanged(QString)), SLOT(loadAreas(QString)));
    connect(ui->bCreatePQ, SIGNAL(clicked()), SLOT(savePQ()));

    QSqlQuery query("SELECT name FROM er_cities");
    while (query.next())
    {
        ui->cbCity->addItem(query.value("name").toString());
    }
}

FormPriorityCreate::~FormPriorityCreate()
{
    delete ui;
}

void FormPriorityCreate::loadMetros(QString cityName)
// загрузка перечня станций метро для города с указанным названием
{
    // очищаем предыдущий набор станций метро
    ui->cbMetro->clear();

    // выбираем все станции метро, которые соответствуют указанному городу
    QSqlQuery query("SELECT metro FROM er_city_metros WHERE city_id = (SELECT id FROM er_cities WHERE name ='" + cityName + "') ORDER BY metro");
    while (query.next())
    {
        ui->cbMetro->addItem(query.value("metro").toString());
    }

    // выбор станции метро недоступен, если в текущем городе отсутствует метро (0 станций)
    ui->widgetMetro->setVisible(ui->cbMetro->count() > 0);

    adjustSize();
}

void FormPriorityCreate::loadAreas(QString cityName)
// загрузка перечня районов для города с указанным названием
{
    // очищаем предыдущий набор станций метро
    ui->cbArea->clear();

    // выбираем все станции метро, которые соответствуют указанному городу
    QSqlQuery query("SELECT area FROM er_city_areas WHERE city_id = (SELECT id FROM er_cities WHERE name ='" + cityName + "') ORDER BY area");
    while (query.next())
    {
        ui->cbArea->addItem(query.value("area").toString());
    }

    // выбор станции метро недоступен, если в текущем городе отсутствует метро (0 станций)
    ui->widgetArea->setVisible(ui->cbArea->count() > 0);

    adjustSize();
}

void FormPriorityCreate::savePQ()
// сохранение приоритетного запроса
{
    QString SQL = "INSERT INTO er_priority_queries(city,";
    SQL += "sign,";
    SQL += "pq_type,";
    SQL += "furniture,";
    SQL += "washer,";
    SQL += "telephone,";
    SQL += "fridge,";
    SQL += "price_from,";
    SQL += "price_to,";
    SQL += "period,";
    SQL += "rooms_min,";
    SQL += "rooms_max,";
    SQL += "square_total,";
    SQL += "square_live,";
    SQL += "square_kitchen,";
    SQL += "long_period,";
    SQL += "additional_info,";
    SQL += "object_type) VALUES((SELECT id FROM er_cities WHERE name = :city)";
    SQL += ":sign,";
    SQL += ":pq_type,";
    SQL += ":furniture,";
    SQL += ":washer,";
    SQL += ":telephone,";
    SQL += ":fridge,";
    SQL += ":price_from,";
    SQL += ":price_to,";
    SQL += ":period,";
    SQL += ":rooms_min,";
    SQL += ":rooms_max,";
    SQL += ":square_total,";
    SQL += ":square_live,";
    SQL += ":square_kitchen,";
    SQL += ":long_period,";
    SQL += ":additional_info,";
    SQL += ":object_type))";

    QSqlQuery query;
    query.prepare(SQL);
//    query.bindValue(":city", ui->cbCity->currentText());
//    query.bindValue(":sign", "TEST");
//    query.bindValue(":pq_type", ui->cbQueryType->currentText());
//    query.bindValue(":furniture", NULL);
//    query.bindValue(":washer", NULL);
//    query.bindValue(":telephone", NULL);
//    query.bindValue(":fridge", NULL);
//    query.bindValue(":price_from", ui->spinPriceFrom->value());
//    query.bindValue(":price_to", ui->spinPriceTo->value());
//    query.bindValue(":period", ui->spinPeriod->value());
//    query.bindValue(":rooms_min", ui->spinRoomsFrom->value());
//    query.bindValue(":rooms_max", ui->spinRoomsTo->value());
//    query.bindValue(":square_total", ui->spinSquareTotalFrom->value());
//    query.bindValue(":square_live", ui->spinSquareLiveFrom->value());
//    query.bindValue(":square_kitchen", ui->spinSquareKitchenFrom->value());
//    query.bindValue(":long_period", ui->chkPeriodLong->isChecked());
//    query.bindValue(":additional_info", NULL);
//    query.bindValue(":object_type", 1);
    query.exec();
}
