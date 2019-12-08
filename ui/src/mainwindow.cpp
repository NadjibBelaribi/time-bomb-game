#include "../headers/mainwindow.h"
#include "../compiled/ui_mainwindow.h"
#include "../../kernel/headers/Game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->roundNext->hide();

    players = new QPushButton* [8];
    size_t i = 0;
    for (i = 0; i < 8; i ++) {
        switch (i) {
            case 0: players[i] = ui->player1; break;
            case 1: players[i] = ui->player2; break;
            case 2: players[i] = ui->player3; break;
            case 3: players[i] = ui->player4; break;
            case 4: players[i] = ui->player5; break;
            case 5: players[i] = ui->player6; break;
            case 6: players[i] = ui->player7; break;
            case 7: players[i] = ui->player8; break;
        }
    }

    cards = new QPushButton* [5];
    for (i = 0; i < 5; i ++) {
        switch (i) {
            case 0: cards[i] = ui->card1; break;
            case 1: cards[i] = ui->card2; break;
            case 2: cards[i] = ui->card3; break;
            case 3: cards[i] = ui->card4; break;
            case 4: cards[i] = ui->card5; break;
        }
    }


    on_back_clicked();
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
    initPseudoFields(4);
}

void MainWindow::on_back_clicked()
{
    ui->menu->setCurrentWidget(ui->start);
}

void MainWindow::on_nb4_clicked()
{
    initPseudoFields(4);
}

void MainWindow::on_nb5_clicked()
{
    initPseudoFields(5);
}

void MainWindow::on_nb6_clicked()
{
    initPseudoFields(6);
}

void MainWindow::on_nb7_clicked()
{
    initPseudoFields(7);
}

void MainWindow::on_nb8_clicked()
{
    initPseudoFields(8);
}

void MainWindow::initPseudoFields (const size_t n)
{
    RemoveLayout(ui->gridPseudo);
    size_t i;
    for (i = 1; i <= n; i++)
    {
        QLineEdit *le = new QLineEdit();
        if (fr)
            le->setPlaceholderText(QString("Joueur %1").arg(i));
        else
            le->setPlaceholderText(QString("Player %1").arg(i));
        ui->gridPseudo->addWidget(le, i, 0);
        hello.push_back(le);
    }
}

inline bool caseInsCharCompareN(char a, char b) {
   return(toupper(a) == toupper(b));
 }

inline bool caseInsCharCompareW(wchar_t a, wchar_t b) {
 return(towupper(a) == towupper(b));
}

bool MainWindow::caseInsCompare(const string& s1, const string& s2) {
 return((s1.size() == s2.size()) &&
        equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareN));
  }

bool MainWindow::caseInsCompare(const wstring& s1, const wstring& s2) {
    return((s1.size() == s2.size()) &&
       equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareW));
}

bool MainWindow::same(vector <QString> psd)
{
    size_t i, j;
    for (i = 0; i < psd.size(); i++)
    {
        for (j = 0; j < psd.size(); j++)
        {
            string s1 = psd.at(i).toStdString();
            string s2 = psd.at(j).toStdString();
            bool x = caseInsCompare(s1,s2);
            if (i != j && (x == 0))
                return true;
        }
    }
    return false;
}

void MainWindow::on_go_clicked()
{
    size_t nb_players = hello.size();
    size_t i, compteur = 0;
    if (nb_players < 4) return;

    for (i = 0; i < nb_players; i++)
    {
        QString tmp = hello.at(i)->text();
        if (!hello.at(i)->text().isEmpty())
        {
            compteur++;
            pseudos.push_back(tmp);
        }
    }
    if (compteur == nb_players && (!same(pseudos)))
    {
        for (i = 0; i < nb_players; i ++)
            players[i]->setEnabled(true);
        ui->menu->setCurrentWidget(ui->board);
        reveals.clear();
        setTable(pseudos);
        setCpt(0);
        if (fr)
            ui->status->setText("Découvrez votre rôle et cartes !");
        else
            ui->status->setText("Discover your role and your cards");
        ui->role->hide();
        ui->defusing->display(0);
        ui->round->display(1);
        showPlayers();
        RemoveLayout(ui->gridPseudo);
    }

    if (compteur != nb_players)
    {
        QMessageBox msgBox;
        if (fr)
            msgBox.setText("Veuillez rentrer des pseudos non vides");
        else
            msgBox.setText("Please enter non null usernames");
        msgBox.exec();
    }
    else if (same(pseudos))
    {
        QMessageBox msgBox;
        if (fr)
            msgBox.setText("Veuillez rentrer des pseudos différents");
        else
            msgBox.setText("Please enter different usernames");
        msgBox.exec();
    }

    for (i = 0; i < compteur; i++)
    {
        pseudos.pop_back();
    }
}

