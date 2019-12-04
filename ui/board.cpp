#include "board.h"
#include "options.h"
#include<QMessageBox>
#include "ui_board.h"

Board::Board(QWidget *parent,std::vector <QString> pseudos) :
             QWidget(parent),
             ui(new Ui::Board)
         {
              ui->setupUi(this);
             setTable(pseudos);
             this->cpt = 0;
         }


void Board::setTable( std::vector <QString> psds ) {

    const size_t nbPlayers= psds.size() ;
     string * pseudos = new string[nbPlayers];
    size_t i,j ;

    for (i = 0; i < nbPlayers ; i++)
    {
        pseudos[i] = psds.at(i).toStdString();

    }

    hideCards();
    switch(nbPlayers) {

    case 4 :
        ui->player5->hide();
        ui->player6->hide();
        ui->player7->hide();
        ui->player8->hide();
        ui->player1->setText(QString::fromStdString(pseudos[0]));
        ui->player2->setText(QString::fromStdString(pseudos[1]));
        ui->player3->setText(QString::fromStdString(pseudos[2]));
        ui->player4->setText(QString::fromStdString(pseudos[3]));

        break ;

    case 5 :
        ui->player6->hide();
        ui->player7->hide();
        ui->player8->hide();
        ui->player1->setText(QString::fromStdString(pseudos[0]));
        ui->player2->setText(QString::fromStdString(pseudos[1]));
        ui->player3->setText(QString::fromStdString(pseudos[2]));
        ui->player4->setText(QString::fromStdString(pseudos[3]));
        ui->player5->setText(QString::fromStdString(pseudos[4]));



        break ;
    case 6 :
        ui->player7->hide();
         ui->player8->hide();
         ui->player1->setText(QString::fromStdString(pseudos[0]));
         ui->player2->setText(QString::fromStdString(pseudos[1]));
         ui->player3->setText(QString::fromStdString(pseudos[2]));
         ui->player4->setText(QString::fromStdString(pseudos[3]));
         ui->player5->setText(QString::fromStdString(pseudos[4]));
         ui->player6->setText(QString::fromStdString(pseudos[5]));


        break ;
    case 7 :
        ui->player8->hide();
        ui->player1->setText(QString::fromStdString(pseudos[0]));
        ui->player2->setText(QString::fromStdString(pseudos[1]));
        ui->player3->setText(QString::fromStdString(pseudos[2]));
        ui->player4->setText(QString::fromStdString(pseudos[3]));
        ui->player5->setText(QString::fromStdString(pseudos[4]));
        ui->player6->setText(QString::fromStdString(pseudos[5]));
        ui->player7->setText(QString::fromStdString(pseudos[6]));

     case 8:
        ui->player1->setText(QString::fromStdString(pseudos[0]));
        ui->player2->setText(QString::fromStdString(pseudos[1]));
        ui->player3->setText(QString::fromStdString(pseudos[2]));
        ui->player4->setText(QString::fromStdString(pseudos[3]));
        ui->player5->setText(QString::fromStdString(pseudos[4]));
        ui->player6->setText(QString::fromStdString(pseudos[5]));
        ui->player7->setText(QString::fromStdString(pseudos[6]));
        ui->player8->setText(QString::fromStdString(pseudos[7]));

        break ;
    default:
        cout << "err nombre joueurs " << endl ;
    }

       game = new Game(nbPlayers,pseudos) ;
       Game::stateGame state;

}

void Board::keep ()
{
    if((indc != -1) && (indp !=-1))
    {
        printCardRevealed(game->next(indp,indc));
        indp = -1 ;
        indc = -1 ;
    }
    if (this->getCpt() >= game->getPlayers().size())
        printBeginMess();
    if(game->getState() != Game::Active)
    {
        QMessageBox msg ;

        switch (game->getState()) {
        case  Game::MoriartyWin:
            msg.setText("Moriarty is the boss");
            break;
        case  Game::SherlockWin:
            msg.setText("Sherlock is the boss");
            break;
        }
        msg.exec() ;
    }

}
void Board::printCardRevealed (const Card::typeCard &type)
{
    cout << "La carte révélée est: ";
    switch (type) {
        case Card::Safe:
            cout <<  "Inutile, carte SAFE."  << endl;
            break;
        case Card::Defusing:
            cout <<  "Utile, carte DEFUSING !"  << endl;
            break;
        case Card::Bomb:
            cout <<  "Mortelle, carte BOOOMB !!!" << endl;
    }
}

void Board::printBeginMess () {
   ui->round->setText(QString::number(game->getRound()));
    ui->nbDefusing->setText(QString::number(game->getNbDefusingCardsRevealed()));
    ui->tour->setText(QString::fromStdString(game->getCurrentPlayer().getPseudo()));
}

Board::~Board()
{
    delete ui;
}

