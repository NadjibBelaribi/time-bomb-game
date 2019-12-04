#include <iostream>
#include <cstdlib>
#include "../../network/headers/GSocket.h"
#include "../../network/headers/Host.h"
#include "../../network/headers/Client.h"

using namespace std;

#define COL_NORMAL "\x1B[0m"
#define COL_GREEN "\x1B[32m"
#define COL_RED "\x1B[31m"
#define COL_CYAN "\x1B[36m"
#define COL_YELLOW "\x1B[33m"

void tchatCallback (const GSocket::gmess &mess);
void gameCallback (GSocket::gstate &gst);
void host (const char *portRaw, const char *nbPlayersRaw, const char *pseudoRaw);
void client (const char *ip, const char *portRaw, const char *pseudoRaw);
void askCard (GSocket::gstate &gst);
void printBeginMess (const GSocket::gstate &gst);
void printCardRevealed (const GSocket::gstate &gst);
void printRole (const GSocket::gstate &gst);
void printEndTeams (GSocket::gstate &gst);
void printMyCards (GSocket::gstate &gst);

bool isHost;
GSocket *gsck;
bool first = true;
unsigned lastRound = 0;

/* *** ATTENTION ***
 * => Les fonctions de callback tchatCallback et gameCallback sont appelées depuis des threads générés par Hote ou Client !!!!!!!
 * => Ne pas bloquer ces fonctions
 */

int main (int argc, char **argv) {
    if ((argc != 5) || ((argc >= 2) && (strcmp(argv[1], "host") != 0) && (strcmp(argv[1], "join") != 0))) {
        cerr << "Utilisation:\n\thost <port> <nb_players> <pseudo>\n\tjoin <ip> <port> <pseudo>" << endl;
        exit(1);
    }

    isHost = strcmp(argv[1], "host") == 0; // si client, alors = false
    if (isHost)
        host(argv[2], argv[3], argv[4]);
    else
        client(argv[2], argv[3], argv[4]);

    while (1)
        sleep(0.2);
    return 0;
}

void host (const char *portRaw, const char *nbPlayersRaw, const char *pseudoRaw)
{
    const string pseudo (pseudoRaw);
    const size_t nbPlayers = atoi(nbPlayersRaw);
    const in_port_t port = atoi(portRaw);

    if ((nbPlayers < 4) || (nbPlayers > 8)) {
        cerr << "Le nombre de joueurs doit être compris entre 4 et 8" << endl;
        exit(1);
    }
    printf("Attente de la connexion de tous les joueurs ...\n");
    gsck = new Host(pseudo, nbPlayers - 1, port, gameCallback, tchatCallback);
}

void client (const char *ip, const char *portRaw, const char *pseudoRaw)
{
    const string pseudo (pseudoRaw);
    const size_t port = atoi(portRaw);
    gsck = new Client(pseudo, ip, port, gameCallback, tchatCallback);
    printf("Connexion au serveur et attente de lancement ...\n");
}

void tchatCallback (const GSocket::gmess &mess)
{
    cout << "\t[TCHAT] " << mess.player << ": " << mess.mess << endl;
}

void gameCallback (GSocket::gstate &gst)
{
    if (first)
        printRole(gst);
    if (gst.round > lastRound)
        printMyCards(gst);
    if (!first)
        printCardRevealed(gst);
    printBeginMess(gst);

    first = false;
    if (gst.gameState == Game::MoriartyWin) {
        cout << COL_RED "\nEND - Moriarty team wins !" COL_NORMAL << endl;
        printEndTeams(gst);
        exit(0);
    } else if (gst.gameState == Game::SherlockWin) {
        cout << COL_CYAN "\nEND - Sherlock team wins !" COL_NORMAL << endl;
        printEndTeams(gst);
        exit(0);
    }

    if (gst.currentPlayer == gst.pseudo) // CEST MON TOUR !
        askCard(gst);
    // else PAS MON TOUR

    lastRound = gst.round;
}

