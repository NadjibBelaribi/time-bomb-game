#include <iostream>
#include <cstdlib>
#include "../headers/Game.h"
using namespace std;

#define COL_NORMAL "\x1B[0m"
#define COL_GREEN "\x1B[32m"
#define COL_RED "\x1B[31m"
#define COL_CYAN "\x1B[36m"
#define COL_YELLOW "\x1B[33m"

Card & askForCard (Game &game);
void printBeginMess (const Game &game);
void printCardRevealed (const Card::typeCard &type);
void printEndTeams (Game &game);

int main (int argc, char **argv) {
    if ((argc < 5) || (argc > 9)) {
        cerr << "Utilisation: <pseudo1> ... <pseudoN> (de 4 à 8 joueurs)\n" << endl;
        exit(1);
    }
    const size_t nbPlayers = argc - 1;
    string *pseudos = new string [nbPlayers];
    for (unsigned i = 0; i < nbPlayers; i ++)
        pseudos[i] = string(argv[i + 1]);


    Game game = Game(nbPlayers, pseudos);
    Game::stateGame state;
    cout << COL_YELLOW " === DEBUT DU JEU === (" << nbPlayers << " joueurs)" COL_NORMAL << endl;

    do {
        printBeginMess(game);
        printCardRevealed(game.next(askForCard(game)));
    } while ((state = game.getState()) == Game::Active);

    if (state == Game::MoriartyWin)
        cout << COL_RED "\nEND - Moriarty team wins !" COL_NORMAL << endl;
    else
        cout << COL_CYAN "\nEND - Sherlock team wins !" COL_NORMAL << endl;

    printEndTeams(game);
    cout << COL_YELLOW " === FIN DU JEU === " COL_NORMAL << endl;
    return 0;
}

Card & askForCard (Game &game) // SANS LE JOUEUR DU TOUR ACTUEL
{
    cout << "À quel joueur dévoiler une carte ? ";
    vector<Player *> players = game.getPlayersForRevealingCard();
    const size_t nbPlayers = players.size();
    unsigned i = 1;

    for (vector<Player *>::iterator it = players.begin(); it != players.end(); it ++, i ++) {
        cout << (**it).getPseudo() << "(" << i << ")";
        if (i < nbPlayers)
            cout << ", ";
    }
    cout << ": ";
    bool first = true;
    do {
        if (!first)
            cout << COL_RED "Numéro incorrect. Réessayez: " COL_NORMAL;
        first = false;
        cin >> i;
    } while ((i < 1) || (i > nbPlayers));

    Player *player = players.at(i - 1);
    vector<Card> &cards = player->getCards();
    const size_t nbCards = cards.size();
    cout << "Quelle carte dévoiler du joueur " << player->getPseudo() << " ? (1-" << nbCards << "): ";

    first = true;
    do {
        if (!first)
            cout << COL_RED "Numéro incorrect. Réessayez: " COL_NORMAL;
        first = false;
        cin >> i;
    } while ((i < 1) || (i > nbCards));

    return cards.at(i - 1);
}

void printBeginMess (const Game &game)
{
    cout << "\nROUND " << COL_YELLOW << game.getRound() << COL_NORMAL << ", NB DEFUSING FOUND: " COL_CYAN << game.getNbDefusingCardsRevealed() << COL_NORMAL "\nTour de: " << COL_YELLOW << game.getCurrentPlayer().getPseudo() << COL_NORMAL << " !" << endl;
}

void printCardRevealed (const Card::typeCard &type)
{
    cout << "La carte révélée est: ";
    switch (type) {
        case Card::Safe:
            cout << COL_GREEN "Inutile, carte SAFE." COL_NORMAL << endl;
            break;
        case Card::Defusing:
            cout << COL_CYAN "Utile, carte DEFUSING !" COL_NORMAL << endl;
            break;
        case Card::Bomb:
            cout << COL_RED "Mortelle, carte BOOOMB !!!" COL_NORMAL << endl;
    }
}

void printEndTeams (Game &game)
{
    vector<Player> &players = game.getPlayers();
    cout << endl << COL_RED << "Team Moriarty: ";
    for (vector<Player>::iterator it = players.begin(); it != players.end(); it ++) {
        if ((*it).getRole() == Player::Moriarty)
            cout << (*it).getPseudo() << " ";
    }
    cout << endl << COL_CYAN << "Team Sherlock: ";
    for (vector<Player>::iterator it = players.begin(); it != players.end(); it ++) {
        if ((*it).getRole() == Player::Sherlock)
            cout << (*it).getPseudo() << " ";
    }

    cout << COL_NORMAL << endl;
}
