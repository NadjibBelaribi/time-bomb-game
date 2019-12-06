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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
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
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *playB;
    QSpacerItem *verticalSpacer_3;
    QPushButton *help;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *options;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *back;
    QPushButton *nb4;
    QPushButton *nb5;
    QPushButton *nb6;
    QPushButton *nb7;
    QPushButton *nb8;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridPseudo;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *go;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_7;
    QWidget *board;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_11;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *backOptions;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_21;
    QLineEdit *round;
    QLineEdit *nbDefusing;
    QLineEdit *tour;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *role;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *card1;
    QPushButton *card2;
    QPushButton *card3;
    QPushButton *card4;
    QPushButton *card5;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *horizontalLayout;
    QPushButton *player1;
    QPushButton *player2;
    QPushButton *player3;
    QPushButton *player4;
    QPushButton *player5;
    QPushButton *player6;
    QPushButton *player7;
    QPushButton *player8;
    QSpacerItem *verticalSpacer_12;
    QWidget *aide;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1095, 614);
        MainWindow->setMinimumSize(QSize(20, 30));
        MainWindow->setMaximumSize(QSize(1292, 614));
        MainWindow->setStyleSheet(QLatin1String("QMainWindow\n"
"{\n"
"background-image: url(:/imgs/imgs/london.jpg);\n"
"background-image:no-repeat;\n"
"border-image:url(:/imgs/imgs/london.jpg) 0 0 0 0 stretch ;\n"
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
        start->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	width: 200px;\n"
"	border: 1px solid snow;\n"
"	border-radius: 10px 10px 10px 10px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:DarkSlateBlue ;\n"
"}"));
        gridLayout = new QGridLayout(start);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        playB = new QPushButton(start);
        playB->setObjectName(QStringLiteral("playB"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(playB->sizePolicy().hasHeightForWidth());
        playB->setSizePolicy(sizePolicy);
        playB->setMinimumSize(QSize(60, 45));
        playB->setStyleSheet(QStringLiteral(" font: 75 33pt \"Purisa\";"));

        verticalLayout->addWidget(playB);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_3);

        help = new QPushButton(start);
        help->setObjectName(QStringLiteral("help"));
        help->setMinimumSize(QSize(60, 45));
        help->setStyleSheet(QStringLiteral(" font: 75 33pt \"Purisa\";"));

        verticalLayout->addWidget(help);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_4);

        pushButton_3 = new QPushButton(start);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(60, 45));
        pushButton_3->setStyleSheet(QStringLiteral(" font: 75 33pt \"Purisa\";"));

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        menu->addWidget(start);
        options = new QWidget();
        options->setObjectName(QStringLiteral("options"));
        options->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	width: 200px;\n"
"	border: 1px solid snow;\n"
"	border-radius: 10px 10px 10px 10px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:DarkSlateBlue ;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(options);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        back = new QPushButton(options);
        back->setObjectName(QStringLiteral("back"));

        horizontalLayout_5->addWidget(back);

        nb4 = new QPushButton(options);
        nb4->setObjectName(QStringLiteral("nb4"));
        nb4->setMinimumSize(QSize(169, 25));

        horizontalLayout_5->addWidget(nb4);

        nb5 = new QPushButton(options);
        nb5->setObjectName(QStringLiteral("nb5"));

        horizontalLayout_5->addWidget(nb5);

        nb6 = new QPushButton(options);
        nb6->setObjectName(QStringLiteral("nb6"));

        horizontalLayout_5->addWidget(nb6);

        nb7 = new QPushButton(options);
        nb7->setObjectName(QStringLiteral("nb7"));

        horizontalLayout_5->addWidget(nb7);

        nb8 = new QPushButton(options);
        nb8->setObjectName(QStringLiteral("nb8"));

        horizontalLayout_5->addWidget(nb8);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, -1, 0, -1);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        gridPseudo = new QGridLayout();
        gridPseudo->setSpacing(6);
        gridPseudo->setObjectName(QStringLiteral("gridPseudo"));

        horizontalLayout_7->addLayout(gridPseudo);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        go = new QPushButton(options);
        go->setObjectName(QStringLiteral("go"));
        go->setMinimumSize(QSize(20, 40));

        horizontalLayout_6->addWidget(go);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        menu->addWidget(options);
        board = new QWidget();
        board->setObjectName(QStringLiteral("board"));
        verticalLayout_5 = new QVBoxLayout(board);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_11);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        backOptions = new QPushButton(board);
        backOptions->setObjectName(QStringLiteral("backOptions"));
        backOptions->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	width: 200px;\n"
"	border: 1px solid snow;\n"
"	border-radius: 10px 10px 10px 10px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#ff6666 ;\n"
"}"));

        horizontalLayout_10->addWidget(backOptions);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);

        label = new QLabel(board);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	border: 1px solid snow;\n"
"	border-radius: 10px 10px 10px 10px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        label_2 = new QLabel(board);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	border: 1px solid snow;\n"
"	border-radius: 10px 10px 10px 10px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_2);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_17);

        label_3 = new QLabel(board);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setBaseSize(QSize(20, 30));
        label_3->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	border: 1px solid snow;\n"
