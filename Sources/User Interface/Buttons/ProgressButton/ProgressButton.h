#ifndef PROGRESSBUTTON_H
#define PROGRESSBUTTON_H


#include <QWidget>
#include <QToolButton>
#include <QProgressBar>
#include <QVBoxLayout>


/** Виджет, объединяющий в себе возможности кнопки и индикатор прогресса
 */
class ProgressButton : public QWidget
{
    Q_OBJECT

private:
    /** Кнопка
     */
    QToolButton *fButton;
    /** Индикатор прогресса
     */
    QProgressBar *fProgressBar;

public:
    explicit ProgressButton(QWidget *parent = 0);

    /** Получение кнопки
     * @return Кнопка
     */
    QToolButton* button() const;
    /** Получение индикатора прогресса
     * @return Индикатор прогресса
     */
    QProgressBar* progressBar() const;
};


#endif // PROGRESSBUTTON_H
