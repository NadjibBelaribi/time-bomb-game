#include "table.h"
#include <QPushButton>
#include "ui_table.h"
#include "options.h"


Table::Table(QWidget *parent,std::vector <QString> pseudos) :
    QWidget(parent),
    ui(new Ui::Table)
{
     ui->setupUi(this);
    startGame(pseudos);

}

void Table::startGame( std::vector <QString> psds ) {

    const size_t nbPlayers= psds.size() ;
     string * pseudos = new string[nbPlayers];
    size_t i ;

    for (i = 0; i < nbPlayers ; i++)
    {
        pseudos[i] = psds.at(i).toStdString();

    }

    Game game = Game(nbPlayers,pseudos) ;
     for (i = 0; i < nbPlayers; i++)
    {
       QPushButton *but = new QPushButton();
        but->setFixedSize(100,140);
        but->setText(QString::fromStdString(pseudos[i]));
        this->p = game.getPlayer(i);
        this->r = game.getRound();
        QObject::connect(but,SIGNAL(clicked()),this,SLOT(showPCards())) ;
        ui->players_positions->addWidget(but, 0, i);

    }
    Game::stateGame state;
   //do {
           printBeginMess(game, nbPlayers);

           //printCardRevealed(game.next(askForCard(game)));
      //  } while ((state = game.getState()) == Game::Active);

}

void Table::printBeginMess (const Game &game, const size_t nbPlayers) {
   ui->round->setText(QString::number(game.getRound()));
    ui->nbDefusing->setText(QString::number(game.getNbDefusingCardsRevealed()));
    ui->tour->setText(QString::fromStdString(game.getCurrentPlayer().getPseudo()));
}

void Table::showPCards() {
    size_t round = this->r;
    ui->players_positions_2->hide();
    char * ms;
    switch(p->getRole()){
             case Player::Sherlock :
                ms = "Sherlock";
                break;
            case  Player::Moriarty :
                ms = "Moriarty";
                break;
    }
     if (round == 1)
    {
        QPushButton *but = new QPushButton();
         but->setFixedSize(100,140);
         but->setText(QString(ms));
        ui->role_card->addWidget(but,0,0);
    }

    size_t i ;
    char * mm;
    for (i = 0; i < p->getCards().size(); i++)
    {
       QPushButton *but = new QPushButton();
        but->setFixedSize(100,140);
        Card* c = p->getCard(i);
        switch(c->getType()){
                 case Card::Safe:
                    mm = "Safe";
                    break;
                case Card::Defusing:
                    mm = "Defusing";
                    break;
                case Card::Bomb:
                    mm = "Bomb";
                    break;
            }
         but->setText(QString(mm)) ;
        ui->cards_positions->addWidget(but, 0, i);

    }
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



