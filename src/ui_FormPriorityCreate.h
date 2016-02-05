/********************************************************************************
** Form generated from reading UI file 'FormPriorityCreate.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPRIORITYCREATE_H
#define UI_FORMPRIORITYCREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPriorityCreate
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *gbSquare;
    QGridLayout *gridLayout_2;
    QSpinBox *spinSquareLiveTo;
    QLabel *label_9;
    QSpinBox *spinSquareKitchenTo;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *spinSquareTotalTo;
    QSpinBox *spinSquareTotalFrom;
    QSpinBox *spinSquareLiveFrom;
    QLabel *label_10;
    QSpinBox *spinSquareKitchenFrom;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gbPeriod;
    QGridLayout *gridLayout_3;
    QSpinBox *spinPeriod;
    QCheckBox *chkPeriodLong;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QSpinBox *spinRoomsFrom;
    QLabel *label_8;
    QSpinBox *spinRoomsTo;
    QSpacerItem *horizontalSpacer_12;
    QWidget *widgetArea;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelArea;
    QComboBox *cbArea;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetMetro;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_7;
    QLabel *labelMetro;
    QComboBox *cbMetro;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QComboBox *cbQueryType;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelCity;
    QComboBox *cbCity;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *gbFridge;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *rbFridgeYes;
    QRadioButton *rbFridgeNo;
    QRadioButton *rbFridgeDontCare;
    QGroupBox *gbFurniture;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rbFurnitureYes;
    QRadioButton *rbFurnitureNo;
    QRadioButton *rbFurnitureDontCare;
    QPushButton *bCreatePQ;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QSpinBox *spinPriceFrom;
    QLabel *label_6;
    QSpinBox *spinPriceTo;
    QSpacerItem *horizontalSpacer_10;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbTelephoneYes;
    QRadioButton *rbTelephoneNo;
    QRadioButton *rbTelephoneDontCare;
    QGroupBox *gbWasher;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbWasherYes;
    QRadioButton *rbWasherNo;
    QRadioButton *rbWasherDontCare;
    QCheckBox *chkPhoto;
    QFrame *line;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormPriorityCreate)
    {
        if (FormPriorityCreate->objectName().isEmpty())
            FormPriorityCreate->setObjectName(QStringLiteral("FormPriorityCreate"));
        FormPriorityCreate->resize(561, 545);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormPriorityCreate->sizePolicy().hasHeightForWidth());
        FormPriorityCreate->setSizePolicy(sizePolicy);
        FormPriorityCreate->setMinimumSize(QSize(561, 545));
        FormPriorityCreate->setMaximumSize(QSize(561, 545));
        FormPriorityCreate->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(FormPriorityCreate);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(7, 7, 7, 7);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        gbSquare = new QGroupBox(FormPriorityCreate);
        gbSquare->setObjectName(QStringLiteral("gbSquare"));
        gbSquare->setMinimumSize(QSize(0, 0));
        gbSquare->setFlat(false);
        gridLayout_2 = new QGridLayout(gbSquare);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        spinSquareLiveTo = new QSpinBox(gbSquare);
        spinSquareLiveTo->setObjectName(QStringLiteral("spinSquareLiveTo"));
        spinSquareLiveTo->setMaximum(1000);

        gridLayout_2->addWidget(spinSquareLiveTo, 1, 4, 1, 1);

        label_9 = new QLabel(gbSquare);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 1, 3, 1, 1);

        spinSquareKitchenTo = new QSpinBox(gbSquare);
        spinSquareKitchenTo->setObjectName(QStringLiteral("spinSquareKitchenTo"));
        spinSquareKitchenTo->setMaximum(1000);

        gridLayout_2->addWidget(spinSquareKitchenTo, 2, 4, 1, 1);

        label_2 = new QLabel(gbSquare);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(gbSquare);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(gbSquare);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 3, 1, 1);

        spinSquareTotalTo = new QSpinBox(gbSquare);
        spinSquareTotalTo->setObjectName(QStringLiteral("spinSquareTotalTo"));
        spinSquareTotalTo->setMaximum(1000);

        gridLayout_2->addWidget(spinSquareTotalTo, 0, 4, 1, 1);

        spinSquareTotalFrom = new QSpinBox(gbSquare);
        spinSquareTotalFrom->setObjectName(QStringLiteral("spinSquareTotalFrom"));
        spinSquareTotalFrom->setMaximum(1000);

        gridLayout_2->addWidget(spinSquareTotalFrom, 0, 2, 1, 1);

        spinSquareLiveFrom = new QSpinBox(gbSquare);
        spinSquareLiveFrom->setObjectName(QStringLiteral("spinSquareLiveFrom"));
        spinSquareLiveFrom->setMaximum(1000);

        gridLayout_2->addWidget(spinSquareLiveFrom, 1, 2, 1, 1);

        label_10 = new QLabel(gbSquare);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        spinSquareKitchenFrom = new QSpinBox(gbSquare);
        spinSquareKitchenFrom->setObjectName(QStringLiteral("spinSquareKitchenFrom"));
        spinSquareKitchenFrom->setMaximum(1000);

        gridLayout_2->addWidget(spinSquareKitchenFrom, 2, 2, 1, 1);

        label_11 = new QLabel(gbSquare);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 2, 3, 1, 1);

        label_12 = new QLabel(gbSquare);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 2, 1, 1, 1);

        label_13 = new QLabel(gbSquare);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 1, 1, 1, 1);

        label_14 = new QLabel(gbSquare);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 0, 1, 1, 1);


        verticalLayout_3->addWidget(gbSquare);


        horizontalLayout_13->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        gbPeriod = new QGroupBox(FormPriorityCreate);
        gbPeriod->setObjectName(QStringLiteral("gbPeriod"));
        gridLayout_3 = new QGridLayout(gbPeriod);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        spinPeriod = new QSpinBox(gbPeriod);
        spinPeriod->setObjectName(QStringLiteral("spinPeriod"));
        spinPeriod->setMinimum(1);
        spinPeriod->setMaximum(11);
        spinPeriod->setValue(1);

        gridLayout_3->addWidget(spinPeriod, 0, 0, 1, 1);

        chkPeriodLong = new QCheckBox(gbPeriod);
        chkPeriodLong->setObjectName(QStringLiteral("chkPeriodLong"));

        gridLayout_3->addWidget(chkPeriodLong, 1, 0, 1, 2);


        verticalLayout_2->addWidget(gbPeriod);


        horizontalLayout_13->addLayout(verticalLayout_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_13);


        gridLayout->addLayout(horizontalLayout_13, 9, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, -1, -1);
        label_7 = new QLabel(FormPriorityCreate);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_10->addWidget(label_7);

        spinRoomsFrom = new QSpinBox(FormPriorityCreate);
        spinRoomsFrom->setObjectName(QStringLiteral("spinRoomsFrom"));

        horizontalLayout_10->addWidget(spinRoomsFrom);

        label_8 = new QLabel(FormPriorityCreate);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        spinRoomsTo = new QSpinBox(FormPriorityCreate);
        spinRoomsTo->setObjectName(QStringLiteral("spinRoomsTo"));

        horizontalLayout_10->addWidget(spinRoomsTo);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);


        gridLayout->addLayout(horizontalLayout_10, 12, 0, 1, 1);

        widgetArea = new QWidget(FormPriorityCreate);
        widgetArea->setObjectName(QStringLiteral("widgetArea"));
        widgetArea->setMinimumSize(QSize(0, 0));
        horizontalLayout_7 = new QHBoxLayout(widgetArea);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        labelArea = new QLabel(widgetArea);
        labelArea->setObjectName(QStringLiteral("labelArea"));

        horizontalLayout_7->addWidget(labelArea);

        cbArea = new QComboBox(widgetArea);
        cbArea->setObjectName(QStringLiteral("cbArea"));
        cbArea->setMinimumSize(QSize(250, 0));

        horizontalLayout_7->addWidget(cbArea);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        gridLayout->addWidget(widgetArea, 4, 0, 1, 1);

        widgetMetro = new QWidget(FormPriorityCreate);
        widgetMetro->setObjectName(QStringLiteral("widgetMetro"));
        widgetMetro->setMinimumSize(QSize(0, 0));
        horizontalLayout_11 = new QHBoxLayout(widgetMetro);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);

        labelMetro = new QLabel(widgetMetro);
        labelMetro->setObjectName(QStringLiteral("labelMetro"));

        horizontalLayout_11->addWidget(labelMetro);

        cbMetro = new QComboBox(widgetMetro);
        cbMetro->setObjectName(QStringLiteral("cbMetro"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbMetro->sizePolicy().hasHeightForWidth());
        cbMetro->setSizePolicy(sizePolicy1);
        cbMetro->setMinimumSize(QSize(250, 0));

        horizontalLayout_11->addWidget(cbMetro);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);


        gridLayout->addWidget(widgetMetro, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label = new QLabel(FormPriorityCreate);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        cbQueryType = new QComboBox(FormPriorityCreate);
        cbQueryType->setObjectName(QStringLiteral("cbQueryType"));

        horizontalLayout->addWidget(cbQueryType);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        labelCity = new QLabel(FormPriorityCreate);
        labelCity->setObjectName(QStringLiteral("labelCity"));

        horizontalLayout_6->addWidget(labelCity);

        cbCity = new QComboBox(FormPriorityCreate);
        cbCity->setObjectName(QStringLiteral("cbCity"));
        cbCity->setMinimumSize(QSize(250, 0));

        horizontalLayout_6->addWidget(cbCity);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, -1);
        gbFridge = new QGroupBox(FormPriorityCreate);
        gbFridge->setObjectName(QStringLiteral("gbFridge"));
        gbFridge->setMinimumSize(QSize(0, 0));
        gbFridge->setMaximumSize(QSize(16777215, 16777215));
        gbFridge->setAlignment(Qt::AlignCenter);
        horizontalLayout_5 = new QHBoxLayout(gbFridge);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        rbFridgeYes = new QRadioButton(gbFridge);
        rbFridgeYes->setObjectName(QStringLiteral("rbFridgeYes"));
        rbFridgeYes->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_5->addWidget(rbFridgeYes);

        rbFridgeNo = new QRadioButton(gbFridge);
        rbFridgeNo->setObjectName(QStringLiteral("rbFridgeNo"));
        rbFridgeNo->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_5->addWidget(rbFridgeNo);

        rbFridgeDontCare = new QRadioButton(gbFridge);
        rbFridgeDontCare->setObjectName(QStringLiteral("rbFridgeDontCare"));
        rbFridgeDontCare->setCursor(QCursor(Qt::PointingHandCursor));
        rbFridgeDontCare->setChecked(true);

        horizontalLayout_5->addWidget(rbFridgeDontCare);


        horizontalLayout_8->addWidget(gbFridge);

        gbFurniture = new QGroupBox(FormPriorityCreate);
        gbFurniture->setObjectName(QStringLiteral("gbFurniture"));
        gbFurniture->setMinimumSize(QSize(0, 0));
        gbFurniture->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        gbFurniture->setFont(font);
        gbFurniture->setAlignment(Qt::AlignCenter);
        horizontalLayout_3 = new QHBoxLayout(gbFurniture);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        rbFurnitureYes = new QRadioButton(gbFurniture);
        rbFurnitureYes->setObjectName(QStringLiteral("rbFurnitureYes"));
        rbFurnitureYes->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(rbFurnitureYes);

        rbFurnitureNo = new QRadioButton(gbFurniture);
        rbFurnitureNo->setObjectName(QStringLiteral("rbFurnitureNo"));
        rbFurnitureNo->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(rbFurnitureNo);

        rbFurnitureDontCare = new QRadioButton(gbFurniture);
        rbFurnitureDontCare->setObjectName(QStringLiteral("rbFurnitureDontCare"));
        rbFurnitureDontCare->setCursor(QCursor(Qt::PointingHandCursor));
        rbFurnitureDontCare->setChecked(true);

        horizontalLayout_3->addWidget(rbFurnitureDontCare);


        horizontalLayout_8->addWidget(gbFurniture);


        gridLayout->addLayout(horizontalLayout_8, 7, 0, 1, 1);

        bCreatePQ = new QPushButton(FormPriorityCreate);
        bCreatePQ->setObjectName(QStringLiteral("bCreatePQ"));

        gridLayout->addWidget(bCreatePQ, 15, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, 0, -1, -1);
        label_5 = new QLabel(FormPriorityCreate);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_9->addWidget(label_5);

        spinPriceFrom = new QSpinBox(FormPriorityCreate);
        spinPriceFrom->setObjectName(QStringLiteral("spinPriceFrom"));
        spinPriceFrom->setMaximum(1000000000);
        spinPriceFrom->setSingleStep(1);

        horizontalLayout_9->addWidget(spinPriceFrom);

        label_6 = new QLabel(FormPriorityCreate);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_9->addWidget(label_6);

        spinPriceTo = new QSpinBox(FormPriorityCreate);
        spinPriceTo->setObjectName(QStringLiteral("spinPriceTo"));
        spinPriceTo->setMaximum(1000000000);

        horizontalLayout_9->addWidget(spinPriceTo);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_10);


        gridLayout->addLayout(horizontalLayout_9, 13, 0, 1, 1);

        line_2 = new QFrame(FormPriorityCreate);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        groupBox = new QGroupBox(FormPriorityCreate);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setAlignment(Qt::AlignCenter);
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        rbTelephoneYes = new QRadioButton(groupBox);
        rbTelephoneYes->setObjectName(QStringLiteral("rbTelephoneYes"));
        rbTelephoneYes->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(rbTelephoneYes);

        rbTelephoneNo = new QRadioButton(groupBox);
        rbTelephoneNo->setObjectName(QStringLiteral("rbTelephoneNo"));
        rbTelephoneNo->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(rbTelephoneNo);

        rbTelephoneDontCare = new QRadioButton(groupBox);
        rbTelephoneDontCare->setObjectName(QStringLiteral("rbTelephoneDontCare"));
        rbTelephoneDontCare->setCursor(QCursor(Qt::PointingHandCursor));
        rbTelephoneDontCare->setChecked(true);

        horizontalLayout_4->addWidget(rbTelephoneDontCare);


        horizontalLayout_12->addWidget(groupBox);

        gbWasher = new QGroupBox(FormPriorityCreate);
        gbWasher->setObjectName(QStringLiteral("gbWasher"));
        gbWasher->setMinimumSize(QSize(0, 0));
        gbWasher->setMaximumSize(QSize(16777215, 16777215));
        gbWasher->setAlignment(Qt::AlignCenter);
        horizontalLayout_2 = new QHBoxLayout(gbWasher);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        rbWasherYes = new QRadioButton(gbWasher);
        rbWasherYes->setObjectName(QStringLiteral("rbWasherYes"));
        rbWasherYes->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(rbWasherYes);

        rbWasherNo = new QRadioButton(gbWasher);
        rbWasherNo->setObjectName(QStringLiteral("rbWasherNo"));
        rbWasherNo->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(rbWasherNo);

        rbWasherDontCare = new QRadioButton(gbWasher);
        rbWasherDontCare->setObjectName(QStringLiteral("rbWasherDontCare"));
        rbWasherDontCare->setCursor(QCursor(Qt::PointingHandCursor));
        rbWasherDontCare->setChecked(true);

        horizontalLayout_2->addWidget(rbWasherDontCare);


        horizontalLayout_12->addWidget(gbWasher);


        gridLayout->addLayout(horizontalLayout_12, 8, 0, 1, 1);

        chkPhoto = new QCheckBox(FormPriorityCreate);
        chkPhoto->setObjectName(QStringLiteral("chkPhoto"));

        gridLayout->addWidget(chkPhoto, 14, 0, 1, 1);

        line = new QFrame(FormPriorityCreate);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);


        retranslateUi(FormPriorityCreate);

        QMetaObject::connectSlotsByName(FormPriorityCreate);
    } // setupUi

    void retranslateUi(QWidget *FormPriorityCreate)
    {
        FormPriorityCreate->setWindowTitle(QApplication::translate("FormPriorityCreate", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\277\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202\320\275\320\276\320\263\320\276 \320\267\320\260\320\277\321\200\320\276\321\201\320\260", 0));
        gbSquare->setTitle(QApplication::translate("FormPriorityCreate", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214 (\320\272\320\262.\320\274.)", 0));
        label_9->setText(QApplication::translate("FormPriorityCreate", "\320\264\320\276", 0));
        label_2->setText(QApplication::translate("FormPriorityCreate", "\320\236\320\261\321\211\320\260\321\217:", 0));
        label_4->setText(QApplication::translate("FormPriorityCreate", "\320\226\320\270\320\273\320\260\321\217:", 0));
        label_3->setText(QApplication::translate("FormPriorityCreate", "\320\264\320\276", 0));
        label_10->setText(QApplication::translate("FormPriorityCreate", "\320\232\321\203\321\205\320\275\321\217:", 0));
        label_11->setText(QApplication::translate("FormPriorityCreate", "\320\264\320\276", 0));
        label_12->setText(QApplication::translate("FormPriorityCreate", "\320\276\321\202", 0));
        label_13->setText(QApplication::translate("FormPriorityCreate", "\320\276\321\202", 0));
        label_14->setText(QApplication::translate("FormPriorityCreate", "\320\276\321\202", 0));
        gbPeriod->setTitle(QApplication::translate("FormPriorityCreate", "\320\241\321\200\320\276\320\272 (\320\274\320\265\321\201\321\217\321\206\321\213)", 0));
        chkPeriodLong->setText(QApplication::translate("FormPriorityCreate", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271", 0));
        label_7->setText(QApplication::translate("FormPriorityCreate", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\272\320\276\320\274\320\275\320\260\321\202: \320\276\321\202", 0));
        label_8->setText(QApplication::translate("FormPriorityCreate", "\320\264\320\276", 0));
        labelArea->setText(QApplication::translate("FormPriorityCreate", "\320\240\320\260\320\271\320\276\320\275", 0));
        labelMetro->setText(QApplication::translate("FormPriorityCreate", "\320\234\320\265\321\202\321\200\320\276", 0));
        label->setText(QApplication::translate("FormPriorityCreate", "\320\242\320\270\320\277 \320\267\320\260\320\277\321\200\320\276\321\201\320\260", 0));
        cbQueryType->clear();
        cbQueryType->insertItems(0, QStringList()
         << QApplication::translate("FormPriorityCreate", "\320\241\320\264\320\260\320\274", 0)
         << QApplication::translate("FormPriorityCreate", "\320\241\320\275\320\270\320\274\321\203", 0)
         << QApplication::translate("FormPriorityCreate", "\320\237\321\200\320\276\320\264\320\260\320\274", 0)
         << QApplication::translate("FormPriorityCreate", "\320\232\321\203\320\277\320\273\321\216", 0)
        );
        labelCity->setText(QApplication::translate("FormPriorityCreate", "\320\223\320\276\321\200\320\276\320\264", 0));
        gbFridge->setTitle(QApplication::translate("FormPriorityCreate", "\320\245\320\276\320\273\320\276\320\264\320\270\320\273\321\214\320\275\320\270\320\272", 0));
        rbFridgeYes->setText(QApplication::translate("FormPriorityCreate", "\320\224\320\260", 0));
        rbFridgeNo->setText(QApplication::translate("FormPriorityCreate", "\320\235\320\265\321\202", 0));
        rbFridgeDontCare->setText(QApplication::translate("FormPriorityCreate", "\320\235\320\265 \320\270\320\274\320\265\320\265\321\202 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", 0));
        gbFurniture->setTitle(QApplication::translate("FormPriorityCreate", "\320\234\320\265\320\261\320\265\320\273\321\214", 0));
        rbFurnitureYes->setText(QApplication::translate("FormPriorityCreate", "\320\224\320\260", 0));
        rbFurnitureNo->setText(QApplication::translate("FormPriorityCreate", "\320\235\320\265\321\202", 0));
        rbFurnitureDontCare->setText(QApplication::translate("FormPriorityCreate", "\320\235\320\265 \320\270\320\274\320\265\320\265\321\202 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", 0));
        bCreatePQ->setText(QApplication::translate("FormPriorityCreate", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202\320\275\321\213\320\271 \320\267\320\260\320\277\321\200\320\276\321\201", 0));
        label_5->setText(QApplication::translate("FormPriorityCreate", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 (\321\200\321\203\320\261.): \320\276\321\202", 0));
        spinPriceFrom->setSuffix(QString());
        label_6->setText(QApplication::translate("FormPriorityCreate", "\320\264\320\276", 0));
        groupBox->setTitle(QApplication::translate("FormPriorityCreate", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", 0));
        rbTelephoneYes->setText(QApplication::translate("FormPriorityCreate", "\320\224\320\260", 0));
        rbTelephoneNo->setText(QApplication::translate("FormPriorityCreate", "\320\235\320\265\321\202", 0));
        rbTelephoneDontCare->setText(QApplication::translate("FormPriorityCreate", "\320\235\320\265 \320\270\320\274\320\265\320\265\321\202 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", 0));
        gbWasher->setTitle(QApplication::translate("FormPriorityCreate", "\320\241\321\202\320\270\321\200\320\260\320\273\321\214\320\275\320\260\321\217 \320\274\320\260\321\210\320\270\320\275\320\260", 0));
        rbWasherYes->setText(QApplication::translate("FormPriorityCreate", "\320\224\320\260", 0));
        rbWasherNo->setText(QApplication::translate("FormPriorityCreate", "\320\235\320\265\321\202", 0));
        rbWasherDontCare->setText(QApplication::translate("FormPriorityCreate", "\320\235\320\265 \320\270\320\274\320\265\320\265\321\202 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", 0));
        chkPhoto->setText(QApplication::translate("FormPriorityCreate", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class FormPriorityCreate: public Ui_FormPriorityCreate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPRIORITYCREATE_H
