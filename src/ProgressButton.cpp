#include "ProgressButton.h"


ProgressButton::ProgressButton(QWidget *parent) : QWidget(parent)
{
    setLayout(new QVBoxLayout(this));
    layout()->setSpacing(0);

    // размещаем кнопку
    fButton = new QToolButton(this);
    fButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout()->addWidget(fButton);

    // размещаем индикатор прогресса
    fProgressBar = new QProgressBar(this);
    fProgressBar->setMaximumHeight(5);
    fProgressBar->setValue(100);
    fProgressBar->setTextVisible(false);
    layout()->addWidget(fProgressBar);
}


QToolButton *ProgressButton::button() const
{
    return fButton;
}


QProgressBar *ProgressButton::progressBar() const
{
    return fProgressBar;
}
