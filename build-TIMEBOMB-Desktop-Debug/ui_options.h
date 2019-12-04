/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_options
{
public:
    QGridLayout *gridLayout;
    QPushButton *backToMenu;
    QSpinBox *spinBox;
    QPushButton *validPlayer;
    QGridLayout *gridPseudo;
    QPushButton *letsPlay;

    void setupUi(QWidget *options)
    {
        if (options->objectName().isEmpty())
            options->setObjectName(QStringLiteral("options"));
        options->resize(640, 480);
        options->setStyleSheet(QLatin1String("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-image:none;\n"
"}\n"
""));
        gridLayout = new QGridLayout(options);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        backToMenu = new QPushButton(options);
        backToMenu->setObjectName(QStringLiteral("backToMenu"));
        backToMenu->setStyleSheet(QLatin1String("font-size:30px;\n"
"color:black;\n"
"background-color:rgb(92, 53, 102);\n"
"border-radius:10px;"));

        gridLayout->addWidget(backToMenu, 0, 0, 1, 1);

        spinBox = new QSpinBox(options);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setStyleSheet(QStringLiteral("font-size:40px;"));
        spinBox->setMinimum(4);
        spinBox->setMaximum(8);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        validPlayer = new QPushButton(options);
        validPlayer->setObjectName(QStringLiteral("validPlayer"));
        validPlayer->setStyleSheet(QLatin1String("font-size:30px;\n"
"color:black;\n"
"background-color:rgb(115, 210, 22);\n"
"border-radius:10px;"));

        gridLayout->addWidget(validPlayer, 0, 2, 1, 1);

        gridPseudo = new QGridLayout();
        gridPseudo->setObjectName(QStringLiteral("gridPseudo"));

        gridLayout->addLayout(gridPseudo, 1, 0, 1, 2);

        letsPlay = new QPushButton(options);
        letsPlay->setObjectName(QStringLiteral("letsPlay"));
        letsPlay->setStyleSheet(QLatin1String("font-size:30px;\n"
"color:black;\n"
"border-radius: 10px;\n"
"background-color:rgb(244, 160, 160)"));

        gridLayout->addWidget(letsPlay, 1, 2, 1, 1);


        retranslateUi(options);

        QMetaObject::connectSlotsByName(options);
    } // setupUi

    void retranslateUi(QWidget *options)
    {
        options->setWindowTitle(QApplication::translate("options", "Form", Q_NULLPTR));
        backToMenu->setText(QApplication::translate("options", "Back", Q_NULLPTR));
        validPlayer->setText(QApplication::translate("options", "Valider", Q_NULLPTR));
        letsPlay->setText(QApplication::translate("options", "Let's Play!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class options: public Ui_options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
