/********************************************************************************
** Form generated from reading UI file 'cards.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDS_H
#define UI_CARDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cards
{
public:
    QPushButton *pushButton_6;
    QPushButton *close;

    void setupUi(QWidget *Cards)
    {
        if (Cards->objectName().isEmpty())
            Cards->setObjectName(QStringLiteral("Cards"));
        Cards->resize(754, 409);
        pushButton_6 = new QPushButton(Cards);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(310, 10, 121, 181));
        close = new QPushButton(Cards);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(700, 10, 51, 31));

        retranslateUi(Cards);

        QMetaObject::connectSlotsByName(Cards);
    } // setupUi

    void retranslateUi(QWidget *Cards)
    {
        Cards->setWindowTitle(QApplication::translate("Cards", "Form", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Cards", "ROLE", Q_NULLPTR));
        close->setText(QApplication::translate("Cards", "X", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Cards: public Ui_Cards {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDS_H
