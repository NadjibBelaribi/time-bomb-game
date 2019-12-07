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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
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
    QPushButton *leave_menu;
    QSpacerItem *verticalSpacer_2;
    QWidget *options;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_8;
    QPushButton *back;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
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
    QSpacerItem *horizontalSpacer_11;
    QLabel *label;
    QLCDNumber *round;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_2;
    QLCDNumber *defusing;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *game_cards;
    QSpacerItem *horizontalSpacer_19;
    QVBoxLayout *verticalLayout_7;
    QPushButton *role;
    QLabel *name;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout;
    QPushButton *card3;
    QPushButton *card1;
    QPushButton *card4;
    QPushButton *card2;
    QPushButton *card5;
    QLabel *status;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *game_players;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *player1;
    QPushButton *player2;
    QPushButton *player3;
    QPushButton *player4;
    QPushButton *player5;
    QPushButton *player6;
    QPushButton *player7;
    QPushButton *player8;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *verticalSpacer_12;
    QWidget *fin;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_25;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_17;
    QLabel *fin_img;
    QLabel *winner;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *replay;
    QPushButton *leave;
    QSpacerItem *horizontalSpacer_26;
    QWidget *aide;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_28;
    QVBoxLayout *verticalLayout_11;
    QPushButton *backfromhelp;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_29;
    QPushButton *Previous;
    QSpacerItem *verticalSpacer_21;
    QVBoxLayout *verticalLayout_10;
    QLabel *labelPic;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer_19;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *next;
    QSpacerItem *horizontalSpacer_30;
    QSpacerItem *verticalSpacer_20;
    QSpacerItem *horizontalSpacer_31;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1047, 614);
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setMaximumSize(QSize(1200, 700));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"background-image: url(:london.jpg);\n"
"background-image:no-repeat;\n"
"border-image:url(:london.jpg) 0 0 0 0 stretch ;\n"
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
        menu->setStyleSheet(QString::fromUtf8(""));
        start = new QWidget();
        start->setObjectName(QString::fromUtf8("start"));
        start->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        playB = new QPushButton(start);
        playB->setObjectName(QString::fromUtf8("playB"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(playB->sizePolicy().hasHeightForWidth());
        playB->setSizePolicy(sizePolicy);
        playB->setMinimumSize(QSize(60, 45));
        playB->setStyleSheet(QString::fromUtf8(" font: 75 33pt \"Purisa\";"));

        verticalLayout->addWidget(playB);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_3);

        help = new QPushButton(start);
        help->setObjectName(QString::fromUtf8("help"));
        help->setMinimumSize(QSize(60, 45));
        help->setStyleSheet(QString::fromUtf8(" font: 75 33pt \"Purisa\";"));

        verticalLayout->addWidget(help);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_4);

        leave_menu = new QPushButton(start);
        leave_menu->setObjectName(QString::fromUtf8("leave_menu"));
        leave_menu->setMinimumSize(QSize(60, 45));
        leave_menu->setStyleSheet(QString::fromUtf8(" font: 75 33pt \"Purisa\";"));

        verticalLayout->addWidget(leave_menu);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        menu->addWidget(start);
        options = new QWidget();
        options->setObjectName(QString::fromUtf8("options"));
        options->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	min-width: 100px;\n"
"	height: 30px;\n"
"	border: 1px solid snow;\n"
"	border-radius: 10px 10px 10px 10px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:DarkSlateBlue ;\n"
"}\n"
"\n"
"QLineEdit {\n"
"height: 30px;\n"
"padding: 6px 10px;\n"
"background-color: rgba(80,80,80,0.9);\n"
"border-radius: 6px;\n"
"color: snow;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(options);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_8);

        back = new QPushButton(options);
        back->setObjectName(QString::fromUtf8("back"));
        back->setMinimumSize(QSize(160, 40));
        back->setMaximumSize(QSize(160, 40));
        back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"margin-right: 2em;\n"