"	border-radius: 10px 10px 10px 10px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_3);

        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);


        verticalLayout_4->addLayout(horizontalLayout_10);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_13);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_20);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_21);

        round = new QLineEdit(board);
        round->setObjectName(QStringLiteral("round"));
        round->setMinimumSize(QSize(0, 0));

        horizontalLayout_11->addWidget(round);

        nbDefusing = new QLineEdit(board);
        nbDefusing->setObjectName(QStringLiteral("nbDefusing"));

        horizontalLayout_11->addWidget(nbDefusing);

        tour = new QLineEdit(board);
        tour->setObjectName(QStringLiteral("tour"));

        horizontalLayout_11->addWidget(tour);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);


        verticalLayout_4->addLayout(horizontalLayout_11);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_19);

        role = new QPushButton(board);
        role->setObjectName(QStringLiteral("role"));
        role->setMinimumSize(QSize(200, 300));
        role->setStyleSheet(QStringLiteral(""));

        horizontalLayout_8->addWidget(role);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        card1 = new QPushButton(board);
        card1->setObjectName(QStringLiteral("card1"));
        card1->setMinimumSize(QSize(100, 200));

        horizontalLayout_8->addWidget(card1);

        card2 = new QPushButton(board);
        card2->setObjectName(QStringLiteral("card2"));
        card2->setMinimumSize(QSize(100, 200));

        horizontalLayout_8->addWidget(card2);

        card3 = new QPushButton(board);
        card3->setObjectName(QStringLiteral("card3"));
        card3->setMinimumSize(QSize(100, 200));

        horizontalLayout_8->addWidget(card3);

        card4 = new QPushButton(board);
        card4->setObjectName(QStringLiteral("card4"));
        card4->setMinimumSize(QSize(100, 200));

        horizontalLayout_8->addWidget(card4);

        card5 = new QPushButton(board);
        card5->setObjectName(QStringLiteral("card5"));
        card5->setMinimumSize(QSize(100, 200));

        horizontalLayout_8->addWidget(card5);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);


        verticalLayout_5->addLayout(horizontalLayout_8);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_13);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        player1 = new QPushButton(board);
        player1->setObjectName(QStringLiteral("player1"));
        sizePolicy.setHeightForWidth(player1->sizePolicy().hasHeightForWidth());
        player1->setSizePolicy(sizePolicy);
        player1->setMinimumSize(QSize(100, 170));
        player1->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(player1);

        player2 = new QPushButton(board);
        player2->setObjectName(QStringLiteral("player2"));
        sizePolicy.setHeightForWidth(player2->sizePolicy().hasHeightForWidth());
        player2->setSizePolicy(sizePolicy);
        player2->setMinimumSize(QSize(100, 170));
        player2->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(player2);

        player3 = new QPushButton(board);
        player3->setObjectName(QStringLiteral("player3"));
        sizePolicy.setHeightForWidth(player3->sizePolicy().hasHeightForWidth());
        player3->setSizePolicy(sizePolicy);
        player3->setMinimumSize(QSize(100, 170));
        player3->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(player3);

        player4 = new QPushButton(board);
        player4->setObjectName(QStringLiteral("player4"));
        sizePolicy.setHeightForWidth(player4->sizePolicy().hasHeightForWidth());
        player4->setSizePolicy(sizePolicy);
        player4->setMinimumSize(QSize(100, 170));
        player4->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(player4);

        player5 = new QPushButton(board);
        player5->setObjectName(QStringLiteral("player5"));
        sizePolicy.setHeightForWidth(player5->sizePolicy().hasHeightForWidth());
        player5->setSizePolicy(sizePolicy);
        player5->setMinimumSize(QSize(100, 170));
        player5->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(player5);

        player6 = new QPushButton(board);
        player6->setObjectName(QStringLiteral("player6"));
        sizePolicy.setHeightForWidth(player6->sizePolicy().hasHeightForWidth());
        player6->setSizePolicy(sizePolicy);
        player6->setMinimumSize(QSize(100, 170));
        player6->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(player6);

        player7 = new QPushButton(board);
        player7->setObjectName(QStringLiteral("player7"));
        sizePolicy.setHeightForWidth(player7->sizePolicy().hasHeightForWidth());
        player7->setSizePolicy(sizePolicy);
        player7->setMinimumSize(QSize(100, 170));
        player7->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(player7);

        player8 = new QPushButton(board);
        player8->setObjectName(QStringLiteral("player8"));
        sizePolicy.setHeightForWidth(player8->sizePolicy().hasHeightForWidth());
        player8->setSizePolicy(sizePolicy);
        player8->setMinimumSize(QSize(100, 170));
        player8->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(player8);


        verticalLayout_5->addLayout(horizontalLayout);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_12);

        menu->addWidget(board);
        aide = new QWidget();
        aide->setObjectName(QStringLiteral("aide"));
        menu->addWidget(aide);

        verticalLayout_2->addWidget(menu);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        menu->setCurrentIndex(0);


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
        go->setText(QApplication::translate("MainWindow", "COMMENCER !", Q_NULLPTR));
        backOptions->setText(QApplication::translate("MainWindow", "back", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Round", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Defusings", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Tour", Q_NULLPTR));
        role->setText(QString());
        card1->setText(QString());
        card2->setText(QString());
        card3->setText(QString());
        card4->setText(QString());
        card5->setText(QString());
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
