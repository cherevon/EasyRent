/********************************************************************************
** Form generated from reading UI file 'DlgRealEstateQueryEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGREALESTATEQUERYEDITOR_H
#define UI_DLGREALESTATEQUERYEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgUserQueryEditor
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *bSave;
    QPushButton *bCancel;
    QPlainTextEdit *eAdditionalInfo;
    QLabel *lblAdditionalInfo;
    QGroupBox *gbPhotos;
    QVBoxLayout *verticalLayout;
    QLabel *lblPhoto;
    QHBoxLayout *layoutPhotoButtons;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *bPreviousPhoto;
    QPushButton *bNextPhoto;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblQueryType;
    QComboBox *cbQueryType;
    QLabel *lblObjectType;
    QComboBox *cbRealEstateType;
    QLabel *lblCity;
    QComboBox *cbCity;
    QLabel *lblAddress;
    QLineEdit *eAddress;
    QLabel *lblContact;
    QLineEdit *eContact;
    QSpacerItem *verticalSpacer;
    QGroupBox *gbRooms;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *layoutFloors;
    QSpinBox *spinFirstFloor;
    QLabel *label;
    QSpinBox *spinLastFloor;
    QLabel *lblFloors;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spinPrice;
    QDoubleSpinBox *spinTotalSquare;
    QLabel *lblTotalSquare;
    QLabel *lblPrice;
    QFrame *line;

    void setupUi(QWidget *DlgUserQueryEditor)
    {
        if (DlgUserQueryEditor->objectName().isEmpty())
            DlgUserQueryEditor->setObjectName(QStringLiteral("DlgUserQueryEditor"));
        DlgUserQueryEditor->resize(724, 646);
        gridLayout = new QGridLayout(DlgUserQueryEditor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bSave = new QPushButton(DlgUserQueryEditor);
        bSave->setObjectName(QStringLiteral("bSave"));

        horizontalLayout->addWidget(bSave);

        bCancel = new QPushButton(DlgUserQueryEditor);
        bCancel->setObjectName(QStringLiteral("bCancel"));
        bCancel->setFlat(false);

        horizontalLayout->addWidget(bCancel);


        gridLayout->addLayout(horizontalLayout, 15, 0, 1, 2);

        eAdditionalInfo = new QPlainTextEdit(DlgUserQueryEditor);
        eAdditionalInfo->setObjectName(QStringLiteral("eAdditionalInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(eAdditionalInfo->sizePolicy().hasHeightForWidth());
        eAdditionalInfo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(eAdditionalInfo, 14, 0, 1, 2);

        lblAdditionalInfo = new QLabel(DlgUserQueryEditor);
        lblAdditionalInfo->setObjectName(QStringLiteral("lblAdditionalInfo"));
        lblAdditionalInfo->setTextFormat(Qt::RichText);

        gridLayout->addWidget(lblAdditionalInfo, 11, 0, 1, 2);

        gbPhotos = new QGroupBox(DlgUserQueryEditor);
        gbPhotos->setObjectName(QStringLiteral("gbPhotos"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gbPhotos->sizePolicy().hasHeightForWidth());
        gbPhotos->setSizePolicy(sizePolicy1);
        gbPhotos->setFlat(false);
        verticalLayout = new QVBoxLayout(gbPhotos);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblPhoto = new QLabel(gbPhotos);
        lblPhoto->setObjectName(QStringLiteral("lblPhoto"));
        lblPhoto->setMinimumSize(QSize(256, 256));
        lblPhoto->setMaximumSize(QSize(256, 256));
        lblPhoto->setFrameShape(QFrame::NoFrame);
        lblPhoto->setFrameShadow(QFrame::Sunken);
        lblPhoto->setLineWidth(1);

        verticalLayout->addWidget(lblPhoto);

        layoutPhotoButtons = new QHBoxLayout();
        layoutPhotoButtons->setObjectName(QStringLiteral("layoutPhotoButtons"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutPhotoButtons->addItem(horizontalSpacer_3);

        bPreviousPhoto = new QPushButton(gbPhotos);
        bPreviousPhoto->setObjectName(QStringLiteral("bPreviousPhoto"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bPreviousPhoto->sizePolicy().hasHeightForWidth());
        bPreviousPhoto->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/previous.ico"), QSize(), QIcon::Normal, QIcon::Off);
        bPreviousPhoto->setIcon(icon);
        bPreviousPhoto->setAutoDefault(false);
        bPreviousPhoto->setFlat(true);

        layoutPhotoButtons->addWidget(bPreviousPhoto);

        bNextPhoto = new QPushButton(gbPhotos);
        bNextPhoto->setObjectName(QStringLiteral("bNextPhoto"));
        sizePolicy2.setHeightForWidth(bNextPhoto->sizePolicy().hasHeightForWidth());
        bNextPhoto->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/next.ico"), QSize(), QIcon::Normal, QIcon::Off);
        bNextPhoto->setIcon(icon1);
        bNextPhoto->setAutoDefault(false);
        bNextPhoto->setFlat(true);

        layoutPhotoButtons->addWidget(bNextPhoto);

        layoutPhotoButtons->setStretch(0, 1);

        verticalLayout->addLayout(layoutPhotoButtons);


        gridLayout->addWidget(gbPhotos, 3, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblQueryType = new QLabel(DlgUserQueryEditor);
        lblQueryType->setObjectName(QStringLiteral("lblQueryType"));

        verticalLayout_2->addWidget(lblQueryType);

        cbQueryType = new QComboBox(DlgUserQueryEditor);
        cbQueryType->setObjectName(QStringLiteral("cbQueryType"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cbQueryType->sizePolicy().hasHeightForWidth());
        cbQueryType->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(cbQueryType);

        lblObjectType = new QLabel(DlgUserQueryEditor);
        lblObjectType->setObjectName(QStringLiteral("lblObjectType"));

        verticalLayout_2->addWidget(lblObjectType);

        cbRealEstateType = new QComboBox(DlgUserQueryEditor);
        cbRealEstateType->setObjectName(QStringLiteral("cbRealEstateType"));
        sizePolicy3.setHeightForWidth(cbRealEstateType->sizePolicy().hasHeightForWidth());
        cbRealEstateType->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(cbRealEstateType);

        lblCity = new QLabel(DlgUserQueryEditor);
        lblCity->setObjectName(QStringLiteral("lblCity"));

        verticalLayout_2->addWidget(lblCity);

        cbCity = new QComboBox(DlgUserQueryEditor);
        cbCity->setObjectName(QStringLiteral("cbCity"));
        sizePolicy3.setHeightForWidth(cbCity->sizePolicy().hasHeightForWidth());
        cbCity->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(cbCity);

        lblAddress = new QLabel(DlgUserQueryEditor);
        lblAddress->setObjectName(QStringLiteral("lblAddress"));

        verticalLayout_2->addWidget(lblAddress);

        eAddress = new QLineEdit(DlgUserQueryEditor);
        eAddress->setObjectName(QStringLiteral("eAddress"));
        eAddress->setMaxLength(255);
        eAddress->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(eAddress);

        lblContact = new QLabel(DlgUserQueryEditor);
        lblContact->setObjectName(QStringLiteral("lblContact"));
        lblContact->setTextFormat(Qt::RichText);

        verticalLayout_2->addWidget(lblContact);

        eContact = new QLineEdit(DlgUserQueryEditor);
        eContact->setObjectName(QStringLiteral("eContact"));
        eContact->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(eContact);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 4, 1);

        gbRooms = new QGroupBox(DlgUserQueryEditor);
        gbRooms->setObjectName(QStringLiteral("gbRooms"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(gbRooms->sizePolicy().hasHeightForWidth());
        gbRooms->setSizePolicy(sizePolicy4);
        verticalLayout_3 = new QVBoxLayout(gbRooms);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        gridLayout->addWidget(gbRooms, 10, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(21);
        layoutFloors = new QHBoxLayout();
        layoutFloors->setObjectName(QStringLiteral("layoutFloors"));
        spinFirstFloor = new QSpinBox(DlgUserQueryEditor);
        spinFirstFloor->setObjectName(QStringLiteral("spinFirstFloor"));
        sizePolicy3.setHeightForWidth(spinFirstFloor->sizePolicy().hasHeightForWidth());
        spinFirstFloor->setSizePolicy(sizePolicy3);
        spinFirstFloor->setWrapping(false);
        spinFirstFloor->setAccelerated(true);
        spinFirstFloor->setProperty("showGroupSeparator", QVariant(true));
        spinFirstFloor->setMinimum(1);
        spinFirstFloor->setMaximum(500);
        spinFirstFloor->setSingleStep(1);
        spinFirstFloor->setDisplayIntegerBase(10);

        layoutFloors->addWidget(spinFirstFloor);

        label = new QLabel(DlgUserQueryEditor);
        label->setObjectName(QStringLiteral("label"));

        layoutFloors->addWidget(label);

        spinLastFloor = new QSpinBox(DlgUserQueryEditor);
        spinLastFloor->setObjectName(QStringLiteral("spinLastFloor"));
        sizePolicy3.setHeightForWidth(spinLastFloor->sizePolicy().hasHeightForWidth());
        spinLastFloor->setSizePolicy(sizePolicy3);
        spinLastFloor->setWrapping(false);
        spinLastFloor->setAccelerated(true);
        spinLastFloor->setProperty("showGroupSeparator", QVariant(true));
        spinLastFloor->setMinimum(1);
        spinLastFloor->setMaximum(500);
        spinLastFloor->setSingleStep(1);
        spinLastFloor->setDisplayIntegerBase(10);

        layoutFloors->addWidget(spinLastFloor);


        gridLayout_2->addLayout(layoutFloors, 1, 3, 1, 1);

        lblFloors = new QLabel(DlgUserQueryEditor);
        lblFloors->setObjectName(QStringLiteral("lblFloors"));
        sizePolicy3.setHeightForWidth(lblFloors->sizePolicy().hasHeightForWidth());
        lblFloors->setSizePolicy(sizePolicy3);
        lblFloors->setTextFormat(Qt::RichText);

        gridLayout_2->addWidget(lblFloors, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 7, 1, 1);

        spinPrice = new QSpinBox(DlgUserQueryEditor);
        spinPrice->setObjectName(QStringLiteral("spinPrice"));
        sizePolicy3.setHeightForWidth(spinPrice->sizePolicy().hasHeightForWidth());
        spinPrice->setSizePolicy(sizePolicy3);
        spinPrice->setWrapping(false);
        spinPrice->setAccelerated(true);
        spinPrice->setProperty("showGroupSeparator", QVariant(true));
        spinPrice->setMinimum(0);
        spinPrice->setMaximum(2147483647);
        spinPrice->setSingleStep(1000);
        spinPrice->setDisplayIntegerBase(10);

        gridLayout_2->addWidget(spinPrice, 1, 0, 1, 1);

        spinTotalSquare = new QDoubleSpinBox(DlgUserQueryEditor);
        spinTotalSquare->setObjectName(QStringLiteral("spinTotalSquare"));
        sizePolicy3.setHeightForWidth(spinTotalSquare->sizePolicy().hasHeightForWidth());
        spinTotalSquare->setSizePolicy(sizePolicy3);
        spinTotalSquare->setAccelerated(true);
        spinTotalSquare->setDecimals(2);
        spinTotalSquare->setMaximum(1e+06);
        spinTotalSquare->setSingleStep(0.1);
        spinTotalSquare->setValue(0);

        gridLayout_2->addWidget(spinTotalSquare, 1, 1, 1, 1);

        lblTotalSquare = new QLabel(DlgUserQueryEditor);
        lblTotalSquare->setObjectName(QStringLiteral("lblTotalSquare"));
        sizePolicy3.setHeightForWidth(lblTotalSquare->sizePolicy().hasHeightForWidth());
        lblTotalSquare->setSizePolicy(sizePolicy3);
        lblTotalSquare->setTextFormat(Qt::RichText);

        gridLayout_2->addWidget(lblTotalSquare, 0, 1, 1, 1);

        lblPrice = new QLabel(DlgUserQueryEditor);
        lblPrice->setObjectName(QStringLiteral("lblPrice"));

        gridLayout_2->addWidget(lblPrice, 0, 0, 1, 1);

        line = new QFrame(DlgUserQueryEditor);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 0, 2, 2, 1);


        gridLayout->addLayout(gridLayout_2, 6, 0, 1, 2);

        gridLayout->setColumnStretch(0, 1);
        QWidget::setTabOrder(cbQueryType, cbCity);
        QWidget::setTabOrder(cbCity, eAddress);
        QWidget::setTabOrder(eAddress, eContact);
        QWidget::setTabOrder(eContact, spinPrice);
        QWidget::setTabOrder(spinPrice, spinTotalSquare);
        QWidget::setTabOrder(spinTotalSquare, eAdditionalInfo);
        QWidget::setTabOrder(eAdditionalInfo, bSave);
        QWidget::setTabOrder(bSave, bCancel);

        retranslateUi(DlgUserQueryEditor);

        QMetaObject::connectSlotsByName(DlgUserQueryEditor);
    } // setupUi

    void retranslateUi(QWidget *DlgUserQueryEditor)
    {
        DlgUserQueryEditor->setWindowTitle(QApplication::translate("DlgUserQueryEditor", "Dialog", 0));
        bSave->setText(QApplication::translate("DlgUserQueryEditor", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        bCancel->setText(QApplication::translate("DlgUserQueryEditor", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        lblAdditionalInfo->setText(QApplication::translate("DlgUserQueryEditor", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \321\201\320\262\320\265\320\264\320\265\320\275\320\270\321\217", 0));
        gbPhotos->setTitle(QApplication::translate("DlgUserQueryEditor", "\320\244\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270", 0));
        lblPhoto->setText(QString());
        bPreviousPhoto->setText(QString());
        bNextPhoto->setText(QString());
        lblQueryType->setText(QApplication::translate("DlgUserQueryEditor", "\320\236\320\277\320\265\321\200\320\260\321\206\320\270\321\217", 0));
        lblObjectType->setText(QApplication::translate("DlgUserQueryEditor", "\320\222\320\270\320\264 \320\275\320\265\320\264\320\262\320\270\320\266\320\270\320\274\320\276\321\201\321\202\320\270", 0));
        lblCity->setText(QApplication::translate("DlgUserQueryEditor", "\320\223\320\276\321\200\320\276\320\264", 0));
        lblAddress->setText(QApplication::translate("DlgUserQueryEditor", "\320\220\320\264\321\200\320\265\321\201", 0));
        lblContact->setText(QApplication::translate("DlgUserQueryEditor", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
        gbRooms->setTitle(QApplication::translate("DlgUserQueryEditor", "\320\237\320\276\320\274\320\265\321\211\320\265\320\275\320\270\321\217", 0));
        spinFirstFloor->setSuffix(QString());
        label->setText(QApplication::translate("DlgUserQueryEditor", " - ", 0));
        spinLastFloor->setSuffix(QString());
        lblFloors->setText(QApplication::translate("DlgUserQueryEditor", "\320\227\320\260\320\275\320\270\320\274\320\260\320\265\320\274\321\213\320\265 \321\215\321\202\320\260\320\266\320\270", 0));
        spinPrice->setSuffix(QApplication::translate("DlgUserQueryEditor", " \321\200\321\203\320\261.", 0));
        spinTotalSquare->setPrefix(QString());
        spinTotalSquare->setSuffix(QApplication::translate("DlgUserQueryEditor", " \320\272\320\262. \320\274.", 0));
        lblTotalSquare->setText(QApplication::translate("DlgUserQueryEditor", "\320\236\320\261\321\211\320\260\321\217 \320\277\320\273\320\276\321\211\320\260\320\264\321\214", 0));
        lblPrice->setText(QApplication::translate("DlgUserQueryEditor", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", 0));
    } // retranslateUi

};

namespDlgRealEstateQueryEditor DlgUserQueryEditor: public Ui_DlgUserQueryEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGREALESTATEQUERYEDITOR_H
