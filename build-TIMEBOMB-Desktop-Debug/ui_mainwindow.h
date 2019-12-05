/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *menu;
    QWidget *start;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *playB;
    QPushButton *help;
    QPushButton *pushButton_3;
    QWidget *options;
    QPushButton *back;
    QPushButton *nb4;
    QPushButton *nb5;
    QPushButton *nb6;
    QPushButton *nb7;
    QPushButton *nb8;
    QWidget *gridLayoutWidget;
    QGridLayout *gridPseudo;
    QPushButton *go;
    QWidget *board;
    QPushButton *card1;
    QPushButton *card2;
    QPushButton *card3;
    QPushButton *card4;
    QPushButton *card5;
    QPushButton *role;
    QPushButton *backOptions;
    QLineEdit *round;
    QLineEdit *nbDefusing;
    QLineEdit *tour;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *player1;
    QPushButton *player2;
    QPushButton *player3;
    QPushButton *player4;
    QPushButton *player5;
    QPushButton *player6;
    QPushButton *player7;
    QPushButton *player8;
    QWidget *aide;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(873, 606);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"background-image:url(:/imgs/imgs/wall_accueil.jpg);\n"
"background-repeat:no-repeat;\n"
"border-image:url(:/imgs/imgs/wall_accueil.jpg) 0 0 0 0 stretch;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:white;\n"
"}\n"
"\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        menu = new QStackedWidget(centralWidget);
        menu->setObjectName(QString::fromUtf8("menu"));
        start = new QWidget();
        start->setObjectName(QString::fromUtf8("start"));
        verticalLayoutWidget = new QWidget(start);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(159, 39, 531, 511));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        playB = new QPushButton(verticalLayoutWidget);
        playB->setObjectName(QString::fromUtf8("playB"));

        verticalLayout_3->addWidget(playB);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_3->addWidget(help);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        menu->addWidget(start);
        options = new QWidget();
        options->setObjectName(QString::fromUtf8("options"));
        back = new QPushButton(options);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(80, 60, 111, 51));
        nb4 = new QPushButton(options);
        nb4->setObjectName(QString::fromUtf8("nb4"));
        nb4->setGeometry(QRect(260, 80, 71, 25));
        nb5 = new QPushButton(options);
        nb5->setObjectName(QString::fromUtf8("nb5"));
        nb5->setGeometry(QRect(340, 80, 61, 25));
        nb6 = new QPushButton(options);
        nb6->setObjectName(QString::fromUtf8("nb6"));
        nb6->setGeometry(QRect(410, 80, 61, 25));
        nb7 = new QPushButton(options);
        nb7->setObjectName(QString::fromUtf8("nb7"));
        nb7->setGeometry(QRect(480, 80, 71, 25));
        nb8 = new QPushButton(options);
        nb8->setObjectName(QString::fromUtf8("nb8"));
        nb8->setGeometry(QRect(560, 80, 61, 25));
        gridLayoutWidget = new QWidget(options);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(259, 159, 351, 261));
        gridPseudo = new QGridLayout(gridLayoutWidget);
        gridPseudo->setSpacing(6);
        gridPseudo->setContentsMargins(11, 11, 11, 11);
        gridPseudo->setObjectName(QString::fromUtf8("gridPseudo"));
        gridPseudo->setContentsMargins(0, 0, 0, 0);
        go = new QPushButton(options);
        go->setObjectName(QString::fromUtf8("go"));
        go->setGeometry(QRect(640, 390, 89, 25));
        menu->addWidget(options);
        board = new QWidget();
        board->setObjectName(QString::fromUtf8("board"));
        player1 = new QPushButton(board);
        player1->setObjectName(QString::fromUtf8("player1"));
        player1->setGeometry(QRect(40, 270, 89, 151));
        player2 = new QPushButton(board);
        player2->setObjectName(QString::fromUtf8("player2"));
        player2->setGeometry(QRect(140, 270, 89, 151));
        player3 = new QPushButton(board);
        player3->setObjectName(QString::fromUtf8("player3"));
        player3->setGeometry(QRect(240, 270, 89, 151));
        player4 = new QPushButton(board);
        player4->setObjectName(QString::fromUtf8("player4"));
        player4->setGeometry(QRect(340, 270, 89, 151));
        player5 = new QPushButton(board);
        player5->setObjectName(QString::fromUtf8("player5"));
        player5->setGeometry(QRect(440, 270, 89, 151));
        player6 = new QPushButton(board);
        player6->setObjectName(QString::fromUtf8("player6"));
        player6->setGeometry(QRect(540, 270, 89, 151));
        player7 = new QPushButton(board);
        player7->setObjectName(QString::fromUtf8("player7"));
        player7->setGeometry(QRect(640, 270, 89, 151));
        player8 = new QPushButton(board);
        player8->setObjectName(QString::fromUtf8("player8"));
        player8->setGeometry(QRect(740, 270, 89, 151));
        card1 = new QPushButton(board);
        card1->setObjectName(QString::fromUtf8("card1"));
        card1->setGeometry(QRect(360, 80, 89, 151));
        card2 = new QPushButton(board);
        card2->setObjectName(QString::fromUtf8("card2"));
        card2->setGeometry(QRect(450, 80, 89, 151));
        card3 = new QPushButton(board);
        card3->setObjectName(QString::fromUtf8("card3"));
        card3->setGeometry(QRect(540, 80, 89, 151));
        card4 = new QPushButton(board);
        card4->setObjectName(QString::fromUtf8("card4"));
        card4->setGeometry(QRect(630, 80, 89, 151));
        card5 = new QPushButton(board);
        card5->setObjectName(QString::fromUtf8("card5"));
        card5->setGeometry(QRect(720, 80, 89, 151));
        role = new QPushButton(board);
        role->setObjectName(QString::fromUtf8("role"));
        role->setGeometry(QRect(170, 50, 89, 151));
        backOptions = new QPushButton(board);
        backOptions->setObjectName(QString::fromUtf8("backOptions"));
        backOptions->setGeometry(QRect(50, 50, 89, 31));
        round = new QLineEdit(board);
        round->setObjectName(QString::fromUtf8("round"));
        round->setGeometry(QRect(480, 40, 51, 25));
        nbDefusing = new QLineEdit(board);
        nbDefusing->setObjectName(QString::fromUtf8("nbDefusing"));
        nbDefusing->setGeometry(QRect(590, 40, 61, 25));
        tour = new QLineEdit(board);
        tour->setObjectName(QString::fromUtf8("tour"));
        tour->setGeometry(QRect(710, 40, 51, 25));
        textBrowser = new QTextBrowser(board);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(440, 0, 141, 31));
        textBrowser_2 = new QTextBrowser(board);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(560, 0, 121, 31));
        textBrowser_3 = new QTextBrowser(board);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(680, 0, 121, 31));
        horizontalLayoutWidget = new QWidget(board);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 360, 844, 202));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        player1 = new QPushButton(horizontalLayoutWidget);
        player1->setObjectName(QStringLiteral("player1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(player1->sizePolicy().hasHeightForWidth());
        player1->setSizePolicy(sizePolicy);
        player1->setMinimumSize(QSize(100, 170));

        horizontalLayout->addWidget(player1);

        player2 = new QPushButton(horizontalLayoutWidget);
        player2->setObjectName(QStringLiteral("player2"));
        sizePolicy.setHeightForWidth(player2->sizePolicy().hasHeightForWidth());
        player2->setSizePolicy(sizePolicy);
        player2->setMinimumSize(QSize(100, 170));

        horizontalLayout->addWidget(player2);

        player3 = new QPushButton(horizontalLayoutWidget);
        player3->setObjectName(QStringLiteral("player3"));
        sizePolicy.setHeightForWidth(player3->sizePolicy().hasHeightForWidth());
        player3->setSizePolicy(sizePolicy);
        player3->setMinimumSize(QSize(100, 170));

        horizontalLayout->addWidget(player3);

        player4 = new QPushButton(horizontalLayoutWidget);
        player4->setObjectName(QStringLiteral("player4"));
        sizePolicy.setHeightForWidth(player4->sizePolicy().hasHeightForWidth());
        player4->setSizePolicy(sizePolicy);
        player4->setMinimumSize(QSize(100, 170));

        horizontalLayout->addWidget(player4);

        player5 = new QPushButton(horizontalLayoutWidget);
        player5->setObjectName(QStringLiteral("player5"));
        sizePolicy.setHeightForWidth(player5->sizePolicy().hasHeightForWidth());
        player5->setSizePolicy(sizePolicy);
        player5->setMinimumSize(QSize(100, 170));

        horizontalLayout->addWidget(player5);

        player6 = new QPushButton(horizontalLayoutWidget);
        player6->setObjectName(QStringLiteral("player6"));
        sizePolicy.setHeightForWidth(player6->sizePolicy().hasHeightForWidth());
        player6->setSizePolicy(sizePolicy);
        player6->setMinimumSize(QSize(100, 170));

        horizontalLayout->addWidget(player6);

        player7 = new QPushButton(horizontalLayoutWidget);
        player7->setObjectName(QStringLiteral("player7"));
        sizePolicy.setHeightForWidth(player7->sizePolicy().hasHeightForWidth());
        player7->setSizePolicy(sizePolicy);
        player7->setMinimumSize(QSize(100, 170));

        horizontalLayout->addWidget(player7);

        player8 = new QPushButton(horizontalLayoutWidget);
        player8->setObjectName(QStringLiteral("player8"));
        sizePolicy.setHeightForWidth(player8->sizePolicy().hasHeightForWidth());
        player8->setSizePolicy(sizePolicy);
        player8->setMinimumSize(QSize(100, 170));

        horizontalLayout->addWidget(player8);

        menu->addWidget(board);
        aide = new QWidget();
        aide->setObjectName(QString::fromUtf8("aide"));
        menu->addWidget(aide);

        verticalLayout_2->addWidget(menu);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        menu->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        playB->setText(QCoreApplication::translate("MainWindow", "Jouer", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Aide", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        back->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        nb4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        nb5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        nb6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        nb7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        nb8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        go->setText(QCoreApplication::translate("MainWindow", "Go!", nullptr));
        player1->setText(QString());
        player2->setText(QString());
        player3->setText(QString());
        player4->setText(QString());
        player5->setText(QString());
        player6->setText(QString());
        player7->setText(QString());
        player8->setText(QString());
        card1->setText(QString());
        card2->setText(QString());
        card3->setText(QString());
        card4->setText(QString());
        card5->setText(QString());
        role->setText(QString());
        backOptions->setText(QCoreApplication::translate("MainWindow", "back", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Rounds</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Defusings</p></body></html>", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">        Tour</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
