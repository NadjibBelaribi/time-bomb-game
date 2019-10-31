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

    std::vector <QString> getPseudo();

private:
    Ui::options *ui;
    std::vector <QLineEdit*> hello;
    std::vector <QString> pseudos;
};

#endif // OPTIONS_H
