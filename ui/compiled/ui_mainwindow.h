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
    QPushButton *leave_menu;
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
    QLineEdit *round;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_2;
    QLineEdit *nbDefusing;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label_3;
    QLineEdit *tour;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_21;
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
    QWidget *fin_sherlock;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_22;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_14;
    QPushButton *replay_sherlock;
    QSpacerItem *horizontalSpacer_23;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_15;
    QPushButton *leave_sherlock;
    QSpacerItem *horizontalSpacer_24;
    QWidget *fin_mory;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_25;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_16;
    QPushButton *replay_mory;
    QSpacerItem *horizontalSpacer_27;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_17;
    QPushButton *leave_mory;
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
        MainWindow->setMinimumSize(QSize(20, 30));
        MainWindow->setMaximumSize(QSize(1292, 614));
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
"	min-width: 120px;\n"
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

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        back = new QPushButton(options);
        back->setObjectName(QString::fromUtf8("back"));
        back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"margin-right: 2em;\n"
"background-color: snow;\n"
"color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: #EEEEEE;\n"
"}"));

        horizontalLayout_5->addWidget(back);

        nb4 = new QPushButton(options);
        nb4->setObjectName(QString::fromUtf8("nb4"));
        nb4->setMinimumSize(QSize(122, 25));

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
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        go->setFont(font);
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

        backOptions = new QPushButton(board);
        backOptions->setObjectName(QString::fromUtf8("backOptions"));
        backOptions->setMaximumSize(QSize(180, 16777215));
        backOptions->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid snow;\n"
"	border-radius: 10px 10px 10px 10px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label);

        round = new QLineEdit(board);
        round->setObjectName(QString::fromUtf8("round"));
        round->setMinimumSize(QSize(0, 0));
        round->setMaximumSize(QSize(40, 16777215));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        round->setFont(font1);
        round->setStyleSheet(QString::fromUtf8("background: rgba(20,20,20, 0.5);\n"
"color: snow;"));
        round->setAlignment(Qt::AlignCenter);
        round->setReadOnly(true);

        horizontalLayout_10->addWidget(round);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        label_2 = new QLabel(board);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(120, 0));
        label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid snow;\n"
"	border-radius: 10px 10px 10px 10px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_2);

        nbDefusing = new QLineEdit(board);
        nbDefusing->setObjectName(QString::fromUtf8("nbDefusing"));
        nbDefusing->setMaximumSize(QSize(40, 16777215));
        nbDefusing->setFont(font1);
        nbDefusing->setStyleSheet(QString::fromUtf8("background: rgba(20,20,20, 0.5);\n"
"color: snow;"));
        nbDefusing->setAlignment(Qt::AlignCenter);
        nbDefusing->setReadOnly(true);

        horizontalLayout_10->addWidget(nbDefusing);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_17);

        label_3 = new QLabel(board);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setBaseSize(QSize(20, 30));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 1px solid snow;\n"
"	border-radius: 10px 10px 10px 10px;\n"
"	background-color:DodgerBlue ;\n"
"	color:snow;\n"
"	font-size:20px;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_3);

        tour = new QLineEdit(board);
        tour->setObjectName(QString::fromUtf8("tour"));
        tour->setMaximumSize(QSize(120, 16777215));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        tour->setFont(font2);
        tour->setStyleSheet(QString::fromUtf8("background: rgba(20,20,20, 0.5);\n"
"color: snow;"));
        tour->setAlignment(Qt::AlignCenter);
        tour->setReadOnly(true);

        horizontalLayout_10->addWidget(tour);

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

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_19);

        role = new QPushButton(board);
        role->setObjectName(QString::fromUtf8("role"));
        role->setMinimumSize(QSize(200, 300));
        role->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_8->addWidget(role);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        card1 = new QPushButton(board);
        card1->setObjectName(QString::fromUtf8("card1"));
        card1->setMinimumSize(QSize(100, 200));

        horizontalLayout_8->addWidget(card1);

        card2 = new QPushButton(board);
        card2->setObjectName(QString::fromUtf8("card2"));
        card2->setMinimumSize(QSize(100, 200));

        horizontalLayout_8->addWidget(card2);

        card3 = new QPushButton(board);
        card3->setObjectName(QString::fromUtf8("card3"));
        card3->setMinimumSize(QSize(100, 200));

        horizontalLayout_8->addWidget(card3);

        card4 = new QPushButton(board);
        card4->setObjectName(QString::fromUtf8("card4"));
        card4->setMinimumSize(QSize(100, 200));

        horizontalLayout_8->addWidget(card4);

        card5 = new QPushButton(board);
        card5->setObjectName(QString::fromUtf8("card5"));
        card5->setMinimumSize(QSize(100, 200));

        horizontalLayout_8->addWidget(card5);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);


        verticalLayout_5->addLayout(horizontalLayout_8);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_13);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));

        horizontalLayout->addLayout(horizontalLayout_13);

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

        horizontalLayout->addWidget(player1);

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

        horizontalLayout->addWidget(player2);

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

        horizontalLayout->addWidget(player3);

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

        horizontalLayout->addWidget(player4);

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

        horizontalLayout->addWidget(player5);

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

        horizontalLayout->addWidget(player6);

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

        horizontalLayout->addWidget(player7);

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

        horizontalLayout->addWidget(player8);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout->addLayout(horizontalLayout_14);


        verticalLayout_5->addLayout(horizontalLayout);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_12);

        menu->addWidget(board);
        fin_sherlock = new QWidget();
        fin_sherlock->setObjectName(QString::fromUtf8("fin_sherlock"));
        fin_sherlock->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 6px;\n"
