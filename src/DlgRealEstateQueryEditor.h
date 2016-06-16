#ifndef DLGUSERQUERYEDITOR_H
#define DLGUSERQUERYEDITOR_H


#include <QWidget>
#include "RealEstateQuery.h"


namespace Ui {
class DlgRealEstateQueryEditor;
}


/// Диалог для редактирования запроса для поиска недвижимости
class DlgRealEstateQueryEditor : public QWidget
{
    Q_OBJECT

private:
    /// Исходное состояние редактируемого запроса (необходимо для отката изменений)
    RealEstateQuery* fInitialQuery;
    /// Редактируемый в данный момент запрос для поиска недвижимости
    RealEstateQuery* fEditQuery;
    /// Признак того, что в данный момент выполняется обновление информации о запросе в окно
    bool fRefreshingInfo;
    /// Пользовательский интерфейс
    Ui::DlgRealEstateQueryEditor *ui;

private slots:
    /// Загрузка параметров из пользовательского интерфейса в редактируемый объект
    void loadQueryDataFromUI() const;
    /// Определение допустимых значений для последнего этажа объекта недвижимости
    void updateLastFloorLimits() const;

public:
    explicit DlgRealEstateQueryEditor(QWidget *parent = 0);
    ~DlgRealEstateQueryEditor();

    /** Получение редактируемого в данный момент запроса для поиска недвижимости
     * @return Редактируемый в данный момент запрос для поиска недвижимости
     */
    RealEstateQuery *editQuery() const;

public slots:
    /** Смена редактируемого в данный момент запроса для поиска недвижимости
     * @param value Новый запрос для поиска недвижимости
     */
    void setEditQuery(RealEstateQuery* value);

    /// Обновление отображаемой в окне информации о запросе
    void refreshInfo();
    /// Сохранение внесенных изменений
    void save();
    /// Отмена внесенных изменений
    void cancel();

signals:
    /// Сигнал, возникающий при сохранении изменений
    void saved();
    /// Сигнал, возникающий при отмене изменений
    void cancelled();
};

#endif // DLGUSERQUERYEDITOR_H
