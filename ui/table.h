#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include"mainwindow.h"
#include"../kernel/headers/Game.h"
#include"../kernel/headers/Player.h"
#include"../kernel/headers/Card.h"

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0,std::vector <QString> pseudos = std::vector <QString> () );
    void startGame( std::vector <QString> pseudos) ;
    void printBeginMess (const Game &game, const size_t nbPlayers)  ;
    void showLayout(QGridLayout *layout) ;
    void hideLayout(QGridLayout *layout) ;
    explicit Table(QWidget *parent = 0);
    ~Table();

public slots:
    void showPCards()  ;

private slots:
    void on_backOptions_clicked();

public :
    Player* p;
    size_t r;

private:
    Ui::Table *ui;


};

#endif // TABLE_H
