/********************************************************************************
** Form generated from reading UI file 'board.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD_H
#define UI_BOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Board
{
public:
    QPushButton *player1;
    QPushButton *player2;
    QPushButton *player4;
    QPushButton *player3;
    QPushButton *player5;
    QPushButton *player6;
    QPushButton *player7;
    QPushButton *player8;
    QPushButton *backOptions;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QLineEdit *tour;
    QTextBrowser *textBrowser;
    QLineEdit *nbDefusing;
    QLineEdit *round;
    QPushButton *card4;
    QPushButton *card5;
    QPushButton *card3;
    QPushButton *card2;
    QPushButton *card1;
    QPushButton *role;

    void setupUi(QWidget *Board)
    {
        if (Board->objectName().isEmpty())
            Board->setObjectName(QStringLiteral("Board"));
        Board->resize(1510, 907);
        player1 = new QPushButton(Board);
        player1->setObjectName(QStringLiteral("player1"));
        player1->setGeometry(QRect(40, 480, 151, 261));
        player2 = new QPushButton(Board);
        player2->setObjectName(QStringLiteral("player2"));
        player2->setGeometry(QRect(210, 480, 151, 261));
        player4 = new QPushButton(Board);
        player4->setObjectName(QStringLiteral("player4"));
        player4->setGeometry(QRect(550, 480, 151, 261));
        player3 = new QPushButton(Board);
        player3->setObjectName(QStringLiteral("player3"));
        player3->setGeometry(QRect(380, 480, 151, 261));
        player5 = new QPushButton(Board);
        player5->setObjectName(QStringLiteral("player5"));
        player5->setGeometry(QRect(710, 480, 151, 261));
        player6 = new QPushButton(Board);
        player6->setObjectName(QStringLiteral("player6"));
        player6->setGeometry(QRect(880, 480, 151, 261));
        player7 = new QPushButton(Board);
        player7->setObjectName(QStringLiteral("player7"));
        player7->setGeometry(QRect(1050, 480, 151, 261));
        player8 = new QPushButton(Board);
        player8->setObjectName(QStringLiteral("player8"));
        player8->setGeometry(QRect(1220, 480, 151, 261));
        backOptions = new QPushButton(Board);
        backOptions->setObjectName(QStringLiteral("backOptions"));
        backOptions->setGeometry(QRect(10, 20, 89, 25));
        textBrowser_2 = new QTextBrowser(Board);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(1060, 10, 131, 31));
        textBrowser_3 = new QTextBrowser(Board);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(1240, 10, 71, 31));
        tour = new QLineEdit(Board);
        tour->setObjectName(QStringLiteral("tour"));
        tour->setGeometry(QRect(1210, 40, 141, 31));
        textBrowser = new QTextBrowser(Board);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(940, 10, 71, 31));
        nbDefusing = new QLineEdit(Board);
        nbDefusing->setObjectName(QStringLiteral("nbDefusing"));
        nbDefusing->setGeometry(QRect(1060, 40, 141, 31));
        round = new QLineEdit(Board);
        round->setObjectName(QStringLiteral("round"));
        round->setGeometry(QRect(910, 40, 141, 31));
        card4 = new QPushButton(Board);
        card4->setObjectName(QStringLiteral("card4"));
        card4->setGeometry(QRect(930, 190, 151, 261));
        card5 = new QPushButton(Board);
        card5->setObjectName(QStringLiteral("card5"));
        card5->setGeometry(QRect(1090, 190, 151, 261));
        card3 = new QPushButton(Board);
        card3->setObjectName(QStringLiteral("card3"));
        card3->setGeometry(QRect(760, 190, 151, 261));
        card2 = new QPushButton(Board);
        card2->setObjectName(QStringLiteral("card2"));
        card2->setGeometry(QRect(590, 190, 151, 261));
        card1 = new QPushButton(Board);
        card1->setObjectName(QStringLiteral("card1"));
        card1->setGeometry(QRect(420, 190, 151, 261));
        role = new QPushButton(Board);
        role->setObjectName(QStringLiteral("role"));
        role->setGeometry(QRect(50, 180, 151, 261));

        retranslateUi(Board);

        QMetaObject::connectSlotsByName(Board);
    } // setupUi

    void retranslateUi(QWidget *Board)
    {
        Board->setWindowTitle(QApplication::translate("Board", "Form", Q_NULLPTR));
        player1->setText(QString());
        player2->setText(QString());
        player4->setText(QString());
        player3->setText(QString());
        player5->setText(QString());
        player6->setText(QString());
        player7->setText(QString());
        player8->setText(QString());
        backOptions->setText(QApplication::translate("Board", "BACK", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("Board", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Defusing cards</p></body></html>", Q_NULLPTR));
        textBrowser_3->setHtml(QApplication::translate("Board", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">TOUR</p></body></html>", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("Board", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">ROUND</p></body></html>", Q_NULLPTR));
        card4->setText(QString());
        card5->setText(QString());
        card3->setText(QString());
        card2->setText(QString());
        card1->setText(QString());
        role->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Board: public Ui_Board {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD_H