"background-color: snow;\n"
"color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: #DDDDDD;\n"
"}"));

        verticalLayout_3->addWidget(back);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));

        verticalLayout_3->addLayout(verticalLayout_15);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        label_3 = new QLabel(options);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(200, 40));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(20,20,20,0.8); color: snow; border-radius: 8px; margin-right: 1em;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setMargin(0);

        horizontalLayout_5->addWidget(label_3);

        nb4 = new QPushButton(options);
        nb4->setObjectName(QString::fromUtf8("nb4"));
        nb4->setMinimumSize(QSize(102, 25));

        horizontalLayout_5->addWidget(nb4);

        nb5 = new QPushButton(options);
        nb5->setObjectName(QString::fromUtf8("nb5"));

        horizontalLayout_5->addWidget(nb5);

        nb6 = new QPushButton(options);
        nb6->setObjectName(QString::fromUtf8("nb6"));

        horizontalLayout_5->addWidget(nb6);

        nb7 = new QPushButton(options);
        nb7->setObjectName(QString::fromUtf8("nb7"));

        horizontalLayout_5->addWidget(nb7);

        nb8 = new QPushButton(options);
        nb8->setObjectName(QString::fromUtf8("nb8"));

        horizontalLayout_5->addWidget(nb8);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, -1, 0, -1);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        gridPseudo = new QGridLayout();
        gridPseudo->setSpacing(6);
        gridPseudo->setObjectName(QString::fromUtf8("gridPseudo"));

        horizontalLayout_7->addLayout(gridPseudo);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        go = new QPushButton(options);
        go->setObjectName(QString::fromUtf8("go"));
        go->setMinimumSize(QSize(202, 40));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        go->setFont(font1);
        go->setStyleSheet(QString::fromUtf8("min-width: 200px;"));

        horizontalLayout_6->addWidget(go);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        menu->addWidget(options);
        board = new QWidget();
        board->setObjectName(QString::fromUtf8("board"));
        verticalLayout_5 = new QVBoxLayout(board);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_11);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);

        label = new QLabel(board);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid snow;\n"
"	border-radius: 6px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label);

        round = new QLCDNumber(board);
        round->setObjectName(QString::fromUtf8("round"));
        round->setMinimumSize(QSize(40, 40));
        round->setAutoFillBackground(false);
        round->setStyleSheet(QString::fromUtf8("background-color: rgba(200,200,200,0.6);"));
        round->setFrameShape(QFrame::Box);
        round->setFrameShadow(QFrame::Raised);
        round->setLineWidth(0);
        round->setDigitCount(1);
        round->setMode(QLCDNumber::Dec);
        round->setSegmentStyle(QLCDNumber::Flat);
        round->setProperty("intValue", QVariant(1));

        horizontalLayout_10->addWidget(round);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        label_2 = new QLabel(board);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(120, 0));
        label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid snow;\n"
