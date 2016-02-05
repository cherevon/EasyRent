#include "WgtRegisterUser.h"
#include "ui_WgtRegisterUser.h"

WgtRegisterUser::WgtRegisterUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WgtRegisterUser)
{
    ui->setupUi(this);

    // загружаем перечень стран
    QStringList* countryList = getAllCountries();
    ui->cbCountry->addItems(*countryList);
    delete countryList;

    // обновляем перечень городов в выбранной стране
    countryChanged(ui->cbCountry->currentText());

    // соединяем сигналы и слоты
    connect(ui->cbCountry, SIGNAL(currentIndexChanged(QString)), SLOT(countryChanged(QString)));
    connect(ui->bRegister, SIGNAL(clicked()), SLOT(registerClicked()));
}

WgtRegisterUser::~WgtRegisterUser()
{
    delete ui;
}

void WgtRegisterUser::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void WgtRegisterUser::countryChanged(QString newCountry)
// обработчик события при выборе другой страны
{
    // обновляем перечень городов в стране
    QStringList* cityList = getCitiesInCountry(newCountry);
    ui->cbCity->clear();
    ui->cbCity->addItems(*cityList);
    delete cityList;
}

void WgtRegisterUser::registerClicked()
// обработчик события при нажатии кнопки "зарегистрировать"
{
    // регистрируем пользователя с введенными параметрами
    EasyRentUser* newUser = new EasyRentUser;
    newUser->city = ui->cbCity->currentText();
    newUser->country = ui->cbCountry->currentText();
    newUser->surname = ui->eSurname->text();
    newUser->name = ui->eName->text();
    newUser->patronymic = ui->ePatronymic->text();
    newUser->password = ui->ePassword->text();
    newUser->username = ui->eUsername->text();

    if (!registerUser(newUser))
        qDebug() << "Регистрация нового пользователя не удалась!";
    else
        emit userRegistered();

    delete newUser;
}