std::vector <QString> MainWindow::getPseudo()
{
    return pseudos;
}

void MainWindow::setTable( std::vector <QString> psds ) {

    const size_t nbPlayers= psds.size() ;
    size_t i;
    string *pd = new string [nbPlayers];

    for (i = 0; i < nbPlayers ; i++)
    {
        pd[i] = psds.at(i).toStdString();
        players[i]->setText(QString::fromStdString(pd[i]));

    }
    for (; i < 8; i ++)
        players[i]->hide();

    hideCards();
    game = new Game(nbPlayers, pd) ;

    for (size_t i = 0; i < nbPlayers; i ++)
        reveals.push_back(false);

}

void MainWindow::hideCards()
{
    for (int i = 0; i < 5; i ++)
        cards[i]->hide();

    ui->role->hide();
    ui->name->hide();
}

void MainWindow::hideWithoutI(size_t j)
{
    for( size_t i = 0; i < 5; i ++) {
        if (i == j)
            continue;
        cards[i]->hide();
    }

    ui->role->hide();
}


void MainWindow::keep ()
{
    if((indc != -1) && (indp !=-1))
    {
        Player &pepe = game->getPlayers().at(indp);
        //hideWithoutI(static_cast<size_t>(indc));
        Card &card = pepe.getCards().at(indc);
        string typ (typec2str(card));
        QString txt (QString::fromStdString(typ));
        if (fr)
            txt.append(" ! Au tour de ");
        else
            txt.append(" ! Turn of ");
        txt.append(QString::fromStdString(pepe.getPseudo()).toUpper());
        ui->status->setText(txt);
        const size_t oldRound = game->getRound();
        printCardRevealed(game->next(card));
        ui->name->setText(QString::fromStdString(game->getCurrentPlayer().getPseudo()).toUpper());

        if (oldRound < game->getRound()) {
            // nouv round
            // on refait pphase reveals
            setCpt(0);
            for (size_t i = 0; i < reveals.size(); i ++)
                reveals.at(i) = false;
            QString s ("ROUND ");
            s.append(QString::number(game->getRound()));
            if (fr)
                s.append(" ! Découvrez vos cartes");
            else
                s.append(" ! Discover your cards!");
            ui->status->setText(s);
            ui->role->hide();
            ui->name->hide();
            showPlayers();

        } else {
            blockPlayerCourant(game->getCurrentPlayer());
            ui->round->display(QString::number(game->getRound()));
            ui->defusing->display(QString::number(game->getNbDefusingCardsRevealed()));
        }
        indp = -1 ;
        indc = -1 ;
    }

    if(game->getState() != Game::Active)
    {
        // ui->menu->setCurrentWidget(ui->options);

        //QMessageBox msg ;
        QPixmap pixm(":fin_mori.png");
        QPixmap pixs(":fin_sherlock.png");
        int w = pixm.width();
        int h = pixm.height();

        switch (game->getState()) {
            case  Game::MoriartyWin:
                ui->menu->setCurrentWidget(ui->fin);
                ui->fin_img->setPixmap(pixm.scaled(w,h,Qt::KeepAspectRatio));
                if (fr)
                    ui->winner->setText("BOOOOOM !! Moriarty a gagné !");
                else
                    ui->winner->setText("BOOOOOM !! Moriarty has won !");
                game->~Game();
                indp = -1;
                indc = -1;
                setCpt(0);
                size_t i;
                for (i = 0; i < reveals.size(); i++)
                    reveals.at(i) = false;
                break;
            case  Game::SherlockWin:
                //msg.setText("Sherlock is the boss");
                ui->menu->setCurrentWidget(ui->fin);
                if (fr)
                    ui->winner->setText("Oui !! Sherlock a gagné !");
                else
                    ui->winner->setText("Yeaah !! Sherlock has won !");
                ui->fin_img->setPixmap(pixs.scaled(w,h,Qt::KeepAspectRatio));
                break;
            case Game::Active:
                break;
        }
        //msg.exec() ;
    }

}

void MainWindow::enableCards()
{
    for (int i = 0; i < 5; i ++)
        cards[i]->setEnabled(true);
}
void MainWindow::disableCards()
{
    for (int i = 0; i < 5; i ++)
        cards[i]->setEnabled(false);
}

