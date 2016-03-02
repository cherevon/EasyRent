/********************************************************************************
** Form generated from reading UI file 'CreateUserQueryDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSERQUERYDIALOG_H
#define UI_CREATEUSERQUERYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateUserQueryDialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *lblQueryType;
    QComboBox *cbQueryType;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblRealEstateType;
    QComboBox *cbRealEstateType;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblCity;
    QComboBox *cbCity;
    QVBoxLayout *verticalLayout_4;
    QLabel *lblAddress;
    QComboBox *cbAddress;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblPrice;
    QSpinBox *sbPrice;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *bSave;
    QPushButton *bSave_2;

    void setupUi(QDialog *CreateUserQueryDialog)
    {
        if (CreateUserQueryDialog->objectName().isEmpty())
            CreateUserQueryDialog->setObjectName(QStringLiteral("CreateUserQueryDialog"));
        CreateUserQueryDialog->resize(254, 279);
        verticalLayout_6 = new QVBoxLayout(CreateUserQueryDialog);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblQueryType = new QLabel(CreateUserQueryDialog);
        lblQueryType->setObjectName(QStringLiteral("lblQueryType"));

        verticalLayout->addWidget(lblQueryType);

        cbQueryType = new QComboBox(CreateUserQueryDialog);
        cbQueryType->setObjectName(QStringLiteral("cbQueryType"));
        cbQueryType->setMinimumContentsLength(0);

        verticalLayout->addWidget(cbQueryType);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblRealEstateType = new QLabel(CreateUserQueryDialog);
        lblRealEstateType->setObjectName(QStringLiteral("lblRealEstateType"));

        verticalLayout_2->addWidget(lblRealEstateType);

        cbRealEstateType = new QComboBox(CreateUserQueryDialog);
        cbRealEstateType->setObjectName(QStringLiteral("cbRealEstateType"));
        cbRealEstateType->setEditable(false);

        verticalLayout_2->addWidget(cbRealEstateType);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(7);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        lblCity = new QLabel(CreateUserQueryDialog);
        lblCity->setObjectName(QStringLiteral("lblCity"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblCity->sizePolicy().hasHeightForWidth());
        lblCity->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(lblCity);

        cbCity = new QComboBox(CreateUserQueryDialog);
        cbCity->setObjectName(QStringLiteral("cbCity"));
        cbCity->setEditable(true);

        verticalLayout_3->addWidget(cbCity);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lblAddress = new QLabel(CreateUserQueryDialog);
        lblAddress->setObjectName(QStringLiteral("lblAddress"));

        verticalLayout_4->addWidget(lblAddress);

        cbAddress = new QComboBox(CreateUserQueryDialog);
        cbAddress->setObjectName(QStringLiteral("cbAddress"));
        cbAddress->setEditable(true);

        verticalLayout_4->addWidget(cbAddress);


        verticalLayout_6->addLayout(verticalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lblPrice = new QLabel(CreateUserQueryDialog);
        lblPrice->setObjectName(QStringLiteral("lblPrice"));

        verticalLayout_5->addWidget(lblPrice);

        sbPrice = new QSpinBox(CreateUserQueryDialog);
        sbPrice->setObjectName(QStringLiteral("sbPrice"));
        sbPrice->setFrame(true);
        sbPrice->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbPrice->setAccelerated(true);
        sbPrice->setMaximum(1999999999);
        sbPrice->setSingleStep(1000);
        sbPrice->setValue(1000000);
        sbPrice->setDisplayIntegerBase(10);

        verticalLayout_5->addWidget(sbPrice);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_6->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bSave = new QPushButton(CreateUserQueryDialog);
        bSave->setObjectName(QStringLiteral("bSave"));

        horizontalLayout->addWidget(bSave);

        bSave_2 = new QPushButton(CreateUserQueryDialog);
        bSave_2->setObjectName(QStringLiteral("bSave_2"));

        horizontalLayout->addWidget(bSave_2);


        verticalLayout_6->addLayout(horizontalLayout);


        retranslateUi(CreateUserQueryDialog);

        QMetaObject::connectSlotsByName(CreateUserQueryDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateUserQueryDialog)
    {
        CreateUserQueryDialog->setWindowTitle(QApplication::translate("CreateUserQueryDialog", "Dialog", 0));
        lblQueryType->setText(QApplication::translate("CreateUserQueryDialog", "\320\242\320\270\320\277 \320\267\320\260\320\277\321\200\320\276\321\201\320\260", 0));
        lblRealEstateType->setText(QApplication::translate("CreateUserQueryDialog", "\320\236\320\261\321\212\320\265\320\272\321\202 \320\275\320\265\320\264\320\262\320\270\320\266\320\270\320\274\320\276\321\201\321\202\320\270", 0));
        lblCity->setText(QApplication::translate("CreateUserQueryDialog", "\320\223\320\276\321\200\320\276\320\264", 0));
        lblAddress->setText(QApplication::translate("CreateUserQueryDialog", "\320\220\320\264\321\200\320\265\321\201", 0));
        lblPrice->setText(QApplication::translate("CreateUserQueryDialog", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", 0));
        sbPrice->setSuffix(QApplication::translate("CreateUserQueryDialog", " \321\200\321\203\320\261.", 0));
        bSave->setText(QApplication::translate("CreateUserQueryDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        bSave_2->setText(QApplication::translate("CreateUserQueryDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateUserQueryDialog: public Ui_CreateUserQueryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSERQUERYDIALOG_H
