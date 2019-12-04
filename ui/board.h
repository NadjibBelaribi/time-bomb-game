#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "kernel/Game.h"

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = 0,std::vector <QString> pseudos = std::vector <QString> ());
    void setTable( std::vector <QString> psds ) ;
    void printBeginMess ( ) ;
    void  hideCards() ;
    void  showCards(size_t i) ;
    string type2str(Player p) ;
    string typec2str(Card c) ;
    size_t getCpt();
    void setCpt(size_t cpt);
    void keep () ;
    void printCardRevealed (const Card::typeCard &type) ;
    void afficheCard(size_t j);
    int indp = -1 ;
    int indc = -1 ;
    ~Board();

private slots:
    void on_player1_clicked();
    void on_player2_clicked();
    void on_player3_clicked();
    void on_player4_clicked();
    void on_player5_clicked();
    void on_player6_clicked();
    void on_player7_clicked();
    void on_player8_clicked();


    void on_backOptions_clicked();

    void on_card1_clicked();

    void on_card2_clicked();

    void on_card3_clicked();

    void on_card4_clicked();

    void on_card5_clicked();

private:
    Game *game ;
    size_t cpt;
    Ui::Board *ui;

};

#endif // BOARD_H
