#include "../headers/mainwindow.h"
#include "../compiled/ui_mainwindow.h"
#include "../kernel/headers/Game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     this->on_back_clicked();
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
       ui->gridPseudo->addWidget(le, static_cast<int> (i), 0);
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
       ui->gridPseudo->addWidget(le, static_cast<int> (i), 0);
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
       ui->gridPseudo->addWidget(le, static_cast<int> (i), 0);
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
       ui->gridPseudo->addWidget(le, static_cast<int> (i), 0);
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
       ui->gridPseudo->addWidget(le, static_cast<int> (i), 0);
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
    size_t i;

    for (i = 0; i < nbPlayers ; i++)
    {
        pseudos[i] = psds.at(i).toStdString();

    }
    hideCards();
    switch(nbPlayers) {
    case 4 :
        ui->player5->hide() ;
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
       /* Game::stateGame state; */

       for (size_t i = 0; i < nbPlayers; i ++)
           this->reveals.push_back(false);

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
        Player &pepe = game->getPlayers().at(static_cast<unsigned> (indp - 1));
        //hideWithoutI(static_cast<size_t>(indc));
        Card &card = pepe.getCards().at(static_cast<unsigned> (indc - 1));
        printCardRevealed(game->next(card));
        blockPlayerCourant(game->getCurrentPlayer());
        indp = -1 ;
        indc = -1 ;
    }
    if (this->getCpt() >= game->getPlayers().size())
        printBeginMess();
    if(game->getState() != Game::Active)
    {
       // ui->menu->setCurrentWidget(ui->options);

        //QMessageBox msg ;

        switch (game->getState()) {
        case  Game::MoriartyWin:
            ui->menu->setCurrentWidget(ui->fin_mory);
            break;
        case  Game::SherlockWin:
            //msg.setText("Sherlock is the boss");
            ui->menu->setCurrentWidget(ui->fin_sherlock);
            break;
        default:
            break; // sinon warning
        }
        //msg.exec() ;
    }

}

void MainWindow::enableCards()
{
    ui->card1->setEnabled(true);
    ui->card2->setEnabled(true);
     ui->card3->setEnabled(true);
     ui->card4->setEnabled(true);
      ui->card5->setEnabled(true);
}
void MainWindow::disableCards()
{
     ui->card1->setEnabled(false);
     ui->card2->setEnabled(false);
      ui->card3->setEnabled(false);
      ui->card4->setEnabled(false);
       ui->card5->setEnabled(false);
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
        switch(game->getPlayers().at(static_cast<unsigned> (indp - 1)).getRole())
        {
            case Player::Moriarty:
            ui->role->setStyleSheet("background-image: url(:tb6.png); border-image: url(:tb6.png) 0 0 0 0 stretch; background-image:no-repeat;");
            break;

        case Player::Sherlock:
            ui->role->setStyleSheet("background-image: url(:tb1.png); border-image: url(:tb1.png) 0 0 0 0 stretch; background-image:no-repeat;");
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
                setCardImg(ui->card1,p.getCards().at(0).getType(),true);
                break;

           case 2:
               setCardImg(ui->card2,p.getCards().at(1).getType(),true);
               break;

           case 3:
              setCardImg(ui->card3,p.getCards().at(2).getType(),true);
               break;

           case 4:
               setCardImg(ui->card4,p.getCards().at(3).getType(),true);
               break;

           case 5:
           setCardImg(ui->card5,p.getCards().at(4).getType(),true);
               break;
       }
    }
}


