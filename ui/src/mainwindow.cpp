#include "../headers/mainwindow.h"
#include "../compiled/ui_mainwindow.h"
#include "../../kernel/headers/Game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->roundNext->hide();
    ui->viewCards->hide();
    ui->pseudo->hide();
    ui->tchatArea->hide();
    ui->tchatInput->hide();
    ui->tchatSend->hide();
    ui->boardQuit->hide();
    srand (time(NULL));

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
            if (i != j && x)
                return true;
        }
    }
    return false;
}

void MainWindow::on_go_clicked()
{
    net = false;
    ui->pseudo->hide();
    ui->tchatArea->hide();
    ui->tchatInput->hide();
    ui->tchatSend->hide();
    ui->boardQuit->show();
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

    if (same(pseudos))
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

    if (!net)
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
        string typ (typec2str(card.getType()));
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
                break;
            case  Game::SherlockWin:
                //msg.setText("Sherlock is the boss");
                ui->menu->setCurrentWidget(ui->fin);
                ui->fin_img->setPixmap(pixs.scaled(w,h,Qt::KeepAspectRatio));
                if (fr)
                    ui->winner->setText("Oui !! Sherlock a gagné !");
                else
                    ui->winner->setText("Yeaah !! Sherlock has won !");
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

string MainWindow::typec2str(Card::typeCard tc)
{
    string mm;

    switch(tc){
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
    vector<Card> temp = p.getCards() ;
    size_t nbc = temp.size();
    if (getCpt() <= game->getPlayers().size())
    {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            shuffle(temp.begin(), temp.end(), default_random_engine(seed));
    }
    showCards(nbc);
    for (i = 0; i < nbc; i++)
    {
        cards[i]->show();
        setCardImg(cards[i],temp.at(i).getType(),true);
    }

    for (; i < 5; i ++)
        cards[i]->hide();
}


void MainWindow::setCardImg(QPushButton *but , Card::typeCard type ,bool cache)
{
    bool firstpar;
    if (net)
        firstpar = netReveal;
    else
        firstpar = (getCpt() <= game->getPlayers().size()) ;
    switch(type)
    {
        case Card::Safe:
            if (!firstpar && cache) but->setStyleSheet("background-image: url(:tb14.png); border-image: url(:tb14.png) 0 0 0 0 stretch; background-image:no-repeat;");

            else but->setStyleSheet("background-image: url(:tb11.png); border-image: url(:tb11.png) 0 0 0 0 stretch; background-image:no-repeat;");
            break;

        case Card::Defusing:
            if (!firstpar && cache) but->setStyleSheet("background-image: url(:tb14.png); border-image: url(:tb14.png) 0 0 0 0 stretch; background-image:no-repeat;");
            else but->setStyleSheet("background-image: url(:tb12.png); border-image: url(:tb12.png) 0 0 0 0 stretch; background-image:no-repeat;");
            break;
        case Card::Bomb:
            if (!firstpar && cache) but->setStyleSheet("background-image: url(:tb14.png); border-image: url(:tb14.png) 0 0 0 0 stretch; background-image:no-repeat;");
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
    if (net) {
        if (netIsCur && !netReveal) {
            netSelectPlayer = players[i]->text().toStdString();
            netShowPlayerCards(players[i]->text().toStdString());
            netEnableCards();
        }
    } else {
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
}

void MainWindow::on_roundNext_clicked ()
{
    if (net) {
        string typ (typec2str(netGst.lastCardRevealed));
        QString txt (QString::fromStdString(typ));
        if (fr)
            txt.append(" ! Au tour de ");
        else
            txt.append(" ! Turn of ");
        txt.append(QString::fromStdString(netGst.currentPlayer).toUpper());
        ui->status->setText(txt);

        netReveal = false;
        ui->roundNext->hide();
        netCb(netGst);

    } else {
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
}

void MainWindow::on_viewCards_clicked ()
{
    QString s ("ROUND ");
    s.append(QString::number(netGst.round));
    if (fr)
        s.append(" ! Découvrez vos cartes");
    else
        s.append(" ! Discover your cards!");
    ui->status->setText(s);
    netReveal = true;
    netShowMyCards();
    netSetMyRole();
    netHidePlayers();
    ui->viewCards->hide();
    ui->roundNext->show();
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
    if (net) {
        if (!netIsCur || netReveal)
            return;

        if (netIsCur) {

            size_t nbc = 0;
            for (size_t j = 0; j < netGst.oPlayers.size(); j ++) {
                if (netGst.oPlayers[j] == netSelectPlayer) {
                    nbc = netGst.oNbCards[j];
                    break;
                }
            }
            netLastRevealNbCards = nbc;
            netLastRevealIndCard = i;
            if (netHost)
                (static_cast<Host *>(gsck))->gameNext(netSelectPlayer, i);
            else
                (static_cast<Client *>(gsck))->gameNext(netSelectPlayer, i);
        }
    } else {
        if ((getCpt() < game->getPlayers().size()) || waitNextRound)
            return;
        indc = i;
        disableCards();
        Card::typeCard type = game->getPlayers().at(indp).getCards().at(indc).getType() ;
        setCardImg(cards[i],type,false);
        keep() ;
    }
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

void MainWindow::on_boardQuit_clicked()
{
    ui->menu->setCurrentWidget(ui->start);
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
    if (net) {
        ui->hostPort->setText(QString::fromStdString(to_string(atoi(ui->hostPort->text().toStdString().c_str()) + 1)));
        ui->clientPort->setText(QString::fromStdString(to_string(atoi(ui->clientPort->text().toStdString().c_str()) + 1)));
        on_playNetwork_clicked();
    } else
        on_playB_clicked();
}



/* ---------- NETWORK ---------- */

void MainWindow::on_playNetwork_clicked ()
{
    ui->menu->setCurrentWidget(ui->networkMenu);
    ui->hostMess->hide();
    ui->clientMess->hide();
    ui->networkHostGo->setEnabled(true);
    ui->networkJoinGo->setEnabled(true);
}

void MainWindow::on_networkMenuBack_clicked ()
{
    ui->menu->setCurrentWidget(ui->start);
}

void MainWindow::on_networkHostGo_clicked ()
{
    // GO HOST
    networkGO(true);
}

void MainWindow::on_networkJoinGo_clicked ()
{
    // GO JOIN
    networkGO(false);
}

/* void MainWindow::signalHelper (GSocket::gstate &gst) { */
/*     emit net */

/* } */

MainWindow *mw = nullptr;

void tchatCallback (const GSocket::gmess &mess)
{
    emit mw->signalTchatCb(mess);
}

void gameCallback (GSocket::gstate &gst)
{
    emit mw->signalCb(gst);
}

void MainWindow::netTchatCb (GSocket::gmess gm)
{
    QString html ("\n<b>");
    html += QString::fromStdString(gm.player);
    html += "</b>: ";
    html += QString::fromStdString(gm.mess);
    ui->tchatArea->setHtml(ui->tchatArea->toHtml() + html);
}

void MainWindow::netCb (GSocket::gstate gst)
{
    netGst = gst;
    if (ui->menu->currentWidget() != ui->board) {
        // first time
        ui->menu->setCurrentWidget(ui->board);

        std::vector<QString> psds;
        for (size_t i = 0; i < gst.oPlayers.size(); i ++)
            psds.push_back(QString::fromStdString(gst.oPlayers.at(i)));
        setTable(psds);
        ui->pseudo->setText(QString::fromStdString(gst.pseudo).toUpper());
        ui->pseudo->show();
        ui->tchatArea->show();
        ui->tchatInput->show();
        ui->tchatSend->show();
        ui->hostMess->hide();
        ui->clientMess->hide();
    }

    if (netReveal)
        return;

    QPixmap pixm(":fin_mori.png");
    QPixmap pixs(":fin_sherlock.png");
    int w = pixm.width();
    int h = pixm.height();

    switch (gst.gameState) {
        case Game::MoriartyWin:
            ui->menu->setCurrentWidget(ui->fin);
            ui->fin_img->setPixmap(pixm.scaled(w,h,Qt::KeepAspectRatio));
            if (fr)
                ui->winner->setText("BOOOOOM !! Moriarty a gagné !");
            else
                ui->winner->setText("BOOOOOM !! Moriarty has won !");

            if (netHost)
                (static_cast<Host *>(gsck))->~Host();
            else
                (static_cast<Client *>(gsck))->~Client();
            return;

        case Game::SherlockWin:
            ui->menu->setCurrentWidget(ui->fin);
            ui->fin_img->setPixmap(pixs.scaled(w,h,Qt::KeepAspectRatio));
            if (fr)
                ui->winner->setText("Oui !! Sherlock a gagné !");
            else
                ui->winner->setText("Yeaah !! Sherlock has won !");

            if (netHost)
                (static_cast<Host *>(gsck))->~Host();
            else
                (static_cast<Client *>(gsck))->~Client();
            return;

        case Game::Active:
            break;
    }

    netIsCur = false;
    ui->defusing->display(gst.nbDefusingFound);
    ui->round->display(gst.round);

    // game active

    // normal

    if (netOldRound > 0) {
        if (gst.currentPlayer == gst.pseudo)
            netIsCur = true;
        netShowPlayers();
        netSetCurRole();
        if (netFirstReveal) {
            netHideCards();
            netFirstReveal = false;
            QString txt ("");
            if (fr)
                txt.append("Au tour de ");
            else
                txt.append("Turn of ");
            txt.append(QString::fromStdString(gst.currentPlayer).toUpper());
            ui->status->setText(txt);

        } else {
            netShowCardsWithRevealed();
            netDisableCards();
            string typ (typec2str(gst.lastCardRevealed));
            QString txt (QString::fromStdString(typ));
            if (fr)
                txt.append(" ! Au tour de ");
            else
                txt.append(" ! Turn of ");
            txt.append(QString::fromStdString(gst.currentPlayer).toUpper());
            ui->status->setText(txt);
        }
    }

    if (netOldRound < gst.round) {
        if (netOldRound == 0)
            on_viewCards_clicked();
        else
            ui->viewCards->show();
        netOldRound = gst.round;
        netHidePlayers();
    }

    netLastCurrentPlayer = gst.currentPlayer;
}

void MainWindow::netHideCards ()
{
    for  (size_t i = 0; i < 5; i ++)
        cards[i]->hide();
}

void MainWindow::netDisableCards ()
{
    for (size_t i = 0; i < 5; i ++)
        cards[i]->setEnabled(false);
}

void MainWindow::netEnableCards ()
{
    for (size_t i = 0; i < 5; i ++)
        cards[i]->setEnabled(true);
}

void MainWindow::netShowPlayerCards (string pseudo)
{
    size_t nbc = 0;
    for (size_t i = 0; i < netGst.oPlayers.size(); i ++) {
        if (pseudo == netGst.oPlayers[i]) {
            nbc = netGst.oNbCards[i];
            break;
        }
   }

   for (size_t i = 0; i < nbc; i ++) {
       setCardImg(cards[i], Card::Safe, true);
       cards[i]->show();
   }
   for (size_t i = nbc; i < 5; i ++)
       cards[i]->hide();

}

void MainWindow::netShowMyCards ()
{
    netReveal = true;
    vector<Card::typeCard> temp = netGst.cards ;
    size_t nbc = temp.size();
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(temp.begin(), temp.end(), default_random_engine(seed));

    for (size_t i = 0; i < nbc; i ++) {
        setCardImg(cards[i], temp[i], false);
        cards[i]->show();
    }
    for (size_t i = nbc; i < 5; i ++)
        cards[i]->hide();
}

void MainWindow::netSetCurRole ()
{
        ui->role->setStyleSheet("background-image: url(:tb9.png); border-image: url(:tb9.png) 0 0 0 0 stretch; background-image:no-repeat;");
        ui->name->setText(QString::fromStdString(netGst.currentPlayer).toUpper());
        ui->role->show();
        ui->name->show();
}

void MainWindow::netShowPlayers ()
{
    for (size_t i = 0; i < netGst.oPlayers.size(); i ++)
        players[i]->show();
}

void MainWindow::netSetMyRole ()
{
    switch(netGst.role)
    {
        case Player::Moriarty:
            ui->role->setStyleSheet("background-image: url(:tb6.png); border-image: url(:tb6.png) 0 0 0 0 stretch; background-image:no-repeat;");
            break;

        case Player::Sherlock:
            ui->role->setStyleSheet("background-image: url(:tb1.png); border-image: url(:tb1.png) 0 0 0 0 stretch; background-image:no-repeat;");
            break;
    }
    ui->name->setText(QString::fromStdString(netGst.pseudo).toUpper());
    ui->role->show();
    ui->name->show();
}

void MainWindow::netHidePlayers ()
{
    for (size_t i = 0; i < netGst.oPlayers.size(); i ++)
        players[i]->hide();
}

void MainWindow::netShowCardsWithRevealed ()
{
    size_t nbc = netGst.oNbCards[0];
    if (netLastCurrentPlayer == netGst.pseudo)
        nbc = netLastRevealNbCards;
    if (nbc < 1)
        nbc = 1;
    int r = rand() % nbc;
    if (netLastCurrentPlayer ==  netGst.pseudo)
        r = netLastRevealIndCard;
    for (size_t i = 0; i < nbc; i ++) {
        if (i == static_cast<size_t>(r))
            setCardImg(cards[i], netGst.lastCardRevealed, false);
        else
            setCardImg(cards[i], Card::Safe, true);
        cards[i]->show();
    }

    for (size_t i = nbc; i < 5; i ++)
        cards[i]->hide();
}

void MainWindow::networkGO (const bool host)
{
    netLastRevealNbCards = 0;
    netLastRevealIndCard = 0;
    netLastCurrentPlayer = "";
    netSelectPlayer = "";
    netOldRound = 0;
    netReveal = false;
    netFirstReveal = true;
    netIsCur = false;
    net = true;
    waitNextRound = false;
    netHost = host;
    mw = this;
    ui->boardQuit->hide();

    for (size_t i = 0; i < 5; i ++)
        cards[i]->setEnabled(true);
    for (size_t i = 0; i < 8; i ++)
        players[i]->setEnabled(true);

    qRegisterMetaType<GSocket::gstate>();
    qRegisterMetaType<GSocket::gmess>();
    connect(this, SIGNAL(signalCb(GSocket::gstate)), this, SLOT(netCb(GSocket::gstate)));
    connect(this, SIGNAL(signalTchatCb(GSocket::gmess)), this, SLOT(netTchatCb(GSocket::gmess)));

    if (netHost) {
        // HOST
        const QString port (ui->hostPort->text());
        const QString pseudo (ui->hostPseudo->text());
        const int nbPlayers = ui->hostPlayers->value();
        if (port.isEmpty() || pseudo.isEmpty())
        {
            QMessageBox msgBox;
            if (fr)
                msgBox.setText("Veuillez rentrer les informations demandées");
            else
                msgBox.setText("Please enter asked informations");
            msgBox.exec();
            return;
        }
        string pseudoSafe = pseudo.toStdString();
        pseudoSafe.erase(std::remove(pseudoSafe.begin(), pseudoSafe.end(), ':'), pseudoSafe.end());

        cout << "[NET] Attente de la connexion de tous les joueurs ..." << endl;
        ui->hostMess->show();
        ui->networkHostGo->setEnabled(false);
        ui->networkJoinGo->setEnabled(false);
        gsck = new Host(pseudoSafe, nbPlayers - 1, atoi(port.toStdString().c_str()), gameCallback, tchatCallback);

    } else {
        // CLIENT
        const QString ip (ui->clientIp->text());
        const QString port (ui->clientPort->text());
        const QString pseudo (ui->clientPseudo->text());
        if (ip.isEmpty() || port.isEmpty() || pseudo.isEmpty())
        {
            QMessageBox msgBox;
            if (fr)
                msgBox.setText("Veuillez rentrer les informations demandées");
            else
                msgBox.setText("Please enter asked informations");
            msgBox.exec();
            return;
        }
        string pseudoSafe = pseudo.toStdString();
        pseudoSafe.erase(std::remove(pseudoSafe.begin(), pseudoSafe.end(), ':'), pseudoSafe.end());
        cout << "[NET] Connexion au serveur et attente de lancement ..." << endl;
        ui->clientMess->show();
        ui->networkHostGo->setEnabled(false);
        ui->networkJoinGo->setEnabled(false);
        gsck = new Client(pseudoSafe, ip.toStdString().c_str(), atoi(port.toStdString().c_str()), gameCallback, tchatCallback);
    }
}

void MainWindow::on_tchatSend_clicked ()
{
    string str = ui->tchatInput->text().toStdString();
    ui->tchatInput->clear();
    str.erase(std::remove(str.begin(), str.end(), ':'), str.end());

    GSocket::gmess mess;
    mess.player = netGst.pseudo;
    mess.mess = str;
    mess.time = time(NULL);

    if (netHost)
        (static_cast<Host *>(gsck))->sendTchatMess(mess);
    else
        (static_cast<Client *>(gsck))->sendTchatMess(mess);
}

/* ---------- TRADUCTIONS ---------- */

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
    ui->viewCards->setText("View Cards");
    ui->roundNext->setText("Continue");
    ui->tchatSend->setText("Send");
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
    ui->viewCards->setText("Voir mes cartes");
    ui->roundNext->setText("Continuer");
    ui->tchatSend->setText("Envoyer");
}

void MainWindow::on_eng_trad_clicked()
{
   english();
}

void MainWindow::on_fr_trad_clicked()
{
    french();
}
