/********************************************************************************
** Form generated from reading UI file 'FormPriorityShow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPRIORITYSHOW_H
#define UI_FORMPRIORITYSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPriorityShow
{
public:
    QAction *actNewPQ;
    QAction *actDelete;
    QAction *actFind;
    QVBoxLayout *verticalLayout;
    QTableWidget *PQTable;

    void setupUi(QWidget *FormPriorityShow)
    {
        if (FormPriorityShow->objectName().isEmpty())
            FormPriorityShow->setObjectName(QStringLiteral("FormPriorityShow"));
        FormPriorityShow->resize(1027, 626);
        actNewPQ = new QAction(FormPriorityShow);
        actNewPQ->setObjectName(QStringLiteral("actNewPQ"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/add.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actNewPQ->setIcon(icon);
        actDelete = new QAction(FormPriorityShow);
        actDelete->setObjectName(QStringLiteral("actDelete"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/remove.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actDelete->setIcon(icon1);
        actFind = new QAction(FormPriorityShow);
        actFind->setObjectName(QStringLiteral("actFind"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actFind->setIcon(icon2);
        verticalLayout = new QVBoxLayout(FormPriorityShow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        PQTable = new QTableWidget(FormPriorityShow);
        if (PQTable->columnCount() < 17)
            PQTable->setColumnCount(17);
        PQTable->setObjectName(QStringLiteral("PQTable"));
        PQTable->setAlternatingRowColors(true);
        PQTable->setSelectionMode(QAbstractItemView::MultiSelection);
        PQTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        PQTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        PQTable->setSortingEnabled(true);
        PQTable->setColumnCount(17);
        PQTable->verticalHeader()->setVisible(false);
        PQTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout->addWidget(PQTable);


        retranslateUi(FormPriorityShow);

        QMetaObject::connectSlotsByName(FormPriorityShow);
    } // setupUi

    void retranslateUi(QWidget *FormPriorityShow)
    {
        FormPriorityShow->setWindowTitle(QApplication::translate("FormPriorityShow", "\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202\320\275\321\213\320\265 \320\267\320\260\320\277\321\200\320\276\321\201\321\213", 0));
        actNewPQ->setText(QApplication::translate("FormPriorityShow", "\320\235\320\276\320\262\321\213\320\271...", 0));
#ifndef QT_NO_TOOLTIP
        actNewPQ->setToolTip(QApplication::translate("FormPriorityShow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\277\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202\320\275\321\213\320\271 \320\267\320\260\320\277\321\200\320\276\321\201", 0));
#endif // QT_NO_TOOLTIP
        actNewPQ->setShortcut(QApplication::translate("FormPriorityShow", "Ctrl+Shift+N", 0));
        actDelete->setText(QApplication::translate("FormPriorityShow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
#ifndef QT_NO_TOOLTIP
        actDelete->setToolTip(QApplication::translate("FormPriorityShow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202\320\275\321\213\320\271 \320\267\320\260\320\277\321\200\320\276\321\201", 0));
#endif // QT_NO_TOOLTIP
        actDelete->setShortcut(QApplication::translate("FormPriorityShow", "Del", 0));
        actFind->setText(QApplication::translate("FormPriorityShow", "\320\235\320\260\320\271\321\202\320\270...", 0));
#ifndef QT_NO_TOOLTIP
        actFind->setToolTip(QApplication::translate("FormPriorityShow", "\320\235\320\260\320\271\321\202\320\270 \320\277\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202\320\275\321\213\320\271 \320\267\320\260\320\277\321\200\320\276\321\201 \320\270\320\267 \321\201\320\277\320\270\321\201\320\272\320\260", 0));
#endif // QT_NO_TOOLTIP
        actFind->setShortcut(QApplication::translate("FormPriorityShow", "Ctrl+F", 0));
    } // retranslateUi

};

namespace Ui {
    class FormPriorityShow: public Ui_FormPriorityShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPRIORITYSHOW_H