void MainWindow::setCardImg(QPushButton *but , Card::typeCard type ,bool cache)
{
    bool firstpart = (this->getCpt() <= game->getPlayers().size()) ;
    switch(type)
    {
        case Card::Safe:
        if (!firstpart && cache) but->setStyleSheet("background-image: url(:tb14.png); border-image: url(:tb14.png) 0 0 0 0 stretch; background-image:no-repeat;");

        else but->setStyleSheet("background-image: url(:tb11.png); border-image: url(:tb11.png) 0 0 0 0 stretch; background-image:no-repeat;");
        break;

    case Card::Defusing:
        if (!firstpart && cache) but->setStyleSheet("background-image: url(:tb14.png); border-image: url(:tb14.png) 0 0 0 0 stretch; background-image:no-repeat;");
        else but->setStyleSheet("background-image: url(:tb12.png); border-image: url(:tb12.png) 0 0 0 0 stretch; background-image:no-repeat;");
        break;
    case Card::Bomb:
        if (!firstpart && cache) but->setStyleSheet("background-image: url(:tb14.png); border-image: url(:tb14.png) 0 0 0 0 stretch; background-image:no-repeat;");
        else but->setStyleSheet("background-image: url(:tb10.png); border-image: url(:tb10.png) 0 0 0 0 stretch; background-image:no-repeat;");
        break;
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

    if (this->reveals.at(0) && this->getCpt() < game->getPlayers().size())
     {indp = -1; return;}

    this->reveals.at(0) = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    enableCards();
    showCards(bjr) ;
    afficheCard(1);
}

void MainWindow::on_player8_clicked()
{
    indp = 8;
    Player p = game->getPlayers().at(7) ;

    if (this->reveals.at(7) && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    this->reveals.at(7) = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    enableCards();
    afficheCard(8);
}

void MainWindow::on_player7_clicked()
{
    indp = 7;
    Player p = game->getPlayers().at(6) ;

    if (this->reveals.at(6) && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    this->reveals.at(6) = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    enableCards();
    afficheCard(7);
}

void MainWindow::on_player6_clicked()
{
    indp = 6;
    Player p = game->getPlayers().at(5) ;

    if (this->reveals.at(5) && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    this->reveals.at(5) = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    enableCards();

    afficheCard(6);
}

void MainWindow::on_player5_clicked()
{
    indp = 5;
    Player p = game->getPlayers().at(4) ;

    if (this->reveals.at(4) && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    this->reveals.at(4) = true;

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

    if (this->reveals.at(3) && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    this->reveals.at(3) = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    enableCards();

    afficheCard(4);
}

void MainWindow::on_player3_clicked()
{
    indp = 3 ;
    Player p = game->getPlayers().at(2) ;

    if (this->reveals.at(2) && this->getCpt() < game->getPlayers().size())
    {indp = -1; return;}

    this->reveals.at(2) = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    enableCards();

    afficheCard(3);

}

void MainWindow::on_player2_clicked()
{
    indp = 2 ;
    Player p = game->getPlayers().at(1) ;

    if (this->reveals.at(1) && this->getCpt() < game->getPlayers().size())
    { indp = 1; return;}

    this->reveals.at(1) = true;

    size_t tmp = this->getCpt();
    tmp++;
    this->setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    enableCards();

    afficheCard(2);
}

void MainWindow::on_card5_clicked()
{

    if (this->getCpt() < game->getPlayers().size())
       return;
    indc = 5;
    disableCards();
    Card::typeCard type = game->getPlayers().at(static_cast<unsigned> (indp-1)).getCards().at(static_cast<unsigned> (indc-1)).getType() ;
    setCardImg(ui->card5,type,false);
     keep() ;
}

void MainWindow::on_card4_clicked()
{

    if (this->getCpt() < game->getPlayers().size())
       return;
    indc = 4;
    disableCards();
    Card::typeCard type = game->getPlayers().at(static_cast<unsigned> (indp-1)).getCards().at(static_cast<unsigned> (indc-1)).getType() ;
    setCardImg(ui->card4,type,false);
     keep() ;
}

void MainWindow::on_card3_clicked()
{

    if (this->getCpt() < game->getPlayers().size())
       return;
    indc = 3;
    disableCards();
    Card::typeCard type = game->getPlayers().at(static_cast<unsigned> (indp-1)).getCards().at(static_cast<unsigned> (indc-1)).getType() ;
    setCardImg(ui->card3,type,false);
     keep() ;
}

void MainWindow::on_card2_clicked()
{

    if (this->getCpt() < game->getPlayers().size())
       return;
    indc = 2;
    disableCards();
    Card::typeCard type = game->getPlayers().at(static_cast<unsigned> (indp-1)).getCards().at(static_cast<unsigned> (indc-1)).getType() ;
    setCardImg(ui->card2,type,false);
     keep() ;
}

void MainWindow::on_card1_clicked()
{

    if (this->getCpt() < game->getPlayers().size())
       return;
    indc = 1;
    Card::typeCard type = game->getPlayers().at(static_cast<unsigned> (indp-1)).getCards().at(static_cast<unsigned> (indc-1)).getType() ;
    setCardImg(ui->card1,type,false);
    disableCards();
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
         for(size_t i = 0 ; i<game->getPlayers().size() && cour == -1;i++)
         {
             if(p.getPseudo() == game->getPlayers().at(i).getPseudo())
             {
                cour = static_cast<int> (i) ;
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

    QPixmap pix(file[i]);
    int w = ui->labelPic->width();
    int h = ui->labelPic->height();
    ui->labelPic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_leave_sherlock_clicked()
{
    this->close();
}

void MainWindow::on_leave_mory_clicked()
{
    this->close();
}

void MainWindow::on_leave_menu_clicked()
{
    this->close();
}

void MainWindow::on_Previous_clicked()
{
    if(i>0) i--;
    QPixmap pix(file[i]);
    int w = ui->labelPic->width();
    int h = ui->labelPic->height();
    ui->labelPic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

void MainWindow::on_next_clicked()
{
    if(i<12) i++;
    QPixmap pix(file[i]);
    int w = ui->labelPic->width();
    int h = ui->labelPic->height();
    ui->labelPic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_backfromhelp_clicked()
{
    ui->menu->setCurrentWidget(ui->start);
}