string Board::type2str(Player p)
{
         string ms;
         switch(p.getRole()){
                  case Player::Sherlock :
                     ms = "Sherlock";
                     break;
                 case  Player::Moriarty :
                     ms = "Moriarty";
                     break;
         }
         return ms ;
}
string Board::typec2str(Card c)
{
string mm;

    switch(c.getType()){
             case Card::Safe:
                mm = "Safe";
                break;
            case Card::Defusing:
                mm = "Defusing";
                break;
            case Card::Bomb:
                mm = "Bomb";
                break;
    default :
        mm= "none" ;
        break ;
    }
    return mm ;
}
void Board::on_player1_clicked()
{
    Player p = game->getPlayers().at(0) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
       return;

    game->getPlayers().at(0).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    string mm = type2str(p);
    ui->role->setText(QString::fromStdString(mm)) ;
    afficheCard(1);
    indp = 1 ;

}

void Board::on_player2_clicked()
{
    Player p = game->getPlayers().at(1) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
       return;

    game->getPlayers().at(1).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    string mm = type2str(p);
    ui->role->setText(QString::fromStdString(mm)) ;
    size_t i;
    afficheCard(2);
    indp = 2 ;

}
void Board::on_player3_clicked()
{
    Player p = game->getPlayers().at(2) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
       return;

    game->getPlayers().at(2).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    string mm = type2str(p);
    ui->role->setText(QString::fromStdString(mm)) ;
    afficheCard(3);
    indp = 3 ;
}
void Board::on_player4_clicked()
{
    Player p = game->getPlayers().at(3) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
       return;

    game->getPlayers().at(3).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    string mm = type2str(p);
    ui->role->setText(QString::fromStdString(mm)) ;
    afficheCard(4);
    indp = 4 ;
}
void Board::on_player5_clicked()
{
    Player p = game->getPlayers().at(4) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
       return;

    game->getPlayers().at(4).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    string mm = type2str(p);
    ui->role->setText(QString::fromStdString(mm)) ;
    afficheCard(5);
    indp = 5 ;
}
void Board::on_player6_clicked()
{
    Player p = game->getPlayers().at(5) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
       return;

    game->getPlayers().at(5).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    string mm = type2str(p);
    ui->role->setText(QString::fromStdString(mm)) ;
    afficheCard(6);
    indp = 6 ;
}

void Board::on_player7_clicked()
{
    Player p = game->getPlayers().at(6) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
       return;

    game->getPlayers().at(6).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    string mm = type2str(p);
    ui->role->setText(QString::fromStdString(mm)) ;
    afficheCard(7);
    indp = 7 ;

}
void Board::on_player8_clicked()
{
    Player p = game->getPlayers().at(7) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
       return;

    game->getPlayers().at(7).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    string mm = type2str(p);
    ui->role->setText(QString::fromStdString(mm)) ;
    afficheCard(8);
    indp = 8 ;
}

void Board::on_backOptions_clicked()
{
        hideCards();
        if (this->getCpt() >= game->getPlayers().size())
            printBeginMess();
}

void Board::afficheCard(size_t j)
{
    size_t i;
    Player p = game->getPlayers().at(j - 1);
    size_t nbc = p.getCards().size();
    showCards(nbc);
    for (i = 1; i <= p.getCards().size(); i++)
    {
       switch (i)
       {
            case 1:
                ui->card1->setText(QString::fromStdString(typec2str(p.getCards().at(i - 1))));
                break;

           case 2:
               ui->card2->setText(QString::fromStdString(typec2str(p.getCards().at(i - 1))));
               break;

           case 3:
               ui->card3->setText(QString::fromStdString(typec2str(p.getCards().at(i - 1))));
               break;

           case 4:
               ui->card4->setText(QString::fromStdString(typec2str(p.getCards().at(i - 1))));
               break;

           case 5:
               ui->card5->setText(QString::fromStdString(typec2str(p.getCards().at(i - 1))));
               break;
       }
    }
}

void Board::hideCards()
{

    ui->card1->hide();
    ui->card2->hide();
    ui->card3->hide();
    ui->card4->hide();
    ui->card5->hide();
    ui->role->hide();
}
void Board::showCards(size_t i)
{
    switch (i)
    {
         case 5:
               ui->card1->show();
               ui->card2->show();
               ui->card3->show();
               ui->card4->show();
               ui->card5->show();
                break;

        case 4:
        ui->card1->show();
        ui->card2->show();
        ui->card3->show();
        ui->card4->show();
        break;


        case 3:
        ui->card1->show();
        ui->card2->show();
        ui->card3->show();
        break;

        case 2:
        ui->card1->show();
        ui->card2->show();
        break;

        case 1:
        ui->card1->show();
        break;


      }

    if(this->getCpt() < game->getPlayers().size())
        ui->role->show();


}

size_t Board::getCpt()
{
    return this->cpt;
}

void Board::setCpt(size_t cpt)
{
    this->cpt = cpt;
}



void Board::on_card1_clicked()
{
    indc = 1 ;
     keep() ;

}

void Board::on_card2_clicked()
{
    indc = 2 ;
     keep() ;

}

void Board::on_card3_clicked()
{
    indc = 3 ;
     keep() ;

}

void Board::on_card4_clicked()
{
    indc = 4 ;
     keep() ;
}

void Board::on_card5_clicked()
{
    indc = 5 ;
     keep() ;

}


