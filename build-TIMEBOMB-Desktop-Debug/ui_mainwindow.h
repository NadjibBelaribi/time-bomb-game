/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(873, 606);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow\n"
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
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        menu = new QStackedWidget(centralWidget);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setStyleSheet(QStringLiteral(""));
        start = new QWidget();
        start->setObjectName(QStringLiteral("start"));
        verticalLayoutWidget = new QWidget(start);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(159, 39, 531, 511));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        playB = new QPushButton(verticalLayoutWidget);
        playB->setObjectName(QStringLiteral("playB"));

        verticalLayout_3->addWidget(playB);

        help = new QPushButton(verticalLayoutWidget);
        help->setObjectName(QStringLiteral("help"));

        verticalLayout_3->addWidget(help);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        menu->addWidget(start);
        options = new QWidget();
        options->setObjectName(QStringLiteral("options"));
        back = new QPushButton(options);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(80, 60, 111, 51));
        nb4 = new QPushButton(options);
        nb4->setObjectName(QStringLiteral("nb4"));
        nb4->setGeometry(QRect(260, 80, 71, 25));
        nb5 = new QPushButton(options);
        nb5->setObjectName(QStringLiteral("nb5"));
        nb5->setGeometry(QRect(340, 80, 61, 25));
        nb6 = new QPushButton(options);
        nb6->setObjectName(QStringLiteral("nb6"));
        nb6->setGeometry(QRect(410, 80, 61, 25));
        nb7 = new QPushButton(options);
        nb7->setObjectName(QStringLiteral("nb7"));
        nb7->setGeometry(QRect(480, 80, 71, 25));
        nb8 = new QPushButton(options);
        nb8->setObjectName(QStringLiteral("nb8"));
        nb8->setGeometry(QRect(560, 80, 61, 25));
        gridLayoutWidget = new QWidget(options);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(220, 200, 351, 261));
        gridPseudo = new QGridLayout(gridLayoutWidget);
        gridPseudo->setSpacing(6);
        gridPseudo->setContentsMargins(11, 11, 11, 11);
        gridPseudo->setObjectName(QStringLiteral("gridPseudo"));
        gridPseudo->setContentsMargins(0, 0, 0, 0);
        go = new QPushButton(options);
        go->setObjectName(QStringLiteral("go"));
        go->setGeometry(QRect(640, 390, 89, 25));
        menu->addWidget(options);
        board = new QWidget();
        board->setObjectName(QStringLiteral("board"));
        card1 = new QPushButton(board);
        card1->setObjectName(QStringLiteral("card1"));
        card1->setGeometry(QRect(360, 80, 89, 151));
        card2 = new QPushButton(board);
        card2->setObjectName(QStringLiteral("card2"));
        card2->setGeometry(QRect(450, 80, 89, 151));
        card3 = new QPushButton(board);
        card3->setObjectName(QStringLiteral("card3"));
        card3->setGeometry(QRect(540, 80, 89, 151));
        card4 = new QPushButton(board);
        card4->setObjectName(QStringLiteral("card4"));
        card4->setGeometry(QRect(630, 80, 89, 151));
        card5 = new QPushButton(board);
        card5->setObjectName(QStringLiteral("card5"));
        card5->setGeometry(QRect(720, 80, 89, 151));
        role = new QPushButton(board);
        role->setObjectName(QStringLiteral("role"));
        role->setGeometry(QRect(170, 50, 89, 151));
        backOptions = new QPushButton(board);
        backOptions->setObjectName(QStringLiteral("backOptions"));
        backOptions->setGeometry(QRect(50, 50, 89, 31));
        round = new QLineEdit(board);
        round->setObjectName(QStringLiteral("round"));
        round->setGeometry(QRect(480, 40, 51, 25));
        nbDefusing = new QLineEdit(board);
        nbDefusing->setObjectName(QStringLiteral("nbDefusing"));
        nbDefusing->setGeometry(QRect(590, 40, 61, 25));
        tour = new QLineEdit(board);
        tour->setObjectName(QStringLiteral("tour"));
        tour->setGeometry(QRect(710, 40, 51, 25));
        textBrowser = new QTextBrowser(board);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(440, 0, 141, 31));
        textBrowser_2 = new QTextBrowser(board);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(560, 0, 121, 31));
        textBrowser_3 = new QTextBrowser(board);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
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
        aide->setObjectName(QStringLiteral("aide"));
        menu->addWidget(aide);

        verticalLayout_2->addWidget(menu);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        menu->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        playB->setText(QApplication::translate("MainWindow", "Jouer", Q_NULLPTR));
        help->setText(QApplication::translate("MainWindow", "Aide", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        back->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        nb4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        nb5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        nb6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        nb7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        nb8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        go->setText(QApplication::translate("MainWindow", "Go!", Q_NULLPTR));
        card1->setText(QString());
        card2->setText(QString());
        card3->setText(QString());
        card4->setText(QString());
        card5->setText(QString());
        role->setText(QString());
        backOptions->setText(QApplication::translate("MainWindow", "back", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Rounds</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Defusings</p></body></html>", Q_NULLPTR));
        textBrowser_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">        Tour</p></body></html>", Q_NULLPTR));
        player1->setText(QString());
        player2->setText(QString());
        player3->setText(QString());
        player4->setText(QString());
        player5->setText(QString());
        player6->setText(QString());
        player7->setText(QString());
        player8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