size_t MainWindow::getCpt()
{
    return cpt;
}

void MainWindow::setCpt(size_t cpt)
{
    this->cpt = cpt;
}

string MainWindow::typec2str(const Card &c)
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
    }
    return mm ;
}


void MainWindow::showCards(size_t nb)
{
    for (size_t j = 0; j < nb; j ++)
        cards[j]->show();

    if(getCpt() <= game->getPlayers().size())
    {
        // reveals
        switch(game->getPlayers().at(indp).getRole())
        {
            case Player::Moriarty:
                ui->role->setStyleSheet("background-image: url(:tb6.png); border-image: url(:tb6.png) 0 0 0 0 stretch; background-image:no-repeat;");
                break;

            case Player::Sherlock:
                ui->role->setStyleSheet("background-image: url(:tb1.png); border-image: url(:tb1.png) 0 0 0 0 stretch; background-image:no-repeat;");
                break;
        }
        ui->name->setText(QString::fromStdString(game->getPlayers().at(indp).getPseudo()).toUpper());

    } else {
        // jeu normal
        ui->role->setStyleSheet("background-image: url(:tb9.png); border-image: url(:tb9.png) 0 0 0 0 stretch; background-image:no-repeat;");
        ui->name->setText(QString::fromStdString(game->getCurrentPlayer().getPseudo()).toUpper());
    }

    ui->role->show();
    ui->name->show();
}

void MainWindow::afficheCard(size_t j)
{
    size_t i;
    Player &p = game->getPlayers().at(j);
    size_t nbc = p.getCards().size();
    showCards(nbc);
    for (i = 0; i < p.getCards().size(); i++)
    {
        cards[i]->show();
        setCardImg(cards[i],p.getCards().at(i).getType(),true);
    }

    for (; i < 5; i ++)
        cards[i]->hide();
}


