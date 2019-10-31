#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include"mainwindow.h"

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0,std::vector <QString> pseudos = std::vector <QString> () );
    explicit Table(QWidget *parent = 0);

    ~Table();
public slots :
    void showPCards() ;

private slots:
    void on_backOptions_clicked();


private:
    Ui::Table *ui;
};

#endif // TABLE_H
