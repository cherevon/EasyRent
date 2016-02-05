/********************************************************************************
** Form generated from reading UI file 'AuthWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHWIDGET_H
#define UI_AUTHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *lblLogin;
    QSpacerItem *verticalSpacer;
    QPushButton *bLogin;
    QLabel *lblPassword;
    QPushButton *bRegister;
    QLineEdit *ePassword;
    QLineEdit *eLogin;

    void setupUi(QWidget *AuthWidget)
    {
        if (AuthWidget->objectName().isEmpty())
            AuthWidget->setObjectName(QStringLiteral("AuthWidget"));
        AuthWidget->resize(334, 115);
        AuthWidget->setWindowOpacity(1);
        AuthWidget->setAutoFillBackground(false);
        AuthWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(AuthWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblLogin = new QLabel(AuthWidget);
        lblLogin->setObjectName(QStringLiteral("lblLogin"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblLogin->sizePolicy().hasHeightForWidth());
        lblLogin->setSizePolicy(sizePolicy);
        lblLogin->setAutoFillBackground(true);
        lblLogin->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lblLogin, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        bLogin = new QPushButton(AuthWidget);
        bLogin->setObjectName(QStringLiteral("bLogin"));
        bLogin->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(bLogin, 3, 1, 1, 1);

        lblPassword = new QLabel(AuthWidget);
        lblPassword->setObjectName(QStringLiteral("lblPassword"));
        sizePolicy.setHeightForWidth(lblPassword->sizePolicy().hasHeightForWidth());
        lblPassword->setSizePolicy(sizePolicy);
        lblPassword->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lblPassword, 1, 0, 1, 1);

        bRegister = new QPushButton(AuthWidget);
        bRegister->setObjectName(QStringLiteral("bRegister"));
        bRegister->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(bRegister, 3, 2, 1, 1);

        ePassword = new QLineEdit(AuthWidget);
        ePassword->setObjectName(QStringLiteral("ePassword"));
        ePassword->setMouseTracking(false);
        ePassword->setStyleSheet(QStringLiteral(""));
        ePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(ePassword, 1, 1, 1, 2);

        eLogin = new QLineEdit(AuthWidget);
        eLogin->setObjectName(QStringLiteral("eLogin"));
        eLogin->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(eLogin, 0, 1, 1, 2);

        QWidget::setTabOrder(eLogin, ePassword);
        QWidget::setTabOrder(ePassword, bLogin);
        QWidget::setTabOrder(bLogin, bRegister);

        retranslateUi(AuthWidget);

        QMetaObject::connectSlotsByName(AuthWidget);
    } // setupUi

    void retranslateUi(QWidget *AuthWidget)
    {
        AuthWidget->setWindowTitle(QApplication::translate("AuthWidget", "\320\222\321\205\320\276\320\264 \320\262 ER", 0));
        lblLogin->setText(QApplication::translate("AuthWidget", "\320\233\320\276\320\263\320\270\320\275", 0));
        bLogin->setText(QApplication::translate("AuthWidget", "\320\222\321\205\320\276\320\264", 0));
        lblPassword->setText(QApplication::translate("AuthWidget", "\320\237\320\260\321\200\320\276\320\273\321\214", 0));
        bRegister->setText(QApplication::translate("AuthWidget", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", 0));
        ePassword->setInputMask(QString());
    } // retranslateUi

};

namespace Ui {
    class AuthWidget: public Ui_AuthWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHWIDGET_H