void MainWindow::setCardImg(QPushButton *but , Card::typeCard type ,bool cache)
{
    bool firstpart = (getCpt() <= game->getPlayers().size()) ;
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

void MainWindow::playerClicked (size_t i)
{
    Player p = game->getPlayers().at(i) ;
    if (reveals.at(i) && getCpt() < game->getPlayers().size()){
        indp = -1;
        return;
    }

    reveals.at(i) = true;
    indp = i;

    size_t tmp = getCpt();
    tmp++;
    setCpt(tmp);

    size_t bjr = p.getCards().size();
    showCards(bjr) ;
    enableCards();
    afficheCard(i);

    if (tmp == game->getPlayers().size()) {
        // phase reveals terminée
        // go nouvelle round quand bouton cliqué seulement
        hidePlayer(i);
        ui->roundNext->show();
        waitNextRound = true;
    } else if (tmp < game->getPlayers().size()) {
        // reveal en cours
        hidePlayer(i);
    }
}

void MainWindow::on_roundNext_clicked ()
{
    for (size_t i = 0; i < reveals.size(); i ++)
        reveals.at(i) = false;
    setCpt(getCpt() + 1);
    if (fr)
    {
         QString s ("C'est parti ! Au tour de ");
         s.append(QString(QString::fromStdString(game->getCurrentPlayer().getPseudo())).toUpper());
         ui->status->setText(s);
    }
    else
    {
        QString s ("Let's go ! it's turn of ");
        s.append(QString(QString::fromStdString(game->getCurrentPlayer().getPseudo())).toUpper());
        ui->status->setText(s);
    }

    showPlayers();
    blockPlayerCourant(game->getCurrentPlayer());
    ui->roundNext->hide();

    showCards(game->getCurrentPlayer().getCards().size());
    hideCards();
    ui->role->show();
    ui->name->show();
    waitNextRound = false;
}

void MainWindow::on_player8_clicked()
{
    playerClicked(7);
}

void MainWindow::on_player7_clicked()
{
    playerClicked(6);
}

void MainWindow::on_player6_clicked()
{
    playerClicked(5);
}

void MainWindow::on_player5_clicked()
{
    playerClicked(4);
}

void MainWindow::on_player4_clicked()
{
    playerClicked(3);
}

void MainWindow::on_player3_clicked()
{
    playerClicked(2);
}

void MainWindow::on_player2_clicked()
{
    playerClicked(1);
}

void MainWindow::on_player1_clicked()
{
    playerClicked(0);
}

void MainWindow::cardClicked (const size_t i)
{
    if ((getCpt() < game->getPlayers().size()) || waitNextRound)
        return;
    indc = i;
    disableCards();
    Card::typeCard type = game->getPlayers().at(indp).getCards().at(indc).getType() ;
    setCardImg(cards[i],type,false);
    keep() ;
}


void MainWindow::on_card5_clicked()
{
    cardClicked(4);
}

void MainWindow::on_card4_clicked()
{
    cardClicked(3);
}

void MainWindow::on_card3_clicked()
{

    cardClicked(2);
}

void MainWindow::on_card2_clicked()
{
    cardClicked(1);
}

void MainWindow::on_card1_clicked()
{
    cardClicked(0);
}

void MainWindow::showPlayers ()
{
    size_t nbp = game->getPlayers().size();
    for (size_t i = 0; i < nbp; i ++) {
        players[i]->setEnabled(true);
        players[i]->show();
    }
}

void MainWindow::hidePlayer (const size_t i)
{
    players[i]->setEnabled(false);
    players[i]->hide();
}

void MainWindow::blockPlayerCourant (Player p)
{
    showPlayers();
    int cour = -1 ;
    size_t nbp = game->getPlayers().size();
    for(size_t i = 0 ; i<nbp && cour == -1;i++)
    {
        if(p.getPseudo() == game->getPlayers().at(i).getPseudo())
        {
            cour = i ;
        }
    }

    players[cour]->setEnabled(false);
    players[cour]->hide();
}

void MainWindow::on_help_clicked()
{
    ui->menu->setCurrentWidget(ui->aide);

    QPixmap pix(file[i]);
    int w = ui->labelPic->width();
    int h = ui->labelPic->height();
    ui->labelPic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_leave_clicked()
{
    close();
}

void MainWindow::on_leave_menu_clicked()
{
    close();
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
    if(i<11) i++;
    QPixmap pix(file[i]);
    int w = ui->labelPic->width();
    int h = ui->labelPic->height();
    ui->labelPic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_backfromhelp_clicked()
{
    ui->menu->setCurrentWidget(ui->start);
}

void MainWindow::on_replay_clicked()
{
    ui->menu->setCurrentWidget(ui->options);
    initPseudoFields(4);
}



/* ---------- NETWORK ---------- */

void MainWindow::on_playNetwork_clicked ()
{
    ui->menu->setCurrentWidget(ui->networkMenu);
}

void MainWindow::on_networkMenuBack_clicked ()
{
    ui->menu->setCurrentWidget(ui->start);
}

void MainWindow::on_networkHostGo_clicked ()
{
    ui->menu->setCurrentWidget(ui->board);
    // GO HOST
}

void MainWindow::on_networkJoinGo_clicked ()
{
    ui->menu->setCurrentWidget(ui->board);
    // GO JOIN
}

void MainWindow::english()
{
    fr = false;
    ui->help->setText("Help");
    ui->playNetwork->setText("Network");
    ui->leave_menu->setText("Leave");
    ui->back->setText("Back");
    ui->label_3->setText("Number of players");
    ui->go->setText("Start!");
    ui->networkMenuBack->setText("Back");
    ui->label_4->setText("Host");
    ui->label_5->setText("Join");
    ui->networkHostGo->setText("Host");
    ui->networkJoinGo->setText("Join");
    ui->label_6->setText("Nb players");
    ui->replay->setText("Replay");
    ui->backfromhelp->setText("Back");
    ui->roundNext->setText("Continue");
    ui->label_2->setText("Defuse Wires");
    ui->leave->setText("Leave");
}

void MainWindow::french()
{
    fr = true;
    ui->help->setText("Aide");
    ui->playNetwork->setText("Réseau");
    ui->leave_menu->setText("Quitter");
    ui->back->setText("Retour");
    ui->label_3->setText("Nombre de joueurs");
    ui->go->setText("Commencer!");
    ui->networkMenuBack->setText("Retour");
    ui->label_4->setText("Héberger");
    ui->label_5->setText("Rejoindre");
    ui->networkHostGo->setText("Héberger");
    ui->networkJoinGo->setText("Rejoindre");
    ui->label_6->setText("Nb joueurs");
    ui->replay->setText("Rejouer");
    ui->backfromhelp->setText("Retour");
    ui->roundNext->setText("Continuer");
    ui->label_2->setText("Fils diffuseurs");
    ui->leave->setText("Quitter");
}

void MainWindow::on_eng_trad_clicked()
{
   english();
}

void MainWindow::on_fr_trad_clicked()
{
    french();
}
