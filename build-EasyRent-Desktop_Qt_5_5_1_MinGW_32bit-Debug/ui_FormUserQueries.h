/********************************************************************************
** Form generated from reading UI file 'FormUserQueries.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMUSERQUERIES_H
#define UI_FORMUSERQUERIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "DlgUserQueryEditor.h"

QT_BEGIN_NAMESPACE

class Ui_FormUserQueries
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tvQueries;
    DlgUserQueryEditor *widget;

    void setupUi(QWidget *FormUserQueries)
    {
        if (FormUserQueries->objectName().isEmpty())
            FormUserQueries->setObjectName(QStringLiteral("FormUserQueries"));
        FormUserQueries->resize(762, 404);
        horizontalLayout = new QHBoxLayout(FormUserQueries);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tvQueries = new QTableView(FormUserQueries);
        tvQueries->setObjectName(QStringLiteral("tvQueries"));
        tvQueries->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tvQueries->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout->addWidget(tvQueries);

        widget = new DlgUserQueryEditor(FormUserQueries);
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout->addWidget(widget);


        retranslateUi(FormUserQueries);

        QMetaObject::connectSlotsByName(FormUserQueries);
    } // setupUi

    void retranslateUi(QWidget *FormUserQueries)
    {
        FormUserQueries->setWindowTitle(QApplication::translate("FormUserQueries", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class FormUserQueries: public Ui_FormUserQueries {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMUSERQUERIES_H
