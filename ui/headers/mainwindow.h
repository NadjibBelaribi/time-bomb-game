#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QSpinBox>
#include <QMetaType>
#include <QLineEdit>
#include <QString>
#include <QGridLayout>
#include <QMessageBox>
#include <string.h>
#include <QDebug>
#include <unistd.h>
#include <QPixmap>
#include <QVector>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <string>
#include <cctype>
#include <cwctype>
#include <algorithm>
#include "../../kernel/headers/Game.h"
#include "../../network/headers/GSocket.h"
#include "../../network/headers/Host.h"
#include "../../network/headers/Client.h"

namespace Ui {
    class MainWindow;
}

Q_DECLARE_METATYPE(GSocket::gstate);
Q_DECLARE_METATYPE(GSocket::gmess);

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        int indp = -1 ;
        int indc = -1 ;

        void keep ();

        void setCardImg(QPushButton *but , Card::typeCard type ,bool cache) ;

        bool caseInsCompare(const string& s1, const string& s2);

        bool caseInsCompare(const wstring& s1, const wstring& s2);


        bool same(vector <QString> psd);

        void setCpt(size_t cpt);

        string typec2str(Card::typeCard tc);

        void hideWithoutI(size_t i);

        void RemoveLayout (QGridLayout* widget);
        void enableCards() ;
        void disableCards() ;

        void showPlayers();

        size_t getCpt();

        void english();

        void french();

        std::vector <QString> getPseudo();

        void hideCards();
        void setTable( std::vector <QString> psds );

        void afficheCard(size_t j);

        void hidePlayer (const size_t i);

        void showCards(size_t i);

        void printCardRevealed (const Card::typeCard &type);

        void blockPlayerCourant (Player p);

        char file[12][75]={":timeBomb1.svg"
            ,":timeBomb2.svg"
                ,":timeBomb3.svg"
                ,":timeBomb4.svg"
                ,":timeBomb5.svg"
                ,":timeBomb6.svg"
                ,":timeBomb7.svg"
                ,":timeBomb8.svg"
                ,":timeBomb9.svg"
                ,":timeBomb10.svg"
                ,":timeBomb11.svg"
                ,":timeBomb12.svg"};

        int i=0;

        void initPseudoFields (const size_t n);

        void playerClicked (const size_t i);

        void cardClicked (const size_t i);

        bool fr = true;

private slots:

        void on_playB_clicked();

        void on_back_clicked();

        void on_nb4_clicked();

        void on_nb5_clicked();

        void on_nb6_clicked();

        void on_nb7_clicked();

        void on_nb8_clicked();

        void on_go_clicked();

        void on_card1_clicked();

        void on_card2_clicked();

        void on_card3_clicked();

        void on_card4_clicked();

        void on_card5_clicked();

        void on_player1_clicked();
        void on_player2_clicked();
        void on_player3_clicked();
        void on_player4_clicked();
        void on_player5_clicked();
        void on_player6_clicked();
        void on_player7_clicked();
        void on_player8_clicked();

        void on_help_clicked();


        void on_leave_clicked();

        void on_leave_menu_clicked();

        void on_Previous_clicked();

        void on_next_clicked();

        void on_backfromhelp_clicked();

        void on_replay_clicked();

        void on_roundNext_clicked ();

        // NETWORK

        void on_playNetwork_clicked ();

        void on_networkMenuBack_clicked ();

        void on_networkHostGo_clicked ();

        void on_networkJoinGo_clicked ();

        void on_viewCards_clicked ();

        void networkGO (const bool host);

        void on_tchatSend_clicked ();

        // TRADUCTIONS

        void on_eng_trad_clicked();

        void on_fr_trad_clicked();

public slots:
        void netCb (GSocket::gstate gst);
        void netTchatCb (GSocket::gmess gm);

signals:
        Q_SIGNAL void signalCb (GSocket::gstate);
        Q_SIGNAL void signalTchatCb (GSocket::gmess);

private:
        Ui::MainWindow *ui;
        Game *game ;
        size_t cpt;
        std::vector <QLineEdit*> hello;
        std::vector <QString> pseudos;
        std::vector <bool> reveals;
        QPushButton **players;
        QPushButton **cards;
        bool waitNextRound = false;

        // only for netw
        bool net = false;
        bool netHost = false;
        GSocket *gsck = nullptr;
        GSocket::gstate netGst;
        bool netReveal = false;
        size_t netOldRound = 0;
        bool netIsCur = false;
        string netSelectPlayer = "";
        bool netFirstReveal = true;
        size_t netLastRevealNbCards = 0;
        size_t netLastRevealIndCard = 0;
        string netLastCurrentPlayer = "";

        void netShowPlayerCards (string pseudo);
        void netShowMyCards ();
        void netShowPlayers ();
        void netSetCurRole ();
        void netSetMyRole ();
        void netHidePlayers ();
        void netShowCardsWithRevealed ();
        void netHideCards ();
};

#endif // MAINWINDOW_H
