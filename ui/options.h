#ifndef OPTIONS_H
#define OPTIONS_H

#include "mainwindow.h"

namespace Ui {
class options;
}

class options : public QWidget
{
    Q_OBJECT

public:
    explicit options(QWidget *parent = nullptr);
    ~options();

private slots:
    void on_backToMenu_clicked();

    void on_validPlayer_clicked();

    void on_letsPlay_clicked();

    vector <QString> getPseudo();

private:
    Ui::options *ui;
    vector <QLineEdit*> hello;
    vector <QString> pseudos;
};

#endif // OPTIONS_H
