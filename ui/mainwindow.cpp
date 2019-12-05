#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "options.h"
#include "kernel/Game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::RemoveLayout (QGridLayout* widget)
{
    int i;
    for (i = 0; i < widget->count(); i++)
    {
        widget->itemAt(i)->widget()->deleteLater();
        hello.pop_back();
    }
}

void MainWindow::on_playB_clicked()
{
    ui->menu->setCurrentWidget(ui->options);
}

void MainWindow::on_back_clicked()
{
    ui->menu->setCurrentWidget(ui->start);
}

void MainWindow::on_nb4_clicked()
{
    RemoveLayout(ui->gridPseudo);
    size_t nb_players = 4;
    size_t i;
    for (i = 0; i < nb_players; i++)
    {
       QLineEdit *le = new QLineEdit();
       le->setPlaceholderText(QString("Player %1").arg(i));
       ui->gridPseudo->addWidget(le, i, 0);
       hello.push_back(le);
    }
}

void MainWindow::on_nb5_clicked()
{
    RemoveLayout(ui->gridPseudo);
    size_t nb_players = 5;
    size_t i;
    for (i = 0; i < nb_players; i++)
    {
       QLineEdit *le = new QLineEdit();
       le->setPlaceholderText(QString("Player %1").arg(i));
       ui->gridPseudo->addWidget(le, i, 0);
       hello.push_back(le);
    }
}

void MainWindow::on_nb6_clicked()
{
    RemoveLayout(ui->gridPseudo);
    size_t nb_players = 6;
    size_t i;
    for (i = 0; i < nb_players; i++)
    {
       QLineEdit *le = new QLineEdit();
       le->setPlaceholderText(QString("Player %1").arg(i));
       ui->gridPseudo->addWidget(le, i, 0);
       hello.push_back(le);
    }
}

void MainWindow::on_nb7_clicked()
{
    RemoveLayout(ui->gridPseudo);
    size_t nb_players = 7;
    size_t i;
    for (i = 0; i < nb_players; i++)
    {
       QLineEdit *le = new QLineEdit();
       le->setPlaceholderText(QString("Player %1").arg(i));
       ui->gridPseudo->addWidget(le, i, 0);
       hello.push_back(le);
    }
}

void MainWindow::on_nb8_clicked()
{
    RemoveLayout(ui->gridPseudo);
    size_t nb_players = 8;
    size_t i;
    for (i = 0; i < nb_players; i++)
    {
       QLineEdit *le = new QLineEdit();
       le->setPlaceholderText(QString("Player %1").arg(i));
       ui->gridPseudo->addWidget(le, i, 0);
       hello.push_back(le);
    }
}

void MainWindow::on_go_clicked()
{
    size_t nb_players = hello.size();
    cout << nb_players << endl;
    size_t i;
    for (i = 0; i < nb_players; i++)
    {
      QString tmp = hello.at(i)->text();
      pseudos.push_back(tmp);
     }
     ui->menu->setCurrentWidget(ui->board);
    this->setTable(pseudos);
     this->cpt = 0;
}

std::vector <QString> MainWindow::getPseudo()
{
    return this->pseudos;
}

void MainWindow::setTable( std::vector <QString> psds ) {

    const size_t nbPlayers= psds.size() ;
    std::string *pseudos = new string[nbPlayers];
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
              break;

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

void MainWindow::hideCards()
{

    ui->card1->hide();
    ui->card2->hide();
    ui->card3->hide();
    ui->card4->hide();
    ui->card5->hide();
    ui->role->hide();
}

void MainWindow::hideWithoutI(size_t i)
{
    switch (i)
    {
        case 1:
            ui->card2->hide();
            ui->card3->hide();
            ui->card4->hide();
            ui->card5->hide();
        break;

        case 2:
            ui->card1->hide();
            ui->card3->hide();
            ui->card4->hide();
            ui->card5->hide();
        break;

        case 3:
            ui->card1->hide();
            ui->card2->hide();
            ui->card4->hide();
            ui->card5->hide();
        break;

        case 4:
            ui->card1->hide();
            ui->card2->hide();
            ui->card3->hide();
            ui->card5->hide();
        break;

        case 5:
            ui->card1->hide();
            ui->card2->hide();
            ui->card3->hide();
            ui->card4->hide();
        break;
    }
    ui->role->hide();
}


void MainWindow::keep ()
{
    if((indc != -1) && (indp !=-1))
    {
        printCardRevealed(game->next(indp,indc));
        hideWithoutI(static_cast<size_t>(indc));
        blockPlayerCourant(game->getCurrentPlayer());
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

size_t MainWindow::getCpt()
{
    return this->cpt;
}

void MainWindow::setCpt(size_t cpt)
{
    this->cpt = cpt;
}

string MainWindow::type2str(Player p)
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

string MainWindow::typec2str(Card c)
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


void MainWindow::showCards(size_t i)
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

    if(this->getCpt() <= game->getPlayers().size())
    {
        switch(game->getPlayers().at(indp - 1).getRole())
        {
            case Player::Moriarty:
            ui->role->setStyleSheet("background-image: url(:/imgs/imgs/tb6.png); border-image: url(:/imgs/imgs/tb6.png) 0 0 0 0 stretch; background-image:no-repeat;");
            break;

        case Player::Sherlock:
            ui->role->setStyleSheet("background-image: url(:/imgs/imgs/tb1.png); border-image: url(:/imgs/imgs/tb1.png) 0 0 0 0 stretch; background-image:no-repeat;");
            break;
        }
        ui->role->show();
    }



}

void MainWindow::afficheCard(size_t j)
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
                ui->card1->setText(QString::fromStdString(typec2str(p.getCards().at(0))));
                break;

           case 2:
               ui->card2->setText(QString::fromStdString(typec2str(p.getCards().at(1))));
               break;

           case 3:
               ui->card3->setText(QString::fromStdString(typec2str(p.getCards().at(2))));
               break;

           case 4:
               ui->card4->setText(QString::fromStdString(typec2str(p.getCards().at(3))));
               break;

           case 5:
               ui->card5->setText(QString::fromStdString(typec2str(p.getCards().at(4))));
               break;
       }
    }
}

