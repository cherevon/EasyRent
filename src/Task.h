#ifndef TASK_H
#define TASK_H


#include <QObject>
#include <QIcon>


/** Пользовательская задача
 * @details Отвечает за некоторую функциональность, доступную пользователю
 */
class Task : public QObject
{
    Q_OBJECT

private:
    /** Наименование задачи */
    QString fTitle;
    /** Подробное описание задачи */
    QString fDescription;
    /** Иконка задачи */
    QIcon fIcon;

public:
    explicit Task(QObject *parent = 0);

    /** Минимальное значение процента выполнения задачи */
    const uint MIN_PERCENT_VALUE = 0;
    /** Максимальное значение процента выполнения задачи */
    const uint MAX_PERCENT_VALUE = 100;

    /** Получение наименования задачи
     * @return Наименование задачи
     */
    QString title() const;
    /** Получение подробного описания задачи
     * @return Подробное описание задачи
     */
    QString description() const;
    /** Получение иконки задачи
     * @return Иконка задачи
     */
    QIcon icon() const;

public slots:
    /** Изменение наименования задачи
     * @param newTitle Новое наименование задачи
     */
    void setTitle(QString& newTitle);
    /** Изменение подробного описания задачи
     * @param newDescription Новое подробное описание задачи
     */
    void setDescription(QString& newDescription);
    /** Изменение иконки задачи
     * @param newIcon Новая иконка задачи
     */
    void setIcon(QIcon& newIcon);

    /** Выполнение задачи
     */
    virtual void execute();

signals:
    /** Сигнал, возникающий при изменении информации о задаче */
    void changed();
    /** Сигнал, возникающий при появлении прогресса в выполнении задачи
     * @param percentComplete Процент выполнения задачи
     * @remarks Максимальное значение percentComplete = MAX_PERCENT_VALUE.
     * Значение percentComplete равное MIN_PERCENT_VALUE считается запуском задачи.
     * При достижении percentComplete значения MAX_PERCENT_VALUE, задача считается полностью выполненной
     * @see MAX_PERCENT_VALUE
     */
    void executionProgress(uint percentComplete);
};


#endif // TASK_H
