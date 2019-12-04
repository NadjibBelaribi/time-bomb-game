#include "options.h"
#include "ui_options.h"
#include <QLineEdit>
#include "board.h"
#include <QDebug>

options::options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::options)
{
    ui->setupUi(this);
}

options::~options()
{
    delete ui;
}

void options::on_backToMenu_clicked()
{
   MainWindow *m = new MainWindow;
   m->showNormal();
   this->window()->close();
}

void options::on_validPlayer_clicked()
{
    size_t nb_players = static_cast<size_t>(ui->spinBox->value());
    size_t i;
    for (i = 0; i < nb_players; i++)
    {
       QLineEdit *le = new QLineEdit();
       le->setPlaceholderText(QString("Player %1").arg(i));
       ui->gridPseudo->addWidget(le, i, 0);
       hello.push_back(le);
    }
}

void options::on_letsPlay_clicked()
{
    size_t nb_players = hello.size();
    size_t i;
    for (i = 0; i < nb_players; i++)
    {
      QString tmp = hello.at(i)->text();
      pseudos.push_back(tmp);
     }
     Board *b = new Board(NULL,pseudos);
      b->showNormal();
      this->window()->close();
}

std::vector <QString>options::getPseudo()
{
    return this->pseudos;
}