"	border-radius: 6px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_2);

        defusing = new QLCDNumber(board);
        defusing->setObjectName(QString::fromUtf8("defusing"));
        defusing->setMinimumSize(QSize(40, 40));
        defusing->setStyleSheet(QString::fromUtf8("background-color: rgba(200,200,200,0.6);"));
        defusing->setLineWidth(0);
        defusing->setSmallDecimalPoint(false);
        defusing->setDigitCount(1);
        defusing->setMode(QLCDNumber::Dec);
        defusing->setSegmentStyle(QLCDNumber::Flat);
        defusing->setProperty("intValue", QVariant(0));

        horizontalLayout_10->addWidget(defusing);

        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);


        verticalLayout_4->addLayout(horizontalLayout_10);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_13);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_20);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_21);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);


        verticalLayout_4->addLayout(horizontalLayout_11);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_10);

        game_cards = new QHBoxLayout();
        game_cards->setSpacing(6);
        game_cards->setObjectName(QString::fromUtf8("game_cards"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        game_cards->addItem(horizontalSpacer_19);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        role = new QPushButton(board);
        role->setObjectName(QString::fromUtf8("role"));
        role->setMinimumSize(QSize(150, 225));
        role->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(role);

        name = new QLabel(board);
        name->setObjectName(QString::fromUtf8("name"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        name->setFont(font2);
        name->setStyleSheet(QString::fromUtf8("background-color: rgba(20,20,20,0.6); color: snow; border-radius: 4px;"));
        name->setScaledContents(false);
        name->setAlignment(Qt::AlignCenter);
        name->setMargin(6);

        verticalLayout_7->addWidget(name);


        game_cards->addLayout(verticalLayout_7);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        game_cards->addItem(horizontalSpacer_10);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        card3 = new QPushButton(board);
        card3->setObjectName(QString::fromUtf8("card3"));
        card3->setMinimumSize(QSize(100, 200));
        card3->setMaximumSize(QSize(100, 200));

        horizontalLayout->addWidget(card3);

        card1 = new QPushButton(board);
        card1->setObjectName(QString::fromUtf8("card1"));
        card1->setMinimumSize(QSize(100, 200));
        card1->setMaximumSize(QSize(100, 200));

        horizontalLayout->addWidget(card1);

        card4 = new QPushButton(board);
        card4->setObjectName(QString::fromUtf8("card4"));
        card4->setMinimumSize(QSize(100, 200));
        card4->setMaximumSize(QSize(100, 200));

        horizontalLayout->addWidget(card4);

        card2 = new QPushButton(board);
        card2->setObjectName(QString::fromUtf8("card2"));
        card2->setMinimumSize(QSize(100, 200));
        card2->setMaximumSize(QSize(100, 200));

        horizontalLayout->addWidget(card2);

        card5 = new QPushButton(board);
        card5->setObjectName(QString::fromUtf8("card5"));
        card5->setMinimumSize(QSize(100, 200));
        card5->setMaximumSize(QSize(100, 200));

        horizontalLayout->addWidget(card5);


        verticalLayout_13->addLayout(horizontalLayout);

        status = new QLabel(board);
        status->setObjectName(QString::fromUtf8("status"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Noto Sans Lao"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        font3.setKerning(true);
        status->setFont(font3);
        status->setStyleSheet(QString::fromUtf8("background-color: rgba(20,20,20,0.6); color:orange;"));
        status->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(status);


        game_cards->addLayout(verticalLayout_13);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        game_cards->addItem(horizontalSpacer_18);


        verticalLayout_5->addLayout(game_cards);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_13);

        game_players = new QHBoxLayout();
        game_players->setSpacing(6);
        game_players->setObjectName(QString::fromUtf8("game_players"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));

        game_players->addLayout(horizontalLayout_13);

        player1 = new QPushButton(board);
        player1->setObjectName(QString::fromUtf8("player1"));
        sizePolicy.setHeightForWidth(player1->sizePolicy().hasHeightForWidth());
        player1->setSizePolicy(sizePolicy);
        player1->setMinimumSize(QSize(100, 170));
        player1->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 75 italic 15pt \"Utopia\";\n"
"padding-top :120px ;\n"
" text-transform: uppercase;\n"
"background-image: url(:tb9.png); border-image: url(:tb9.png) 0 0 0 0 stretch; background-image:no-repeat;"));

        game_players->addWidget(player1);

        player2 = new QPushButton(board);
        player2->setObjectName(QString::fromUtf8("player2"));
        sizePolicy.setHeightForWidth(player2->sizePolicy().hasHeightForWidth());
        player2->setSizePolicy(sizePolicy);
        player2->setMinimumSize(QSize(100, 170));
        player2->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 75 italic 15pt \"Utopia\";\n"
"padding-top :120px ;\n"
" text-transform: uppercase;\n"
"background-image: url(:tb9.png); border-image: url(:tb9.png) 0 0 0 0 stretch; background-image:no-repeat;"));

        game_players->addWidget(player2);

        player3 = new QPushButton(board);
        player3->setObjectName(QString::fromUtf8("player3"));
        sizePolicy.setHeightForWidth(player3->sizePolicy().hasHeightForWidth());
        player3->setSizePolicy(sizePolicy);
        player3->setMinimumSize(QSize(100, 170));
        player3->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 75 italic 15pt \"Utopia\";\n"
"padding-top :120px ;\n"
" text-transform: uppercase;\n"
"background-image: url(:tb9.png); border-image: url(:tb9.png) 0 0 0 0 stretch; background-image:no-repeat;"));

        game_players->addWidget(player3);

        player4 = new QPushButton(board);
        player4->setObjectName(QString::fromUtf8("player4"));
        sizePolicy.setHeightForWidth(player4->sizePolicy().hasHeightForWidth());
        player4->setSizePolicy(sizePolicy);
        player4->setMinimumSize(QSize(100, 170));
        player4->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 75 italic 15pt \"Utopia\";\n"
