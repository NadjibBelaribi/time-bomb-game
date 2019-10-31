#include "table.h"
#include <QPushButton>
#include "ui_table.h"
#include "options.h"
#include "cards.h"

Table::Table(QWidget *parent,std::vector <QString> pseudos) :
    QWidget(parent),
    ui(new Ui::Table)
{
     ui->setupUi(this);
     size_t i ;

     for (i = 0; i < pseudos.size() ; i++)
     {
        QPushButton *but = new QPushButton();
         but->setFixedSize(100,140);
         but->setText(QString(pseudos.at(i)));
         QWidget::connect(but,SIGNAL(clicked()),this,SLOT(showPCards())) ;
         ui->positions->addWidget(but, 0, i);

     }

}

void Table::showPCards() {
     Cards *c = new Cards() ;
     c->show();
}

Table::~Table()
{
    delete ui;
}




void Table::on_backOptions_clicked()
{
    options *o = new options;
    o->show();
    this->window()->close();
}
