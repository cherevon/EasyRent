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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormUserQueries
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QToolButton *toolButton;

    void setupUi(QWidget *FormUserQueries)
    {
        if (FormUserQueries->objectName().isEmpty())
            FormUserQueries->setObjectName(QStringLiteral("FormUserQueries"));
        FormUserQueries->resize(400, 300);
        gridLayout = new QGridLayout(FormUserQueries);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(FormUserQueries);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        toolButton = new QToolButton(FormUserQueries);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/plus.ico"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setAutoRepeat(false);
        toolButton->setAutoExclusive(false);
        toolButton->setAutoRaise(true);

        gridLayout->addWidget(toolButton, 0, 0, 1, 1);


        retranslateUi(FormUserQueries);

        QMetaObject::connectSlotsByName(FormUserQueries);
    } // setupUi

    void retranslateUi(QWidget *FormUserQueries)
    {
        FormUserQueries->setWindowTitle(QApplication::translate("FormUserQueries", "Form", 0));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormUserQueries: public Ui_FormUserQueries {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMUSERQUERIES_H