"padding-top :120px ;\n"
" text-transform: uppercase;\n"
"background-image: url(:tb9.png); border-image: url(:tb9.png) 0 0 0 0 stretch; background-image:no-repeat;"));

        game_players->addWidget(player4);

        player5 = new QPushButton(board);
        player5->setObjectName(QString::fromUtf8("player5"));
        sizePolicy.setHeightForWidth(player5->sizePolicy().hasHeightForWidth());
        player5->setSizePolicy(sizePolicy);
        player5->setMinimumSize(QSize(100, 170));
        player5->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 75 italic 15pt \"Utopia\";\n"
"padding-top :120px ;\n"
" text-transform: uppercase;\n"
"background-image: url(:tb9.png); border-image: url(:tb9.png) 0 0 0 0 stretch; background-image:no-repeat;"));

        game_players->addWidget(player5);

        player6 = new QPushButton(board);
        player6->setObjectName(QString::fromUtf8("player6"));
        sizePolicy.setHeightForWidth(player6->sizePolicy().hasHeightForWidth());
        player6->setSizePolicy(sizePolicy);
        player6->setMinimumSize(QSize(100, 170));
        player6->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 75 italic 15pt \"Utopia\";\n"
"padding-top :120px ;\n"
" text-transform: uppercase;\n"
"background-image: url(:tb9.png); border-image: url(:tb9.png) 0 0 0 0 stretch; background-image:no-repeat;"));

        game_players->addWidget(player6);

        player7 = new QPushButton(board);
        player7->setObjectName(QString::fromUtf8("player7"));
        sizePolicy.setHeightForWidth(player7->sizePolicy().hasHeightForWidth());
        player7->setSizePolicy(sizePolicy);
        player7->setMinimumSize(QSize(100, 170));
        player7->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 75 italic 15pt \"Utopia\";\n"
"padding-top :120px ;\n"
" text-transform: uppercase;\n"
"background-image: url(:tb9.png); border-image: url(:tb9.png) 0 0 0 0 stretch; background-image:no-repeat;"));

        game_players->addWidget(player7);

        player8 = new QPushButton(board);
        player8->setObjectName(QString::fromUtf8("player8"));
        sizePolicy.setHeightForWidth(player8->sizePolicy().hasHeightForWidth());
        player8->setSizePolicy(sizePolicy);
        player8->setMinimumSize(QSize(100, 170));
        player8->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 75 italic 15pt \"Utopia\";\n"
"padding-top :120px ;\n"
" text-transform: uppercase;\n"
"background-image: url(:tb9.png); border-image: url(:tb9.png) 0 0 0 0 stretch; background-image:no-repeat;"));

        game_players->addWidget(player8);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setSizeConstraint(QLayout::SetDefaultConstraint);

        game_players->addLayout(horizontalLayout_14);


        verticalLayout_5->addLayout(game_players);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_12);

        menu->addWidget(board);
        fin = new QWidget();
        fin->setObjectName(QString::fromUtf8("fin"));
        fin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 6px;\n"
