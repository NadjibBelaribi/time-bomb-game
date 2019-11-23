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
    QPushButton *backToMenu;
    QSpinBox *spinBox;
    QPushButton *validPlayer;
    QWidget *gridLayoutWidget;
    QGridLayout *gridPseudo;
    QPushButton *letsPlay;

    void setupUi(QWidget *options)
    {
        if (options->objectName().isEmpty())
            options->setObjectName(QStringLiteral("options"));
        options->resize(640, 480);
        options->setStyleSheet(QStringLiteral("background-color:rgb(186, 189, 182)"));
        backToMenu = new QPushButton(options);
        backToMenu->setObjectName(QStringLiteral("backToMenu"));
        backToMenu->setGeometry(QRect(20, 20, 161, 61));
        backToMenu->setStyleSheet(QLatin1String("font-size:30px;\n"
"color:black;\n"
"background-color:rgb(92, 53, 102);\n"
"border-radius:10px;"));
        spinBox = new QSpinBox(options);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(270, 20, 91, 61));
        spinBox->setStyleSheet(QStringLiteral("font-size:40px;"));
        spinBox->setMinimum(4);
        spinBox->setMaximum(8);
        validPlayer = new QPushButton(options);
        validPlayer->setObjectName(QStringLiteral("validPlayer"));
        validPlayer->setGeometry(QRect(400, 20, 141, 61));
        validPlayer->setStyleSheet(QLatin1String("font-size:30px;\n"
"color:black;\n"
"background-color:rgb(115, 210, 22);\n"
"border-radius:10px;"));
        gridLayoutWidget = new QWidget(options);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(70, 110, 281, 271));
        gridPseudo = new QGridLayout(gridLayoutWidget);
        gridPseudo->setObjectName(QStringLiteral("gridPseudo"));
        gridPseudo->setContentsMargins(0, 0, 0, 0);
        letsPlay = new QPushButton(options);
        letsPlay->setObjectName(QStringLiteral("letsPlay"));
        letsPlay->setGeometry(QRect(430, 330, 151, 81));
        letsPlay->setStyleSheet(QLatin1String("font-size:30px;\n"
"color:black;\n"
"border-radius: 10px;\n"
"background-color:rgb(244, 160, 160)"));

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
