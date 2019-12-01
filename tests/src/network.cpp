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

void printBeginMess (const Game &game, const size_t nbPlayers);
void printCardRevealed (const Card::typeCard &type);
void printEndTeams (Game &game);
void askCard (GSocket::gstate &gst);

bool isHost;
GSocket *gsck;

void tchatCallback (const GSocket::gmess &mess)
{
    cout << "\t[TCHAT] " << mess.player << ": " << mess.mess << endl;
}

void gameCallback (GSocket::gstate &gst)
{
    switch (gsck->getState()) {
        case GSocket::Waiting:
            cout << " [STATE] Waiting.\n";
            break;
        case GSocket::Playing:
            cout << " [STATE] Playing.\n";
            break;
        case GSocket::End:
            cout << " [STATE] End." << endl;
            exit(0);
            break;
    }

    printf("La carte trouvée est: ");
    switch (gst.lastCardRevealed) {
        case Card::Safe:
            cout << "SAFE";
            break;
        case Card::Defusing:
            cout << "DEFUSING";
            break;
        case Card::Bomb: // BOMB
            cout << "BOMB";
            break;
        default:
            cerr << "gamePlaying: unknow type of card" << endl;
            exit(1);
    }

    cout << "\nAu tour de: " << gst.currentPlayer << "\t(Nb defusing found = " << gst.nbDefusingFound << ")\n";
    if (gst.currentPlayer == gsck->getPseudo()) { // CEST MON TOUR !
        cout << "cest A MOI de jouer" << endl;
        askCard(gst);
    } else { // PAS MON TOUR
        cout << "cest pas a moi de jouer" << endl;
    }
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
    gsck = new Host(pseudo, nbPlayers - 1, port, gameCallback, tchatCallback);
    printf("Attente de la connexion de tous les joueurs ...\n");
}

void client (const char *ip, const char *portRaw, const char *pseudoRaw)
{
    const string pseudo (pseudoRaw);
    const size_t port = atoi(portRaw);
    gsck = new Client(pseudo, ip, port, gameCallback, tchatCallback);
    printf("Connexion au serveur et attente de lancement ...\n");
}

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
        sleep(1);
    return 0;
}

void askCard (GSocket::gstate &gst)
{
    cout << "À quel joueur dévoiler une carte ? ";
    unsigned i = 1;
    for (vector<string>::iterator it = gst.players.begin(); it != gst.players.end(); it ++, i ++) {
        cout << (*it) << "(" << i << ")";
        if (i < gst.players.size())
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
    } while ((i < 1) || (i > gst.players.size()));

    string &player = gst.players.at(i - 1);
    const size_t nbCards = 6 - gst.round;
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