"background-color: rgba(240,240,240,0.8);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgba(240,240,240,1);\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(fin);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_25 = new QSpacerItem(300, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_25);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_17 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_9->addItem(verticalSpacer_17);

        fin_img = new QLabel(fin);
        fin_img->setObjectName(QString::fromUtf8("fin_img"));
        fin_img->setStyleSheet(QString::fromUtf8("background-color: rgba(20,20,20,0.8);"));
        fin_img->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(fin_img);

        winner = new QLabel(fin);
        winner->setObjectName(QString::fromUtf8("winner"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(winner->sizePolicy().hasHeightForWidth());
        winner->setSizePolicy(sizePolicy2);
        winner->setMinimumSize(QSize(0, 50));
        winner->setMaximumSize(QSize(16777215, 50));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        winner->setFont(font4);
        winner->setStyleSheet(QString::fromUtf8("color: snow;"));
        winner->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(winner);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        replay = new QPushButton(fin);
        replay->setObjectName(QString::fromUtf8("replay"));
        replay->setMinimumSize(QSize(80, 30));
        replay->setFont(font1);

        horizontalLayout_15->addWidget(replay);

        leave = new QPushButton(fin);
        leave->setObjectName(QString::fromUtf8("leave"));
        leave->setMinimumSize(QSize(80, 30));
        leave->setFont(font1);

        horizontalLayout_15->addWidget(leave);


        verticalLayout_9->addLayout(horizontalLayout_15);


        verticalLayout_8->addLayout(verticalLayout_9);


        verticalLayout_6->addLayout(verticalLayout_8);


        horizontalLayout_3->addLayout(verticalLayout_6);

        horizontalSpacer_26 = new QSpacerItem(300, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_26);

        menu->addWidget(fin);
        aide = new QWidget();
        aide->setObjectName(QString::fromUtf8("aide"));
        horizontalLayout_4 = new QHBoxLayout(aide);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_28);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        backfromhelp = new QPushButton(aide);
        backfromhelp->setObjectName(QString::fromUtf8("backfromhelp"));
        backfromhelp->setMinimumSize(QSize(100, 40));
        backfromhelp->setMaximumSize(QSize(80, 40));
        backfromhelp->setFont(font);
        backfromhelp->setStyleSheet(QString::fromUtf8("QPushButton  {\n"
"border-radius: 6px;\n"
"background-color: rgba(240,240,240,0.8);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgba(240,240,240,1);\n"
"\n"
"}"));

        verticalLayout_11->addWidget(backfromhelp);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_29 = new QSpacerItem(0, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_29);

        Previous = new QPushButton(aide);
        Previous->setObjectName(QString::fromUtf8("Previous"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Previous->sizePolicy().hasHeightForWidth());
        Previous->setSizePolicy(sizePolicy3);
        Previous->setMinimumSize(QSize(80, 0));
        Previous->setMaximumSize(QSize(80, 16777215));
        Previous->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius:3px;\n"
"background-color: rgba(20,20,20,0.8);\n"
"background-image: url(:previous.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgba(20,20,20,1);\n"
"}"));

        horizontalLayout_9->addWidget(Previous);


        verticalLayout_11->addLayout(horizontalLayout_9);

        verticalSpacer_21 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_11->addItem(verticalSpacer_21);


        horizontalLayout_4->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        labelPic = new QLabel(aide);
        labelPic->setObjectName(QString::fromUtf8("labelPic"));
        sizePolicy1.setHeightForWidth(labelPic->sizePolicy().hasHeightForWidth());
        labelPic->setSizePolicy(sizePolicy1);

        verticalLayout_10->addWidget(labelPic);


        horizontalLayout_4->addLayout(verticalLayout_10);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalSpacer_19 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_12->addItem(verticalSpacer_19);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        next = new QPushButton(aide);
        next->setObjectName(QString::fromUtf8("next"));
        sizePolicy3.setHeightForWidth(next->sizePolicy().hasHeightForWidth());
        next->setSizePolicy(sizePolicy3);
        next->setMinimumSize(QSize(80, 0));
        next->setMaximumSize(QSize(80, 16777215));
        next->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius:3px;\n"
"background-color: rgba(20,20,20,0.8);\n"
"background-image: url(:next.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgba(20,20,20,1);\n"
"}"));

        horizontalLayout_12->addWidget(next);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_30);


        verticalLayout_12->addLayout(horizontalLayout_12);

        verticalSpacer_20 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_12->addItem(verticalSpacer_20);


        horizontalLayout_4->addLayout(verticalLayout_12);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_31);

        menu->addWidget(aide);

        verticalLayout_2->addWidget(menu);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        menu->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        playB->setText(QCoreApplication::translate("MainWindow", "Jouer", nullptr));
        help->setText(QCoreApplication::translate("MainWindow", "Aide", nullptr));
        leave_menu->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        back->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nombre de joueurs", nullptr));
        nb4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        nb5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        nb6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        nb7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        nb8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        go->setText(QCoreApplication::translate("MainWindow", "COMMENCER !", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Round", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Defusings", nullptr));
        role->setText(QString());
        name->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        card3->setText(QString());
        card1->setText(QString());
        card4->setText(QString());
        card2->setText(QString());
        card5->setText(QString());
        status->setText(QString());
        player1->setText(QString());
        player2->setText(QString());
        player3->setText(QString());
        player4->setText(QString());
        player5->setText(QString());
        player6->setText(QString());
        player7->setText(QString());
        player8->setText(QString());
        fin_img->setText(QString());
        winner->setText(QString());
        replay->setText(QCoreApplication::translate("MainWindow", "Rejouer", nullptr));
        leave->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        backfromhelp->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        Previous->setText(QString());
        labelPic->setText(QString());
        next->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
