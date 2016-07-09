#include <QApplication>
#include "MainWindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QObject>
#include <QStyleFactory>


/// Инициализация базы данных
void initializeDB()
{
    QSqlQuery qInitDB;

    // создание таблицы объектов недвижимости
    qInitDB.prepare(QString("CREATE TABLE IF NOT EXISTS er_objects (\n") +
                    QString("id INTEGER PRIMARY KEY AUTOINCREMENT,\n") +
                    QString("obj_type VARCHAR(10) NOT NULL,\n") +
                    QString("city VARCHAR(255) NOT NULL,\n") +
                    QString("address VARCHAR(255),\n") +
                    QString("first_floor INT NOT NULL,\n") +
                    QString("floor_count INT NOT NULL,\n") +
                    QString("square_total FLOAT NOT NULL,\n") +
                    QString("contact VARCHAR(255),\n") +
                    QString("additional_info VARCHAR(255)\n") +
                    QString(")"));
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }

    // создание таблицы типов помещений
    qInitDB.prepare(QString("CREATE TABLE IF NOT EXISTS er_room_types (\n") +
                    QString("id INTEGER PRIMARY KEY AUTOINCREMENT,\n") +
                    QString("name VARCHAR(20) NOT NULL\n") +
                    QString(")"));
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }
    qInitDB.prepare("INSERT INTO er_room_types(name) VALUES(\"Комната\")");
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }
    qInitDB.prepare("INSERT INTO er_room_types(name) VALUES(\"Кухня\")");
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }

    // создание таблицы помещений объектов недвижимости
    qInitDB.prepare(QString("CREATE TABLE IF NOT EXISTS er_object_rooms (\n") +
                    QString("real_estate_obj_id INTEGER REFERENCES er_objects(id),\n") +
                    QString("room_type INTEGER NOT NULL REFERENCES er_room_types(id),\n") +
                    QString("square FLOAT NOT NULL\n") +
                    QString(")"));
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }

    // создание таблицы типов запросов
    qInitDB.prepare(QString("CREATE TABLE IF NOT EXISTS er_query_types (\n") +
                    QString("id INTEGER PRIMARY KEY AUTOINCREMENT,\n") +
                    QString("name VARCHAR(25) NOT NULL\n") +
                    QString(")"));
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }
    qInitDB.prepare("INSERT INTO er_query_types(name) VALUES(\"Продажа\")");
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }
    qInitDB.prepare("INSERT INTO er_query_types(name) VALUES(\"Покупка\")");
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }
    qInitDB.prepare("INSERT INTO er_query_types(name) VALUES(\"Продажа (аренда)\")");
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }
    qInitDB.prepare("INSERT INTO er_query_types(name) VALUES(\"Покупка (аренда)\")");
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }

    // создание таблицы приоритетных запросов
    qInitDB.prepare(QString("CREATE TABLE IF NOT EXISTS er_priority_queries (\n") +
                    QString("id INTEGER PRIMARY KEY AUTOINCREMENT,\n") +
                    QString("query_type INTEGER REFERENCES er_query_types(id),\n") +
                    QString("create_date TIMESTAMP NOT NULL,\n") +
                    QString("price INTEGER NOT NULL,\n") +
                    QString("source VARCHAR(255),\n") +
                    QString("search_object INTEGER REFERENCES er_objects(id)\n") +
                    QString(")"));
    if (!qInitDB.exec())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), qInitDB.lastError().text());
        return;
    }
}


int main(int argc, char* argv[])
{
    QApplication *app = new QApplication(argc, argv);

//    app->setStyle(QStyleFactory::create("fusion"));

    // устанавливаем соединение с базой данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("EasyRent.db");
    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Ошибка"), db.lastError().text());
        return db.lastError().number();
    }
    initializeDB();

    // отображаем главное окно приложения
    MainWindow* wndMain = new MainWindow();
    wndMain->show();

    return app->exec();
}