void MainWindow::on_backOptions_clicked()
{
    hideCards();
    if (this->getCpt() >= game->getPlayers().size())
        printBeginMess();
    blockPlayerCourant(game->getCurrentPlayer());
}




void MainWindow::printCardRevealed (const Card::typeCard &type)
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

void MainWindow::printBeginMess () {
   ui->round->setText(QString::number(game->getRound()));
    ui->nbDefusing->setText(QString::number(game->getNbDefusingCardsRevealed()));
    ui->tour->setText(QString::fromStdString(game->getCurrentPlayer().getPseudo()));
}

void MainWindow::on_player1_clicked()
{
    indp = 1;
    Player p = game->getPlayers().at(0) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
     {indp = -1; return;}

    game->getPlayers().at(0).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    afficheCard(1);
}

void MainWindow::on_player8_clicked()
{
    indp = 8;
    Player p = game->getPlayers().at(7) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    game->getPlayers().at(7).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    afficheCard(8);
}

void MainWindow::on_player7_clicked()
{
    indp = 7;
    Player p = game->getPlayers().at(6) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    game->getPlayers().at(6).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    afficheCard(7);
}

void MainWindow::on_player6_clicked()
{
    indp = 6;
    Player p = game->getPlayers().at(5) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    game->getPlayers().at(5).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    afficheCard(6);
}

void MainWindow::on_player5_clicked()
{
    indp = 5;
    Player p = game->getPlayers().at(4) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    game->getPlayers().at(4).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    afficheCard(5);
}

void MainWindow::on_player4_clicked()
{
    indp = 4;
    Player p = game->getPlayers().at(3) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    game->getPlayers().at(3).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    afficheCard(4);
}

void MainWindow::on_player3_clicked()
{
    indp = 3 ;
    Player p = game->getPlayers().at(2) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    game->getPlayers().at(2).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    afficheCard(3);

}

void MainWindow::on_player2_clicked()
{
    indp = 2 ;
    Player p = game->getPlayers().at(1) ;

    if (p.reveal && this->getCpt() < game->getPlayers().size())
    { indp = 1; return;}

    game->getPlayers().at(1).reveal = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    size_t i;
    afficheCard(2);
}

void MainWindow::on_card5_clicked()
{
    if (this->getCpt() < game->getPlayers().size())
       return;
    indc = 5;
     keep() ;
}

void MainWindow::on_card4_clicked()
{
    if (this->getCpt() < game->getPlayers().size())
       return;
    indc = 4;
     keep() ;
}

void MainWindow::on_card3_clicked()
{
    if (this->getCpt() < game->getPlayers().size())
       return;
    indc = 3;
     keep() ;
}

void MainWindow::on_card2_clicked()
{
    if (this->getCpt() < game->getPlayers().size())
       return;
    indc = 2;
     keep() ;
}

void MainWindow::on_card1_clicked()
{
    if (this->getCpt() < game->getPlayers().size())
       return;
    indc = 1;
     keep() ;
}

void MainWindow::blockPlayerCourant (Player p)
{

        ui->player1->setEnabled(true);
        ui->player2->setEnabled(true);
         ui->player3->setEnabled(true);
         ui->player4->setEnabled(true);
         ui->player5->setEnabled(true);
         ui->player6->setEnabled(true);
         ui->player7->setEnabled(true);
         ui->player8->setEnabled(true);
         int cour = -1 ;
         for(int i = 0 ; i<game->getPlayers().size() && cour == -1;i++)
         {
             if(p.getPseudo() == game->getPlayers().at(i).getPseudo())
             {
                cour = i ;
             }
         }
         switch (cour+1) {
         case 1 :
                ui->player1->setEnabled(false);
          break;
         case 2 :
                ui->player2->setEnabled(false);
          break;
         case 3 :
             ui->player3->setEnabled(false);
       break;
         case 4 :
             ui->player4->setEnabled(false);
       break;
         case 5 :
             ui->player5->setEnabled(false);
       break;
         case 6 :
             ui->player6->setEnabled(false);
       break;
         case 7 :
             ui->player7->setEnabled(false);
       break;
         case 8 :
             ui->player8->setEnabled(false);
       break;

         }


}

void MainWindow::on_help_clicked()
{
    ui->menu->setCurrentWidget(ui->aide);
}
