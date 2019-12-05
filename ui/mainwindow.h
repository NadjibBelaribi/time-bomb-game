#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLineEdit>
#include <QString>
#include <QGridLayout>
#include <QMessageBox>
#include <string.h>
#include <QDebug>
#include <unistd.h>
#include <QPixmap>
#include <QVector>
#include <vector>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <string>
#include "../kernel/headers/Game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int indp = -1 ;
    int indc = -1 ;

    void keep ();

    void setCpt(size_t cpt);

    string typec2str(Card c);

    string type2str(Player p);

    void hideWithoutI(size_t i);

   void RemoveLayout (QGridLayout* widget);

    size_t getCpt();

    std::vector <QString> getPseudo();

    void hideCards();
    void setTable( std::vector <QString> psds );

    void afficheCard(size_t j);


    void showCards(size_t i);

    void printBeginMess ();

    void printCardRevealed (const Card::typeCard &type);

    void blockPlayerCourant (Player p);

private slots:

    void on_playB_clicked();

    void on_back_clicked();

    void on_nb4_clicked();

    void on_nb5_clicked();

    void on_nb6_clicked();

    void on_nb7_clicked();

    void on_nb8_clicked();

    void on_go_clicked();

    void on_backOptions_clicked();

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

private:
    Ui::MainWindow *ui;
    Game *game ;
    size_t cpt;
    std::vector <QLineEdit*> hello;
    std::vector <QString> pseudos;
    std::vector <bool> reveals;
};

#endif // MAINWINDOW_H