"background-color: rgba(240,240,240,0.8);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgba(240,240,240,1);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(fin_sherlock);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_22 = new QSpacerItem(300, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_22);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_14);

        replay_sherlock = new QPushButton(fin_sherlock);
        replay_sherlock->setObjectName(QString::fromUtf8("replay_sherlock"));

        verticalLayout_6->addWidget(replay_sherlock);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_23);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_15);

        leave_sherlock = new QPushButton(fin_sherlock);
        leave_sherlock->setObjectName(QString::fromUtf8("leave_sherlock"));

        verticalLayout_7->addWidget(leave_sherlock);


        horizontalLayout_2->addLayout(verticalLayout_7);

        horizontalSpacer_24 = new QSpacerItem(300, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_24);

        menu->addWidget(fin_sherlock);
        fin_mory = new QWidget();
        fin_mory->setObjectName(QString::fromUtf8("fin_mory"));
        fin_mory->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 6px;\n"
"background-color: rgba(240,240,240,0.8);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgba(240,240,240,1);\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(fin_mory);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_25 = new QSpacerItem(300, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_25);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_8->addItem(verticalSpacer_16);

        replay_mory = new QPushButton(fin_mory);
        replay_mory->setObjectName(QString::fromUtf8("replay_mory"));
        replay_mory->setMinimumSize(QSize(80, 30));
        replay_mory->setFont(font);

        verticalLayout_8->addWidget(replay_mory);


        horizontalLayout_3->addLayout(verticalLayout_8);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_27);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_17 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_9->addItem(verticalSpacer_17);

        leave_mory = new QPushButton(fin_mory);
        leave_mory->setObjectName(QString::fromUtf8("leave_mory"));
        leave_mory->setMinimumSize(QSize(80, 30));
        leave_mory->setFont(font);

        verticalLayout_9->addWidget(leave_mory);


        horizontalLayout_3->addLayout(verticalLayout_9);

        horizontalSpacer_26 = new QSpacerItem(300, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_26);

        menu->addWidget(fin_mory);
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
        backfromhelp->setFont(font1);
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
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Previous->sizePolicy().hasHeightForWidth());
        Previous->setSizePolicy(sizePolicy1);
        Previous->setMinimumSize(QSize(80, 0));
        Previous->setMaximumSize(QSize(80, 16777215));
        Previous->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius:3px; \n"
"background-color: rgba(20,20,20,0.8); \n"
"background-image: url(:previous.png); \n"
"background-repeat: no-repeat; \n"
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
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelPic->sizePolicy().hasHeightForWidth());
        labelPic->setSizePolicy(sizePolicy2);

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
        sizePolicy1.setHeightForWidth(next->sizePolicy().hasHeightForWidth());
        next->setSizePolicy(sizePolicy1);
        next->setMinimumSize(QSize(80, 0));
        next->setMaximumSize(QSize(80, 16777215));
        next->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius:3px; \n"
"background-color: rgba(20,20,20,0.8); \n"
"background-image: url(:next.png); \n"
"background-repeat: no-repeat; \n"
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
        nb4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        nb5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        nb6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        nb7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        nb8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        go->setText(QCoreApplication::translate("MainWindow", "COMMENCER !", nullptr));
        backOptions->setText(QCoreApplication::translate("MainWindow", "PROCHAIN", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Round", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Defusings", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Tour", nullptr));
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
        replay_sherlock->setText(QCoreApplication::translate("MainWindow", "Rejouer", nullptr));
        leave_sherlock->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        replay_mory->setText(QCoreApplication::translate("MainWindow", "Rejouer", nullptr));
        leave_mory->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
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
