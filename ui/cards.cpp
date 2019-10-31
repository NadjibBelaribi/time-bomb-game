#include "cards.h"
#include "ui_cards.h"

Cards::Cards(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cards)
{
    ui->setupUi(this);
}

Cards::~Cards()
{
    delete ui;
}

void Cards::on_close_clicked()
{
    this->window()->close() ;
}
