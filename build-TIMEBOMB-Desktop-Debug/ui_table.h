/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Table
{
public:
    QWidget *players_positions_2;
    QGridLayout *players_positions;
    QWidget *cards_positions_2;
    QGridLayout *cards_positions;
    QGridLayout *role_card;
    QPushButton *close_cards;
    QPushButton *backOptions;
    QTextBrowser *textBrowser_3;
    QLineEdit *nbDefusing;
    QTextBrowser *textBrowser_2;
    QLineEdit *round;
    QTextBrowser *textBrowser;
    QLineEdit *tour;

    void setupUi(QWidget *Table)
    {
        if (Table->objectName().isEmpty())
            Table->setObjectName(QStringLiteral("Table"));
        Table->resize(1440, 497);
        players_positions_2 = new QWidget(Table);
        players_positions_2->setObjectName(QStringLiteral("players_positions_2"));
        players_positions_2->setGeometry(QRect(30, 300, 821, 181));
        players_positions = new QGridLayout(players_positions_2);
        players_positions->setObjectName(QStringLiteral("players_positions"));
        cards_positions_2 = new QWidget(Table);
        cards_positions_2->setObjectName(QStringLiteral("cards_positions_2"));
        cards_positions_2->setGeometry(QRect(10, 220, 819, 179));
        cards_positions = new QGridLayout(cards_positions_2);
        cards_positions->setObjectName(QStringLiteral("cards_positions"));
        role_card = new QGridLayout();
        role_card->setObjectName(QStringLiteral("role_card"));

        cards_positions->addLayout(role_card, 0, 0, 1, 1);

        close_cards = new QPushButton(Table);
        close_cards->setObjectName(QStringLiteral("close_cards"));
        close_cards->setGeometry(QRect(740, 190, 89, 25));
        backOptions = new QPushButton(Table);
        backOptions->setObjectName(QStringLiteral("backOptions"));
        backOptions->setGeometry(QRect(80, 160, 89, 25));
        textBrowser_3 = new QTextBrowser(Table);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(1280, 40, 71, 31));
        nbDefusing = new QLineEdit(Table);
        nbDefusing->setObjectName(QStringLiteral("nbDefusing"));
        nbDefusing->setGeometry(QRect(1100, 70, 141, 31));
        textBrowser_2 = new QTextBrowser(Table);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(1100, 40, 131, 31));
        round = new QLineEdit(Table);
        round->setObjectName(QStringLiteral("round"));
        round->setGeometry(QRect(950, 70, 141, 31));
        textBrowser = new QTextBrowser(Table);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(980, 40, 71, 31));
        tour = new QLineEdit(Table);
        tour->setObjectName(QStringLiteral("tour"));
        tour->setGeometry(QRect(1250, 70, 141, 31));

        retranslateUi(Table);

        QMetaObject::connectSlotsByName(Table);
    } // setupUi

    void retranslateUi(QWidget *Table)
    {
        Table->setWindowTitle(QApplication::translate("Table", "Form", Q_NULLPTR));
        close_cards->setText(QApplication::translate("Table", "X", Q_NULLPTR));
        backOptions->setText(QApplication::translate("Table", "BACK", Q_NULLPTR));
        textBrowser_3->setHtml(QApplication::translate("Table", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">TOUR</p></body></html>", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("Table", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Defusing cards</p></body></html>", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("Table", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">ROUND</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Table: public Ui_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