void askCard (GSocket::gstate &gst)
{
    cout << "À quel joueur dévoiler une carte ? ";
    unsigned i = 1;
    for (vector<string>::iterator it = gst.oPlayers.begin(); it != gst.oPlayers.end(); it ++, i ++) {
        cout << (*it) << "(" << i << ")";
        if (i < gst.oPlayers.size())
            cout << ", ";
    }
    cout << ": ";
    bool first = true;
    do {
        if (!first)
            cout << COL_RED "Numéro incorrect. Réessayez: " COL_NORMAL;
        first = false;
        cin >> i;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while ((i < 1) || (i > gst.oPlayers.size()));

    string &player = gst.oPlayers.at(i - 1);
    const size_t nbCards = gst.oNbCards.at(i - 1);
    cout << "Quelle carte dévoiler du joueur " << player << " ? (1-" << nbCards << "): ";

    first = true;
    do {
        if (!first)
            cout << COL_RED "Numéro incorrect. Réessayez: " COL_NORMAL;
        first = false;
        cin >> i;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while ((i < 1) || (i > nbCards));

    if (isHost)
        (static_cast<Host *>(gsck))->gameNext(player, i - 1);
    else
        (static_cast<Client *>(gsck))->gameNext(player, i - 1);
}


void printBeginMess (const GSocket::gstate &gst)
{
    cout << "\nROUND " << COL_YELLOW << to_string(gst.round) << "/4" << COL_NORMAL << ", NB DEFUSING FOUND: " COL_CYAN << to_string(gst.nbDefusingFound) << "/" << to_string(gst.oPlayers.size() + 1) << COL_NORMAL "\nTour de: " << COL_YELLOW << gst.currentPlayer << COL_NORMAL << " !" << endl;
}

void printCardRevealed (const GSocket::gstate &gst)
{
    cout << "La carte révélée est: ";
    switch (gst.lastCardRevealed) {
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

void printRole (const GSocket::gstate &gst)
{
    cout << " => J'ai le rôle: ";
    if (gst.role == Player::Sherlock)
        cout << COL_CYAN << "Sherlock";
    else
        cout << COL_RED << "Moriarty";
    cout << COL_NORMAL << endl;
}

void printEndTeams (GSocket::gstate &gst)
{
    cout << endl << COL_RED << "Team Moriarty: ";
    unsigned i = 0;
    for (vector<string>::iterator it = gst.oPlayers.begin(); it != gst.oPlayers.end(); it ++, i ++) {
        if (gst.oRoles.at(i) == Player::Moriarty)
            cout << *it << " ";
    }
    if (gst.role == Player::Moriarty)
        cout << gst.pseudo << " ";

    i = 0;
    cout << endl << COL_CYAN << "Team Sherlock: ";
    for (vector<string>::iterator it = gst.oPlayers.begin(); it != gst.oPlayers.end(); it ++, i ++) {
        if (gst.oRoles.at(i) == Player::Sherlock)
            cout << *it << " ";
    }
    if (gst.role == Player::Sherlock)
        cout << gst.pseudo << " ";

    cout << COL_NORMAL << endl;
}

void printMyCards (GSocket::gstate &gst)
{
    cout << COL_YELLOW << "Nouvelle ROUND, mes cartes: " COL_NORMAL;
    bool first = true;
    for (vector<Card::typeCard>::iterator it = gst.cards.begin(); it != gst.cards.end(); it ++) {
        if (!first)
            cout << ", ";
        first = false;
        switch (*it) {
            case Card::Safe:
                cout << COL_GREEN << "Safe" << COL_NORMAL;
                break;
            case Card::Defusing:
                cout << COL_CYAN << "Defusing" << COL_NORMAL;
                break;
            case Card::Bomb:
                cout << COL_RED << "Bomb" << COL_NORMAL;
        }
    }

    cout << endl;
}
