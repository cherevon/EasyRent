/********************************************************************************
** Form generated from reading UI file 'WgtRegisterUser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGTREGISTERUSER_H
#define UI_WGTREGISTERUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WgtRegisterUser
{
public:
    QFormLayout *formLayout;
    QLabel *lblSurname;
    QLineEdit *eSurname;
    QLabel *lblName;
    QLineEdit *eName;
    QLabel *lblPatronymic;
    QLineEdit *ePatronymic;
    QLabel *lblCountry;
    QLabel *lblCity;
    QComboBox *cbCountry;
    QComboBox *cbCity;
    QLabel *lblUsername;
    QLabel *lblPassword;
    QLineEdit *eUsername;
    QLineEdit *ePassword;
    QLabel *lblPasswordRepeat;
    QLineEdit *ePasswordRepeat;
    QPushButton *bRegister;

    void setupUi(QWidget *WgtRegisterUser)
    {
        if (WgtRegisterUser->objectName().isEmpty())
            WgtRegisterUser->setObjectName(QStringLiteral("WgtRegisterUser"));
        WgtRegisterUser->resize(395, 282);
        formLayout = new QFormLayout(WgtRegisterUser);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        lblSurname = new QLabel(WgtRegisterUser);
        lblSurname->setObjectName(QStringLiteral("lblSurname"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblSurname);

        eSurname = new QLineEdit(WgtRegisterUser);
        eSurname->setObjectName(QStringLiteral("eSurname"));

        formLayout->setWidget(0, QFormLayout::FieldRole, eSurname);

        lblName = new QLabel(WgtRegisterUser);
        lblName->setObjectName(QStringLiteral("lblName"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblName);

        eName = new QLineEdit(WgtRegisterUser);
        eName->setObjectName(QStringLiteral("eName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, eName);

        lblPatronymic = new QLabel(WgtRegisterUser);
        lblPatronymic->setObjectName(QStringLiteral("lblPatronymic"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblPatronymic);

        ePatronymic = new QLineEdit(WgtRegisterUser);
        ePatronymic->setObjectName(QStringLiteral("ePatronymic"));
        ePatronymic->setClearButtonEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, ePatronymic);

        lblCountry = new QLabel(WgtRegisterUser);
        lblCountry->setObjectName(QStringLiteral("lblCountry"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblCountry);

        lblCity = new QLabel(WgtRegisterUser);
        lblCity->setObjectName(QStringLiteral("lblCity"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lblCity);

        cbCountry = new QComboBox(WgtRegisterUser);
        cbCountry->setObjectName(QStringLiteral("cbCountry"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cbCountry);

        cbCity = new QComboBox(WgtRegisterUser);
        cbCity->setObjectName(QStringLiteral("cbCity"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cbCity);

        lblUsername = new QLabel(WgtRegisterUser);
        lblUsername->setObjectName(QStringLiteral("lblUsername"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lblUsername);

        lblPassword = new QLabel(WgtRegisterUser);
        lblPassword->setObjectName(QStringLiteral("lblPassword"));

        formLayout->setWidget(6, QFormLayout::LabelRole, lblPassword);

        eUsername = new QLineEdit(WgtRegisterUser);
        eUsername->setObjectName(QStringLiteral("eUsername"));
        eUsername->setClearButtonEnabled(false);

        formLayout->setWidget(5, QFormLayout::FieldRole, eUsername);

        ePassword = new QLineEdit(WgtRegisterUser);
        ePassword->setObjectName(QStringLiteral("ePassword"));
        ePassword->setEchoMode(QLineEdit::Password);
        ePassword->setClearButtonEnabled(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, ePassword);

        lblPasswordRepeat = new QLabel(WgtRegisterUser);
        lblPasswordRepeat->setObjectName(QStringLiteral("lblPasswordRepeat"));

        formLayout->setWidget(7, QFormLayout::LabelRole, lblPasswordRepeat);

        ePasswordRepeat = new QLineEdit(WgtRegisterUser);
        ePasswordRepeat->setObjectName(QStringLiteral("ePasswordRepeat"));
        ePasswordRepeat->setEchoMode(QLineEdit::Password);
        ePasswordRepeat->setClearButtonEnabled(false);

        formLayout->setWidget(7, QFormLayout::FieldRole, ePasswordRepeat);

        bRegister = new QPushButton(WgtRegisterUser);
        bRegister->setObjectName(QStringLiteral("bRegister"));

        formLayout->setWidget(8, QFormLayout::SpanningRole, bRegister);


        retranslateUi(WgtRegisterUser);

        QMetaObject::connectSlotsByName(WgtRegisterUser);
    } // setupUi

    void retranslateUi(QWidget *WgtRegisterUser)
    {
        WgtRegisterUser->setWindowTitle(QApplication::translate("WgtRegisterUser", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217 EasyRent", 0));
        lblSurname->setText(QApplication::translate("WgtRegisterUser", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", 0));
        lblName->setText(QApplication::translate("WgtRegisterUser", "\320\230\320\274\321\217", 0));
        lblPatronymic->setText(QApplication::translate("WgtRegisterUser", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", 0));
        lblCountry->setText(QApplication::translate("WgtRegisterUser", "\320\241\321\202\321\200\320\260\320\275\320\260", 0));
        lblCity->setText(QApplication::translate("WgtRegisterUser", "\320\223\320\276\321\200\320\276\320\264", 0));
        lblUsername->setText(QApplication::translate("WgtRegisterUser", "\320\233\320\276\320\263\320\270\320\275", 0));
        lblPassword->setText(QApplication::translate("WgtRegisterUser", "\320\237\320\260\321\200\320\276\320\273\321\214", 0));
        lblPasswordRepeat->setText(QApplication::translate("WgtRegisterUser", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", 0));
        bRegister->setText(QApplication::translate("WgtRegisterUser", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class WgtRegisterUser: public Ui_WgtRegisterUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGTREGISTERUSER_H
