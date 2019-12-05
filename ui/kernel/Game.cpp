#include "Game.h"

Game::Game (const size_t nbPlayers, const string *pseudos)
{
    if (nbPlayers > 8) {
        cerr << "Players number should be < 8\n";
        exit(1);
    } else if (nbPlayers < 4) {
        cerr << "Players number should be > 4\n";
        exit(1);
    }

    srand(time(NULL));
    size_t nbMoriarty = this->initialNbMoriarty(nbPlayers);
    size_t nbSherlock = nbPlayers - nbMoriarty;
    size_t nbSafeCards = this->initialNbSafeCards(nbPlayers);
    size_t nbDefusingCards = nbPlayers;
    size_t nbBombCards = 1;
    Player::rolePlayer role;
    Card::typeCard randCardType;
    vector<Card> cards;

    for (unsigned i = 0; i < nbPlayers; i ++) {
        cards.clear();
        for (unsigned j = 0; j < 5; j ++) {
            randCardType = this->genRandCardType(nbSafeCards, nbDefusingCards, nbBombCards);
            cards.push_back(Card(randCardType,false));
        }

        role = this->genRandPlayerRole(nbMoriarty, nbSherlock);
        this->players.push_back(Player(pseudos[i], role, cards, false));
    }

    this->currentPlayer = &this->players.at(rand() % this->players.size());
    this->state = Game::Active;
    this->round = 1;
    this->nbRoundCardsRevealed = 0;
    this->nbDefusingCardsRevealed = 0;
}

size_t Game::initialNbMoriarty (const size_t nbPlayers) const
{
    if (nbPlayers >= 7)
        return 3;
    else
        return 2;
}

size_t Game::initialNbSafeCards (const size_t nbPlayers) const
{
    return 15 + (nbPlayers - 4) * 4;
}

Card::typeCard Game::genRandCardType (size_t &nbSafeCards, size_t &nbDefusingCards, size_t &nbBombCards) const
{
    const size_t sum = nbSafeCards + nbDefusingCards + nbBombCards;
    const size_t random = rand() % sum + 1;

    if (random <= nbSafeCards) {
        nbSafeCards --;
        return Card::Safe;
    } else if (random <= (nbSafeCards + nbDefusingCards)) {
        nbDefusingCards --;
        return Card::Defusing;
    } else {
        nbBombCards --;
        return Card::Bomb;
    }
}

Player::rolePlayer Game::genRandPlayerRole (size_t &nbMoriarty, size_t &nbSherlock) const
{
    const size_t sum = nbMoriarty + nbSherlock;
    const size_t random = rand() % sum + 1;

    if (random <= nbMoriarty) {
        nbMoriarty --;
        return Player::Moriarty;
    } else {
        nbSherlock --;
        return Player::Sherlock;
    }
}

Player & Game::getCurrentPlayer () const
{
    return *this->currentPlayer;
}

unsigned Game::getRound () const
{
    return this->round;
}

Game::stateGame Game::getState () const
{
    return this->state;
}

Card::typeCard Game::next (int indp ,int indc)
{
    if (this->state != Game::Active) {
        cerr << "[Error] next: this->state != Game::Active" << endl;
        exit(1);
    }

    Player *cardOwner = &this->getPlayers().at(indp-1) ;
    const Card card = cardOwner->getCards().at(indc-1) ;

    if (cardOwner == nullptr) {
        cerr << "[Error] next: cardOwner == nullptr" << endl;
        exit(1);
    }
    if (cardOwner == this->currentPlayer) {
        cerr << "[Error] next: cardOwner == this->currentPlayer" << endl;
        exit(1);
    }

    switch (card.getType()) {
        case Card::Bomb:
            this->state = Game::MoriartyWin;
            return card.getType();
        case Card::Defusing:
            this->nbDefusingCardsRevealed ++;
            if (this->nbDefusingCardsRevealed == this->players.size()) {
                this->state = Game::SherlockWin;
                return card.getType();
            }
            break;
        default:
            break;
    };

    this->nbRoundCardsRevealed ++;
    if (this->nbRoundCardsRevealed == this->players.size()) {
        if (this->round == 4) {
            this->state = Game::MoriartyWin;
            return card.getType();
        } else
        {
            cardOwner->getCards().erase(cardOwner->getCards().begin() + (indc - 1 ));
            cout << "Bonjour" ;
            cout <<  cardOwner->getCards().size() << endl;
            this->currentPlayer = cardOwner;
            this->nextRound();
            for(int i = 0 ; i < this->getPlayers().size() ; i++) {
                            for(int j = 0 ; j < this->getPlayers().size() ; j++)
                            {string mm;

                                    switch(this->getPlayers().at(i).getCards().at(j).getType()){
                                             case Card::Safe:
                                                mm = "Safe";
                                                break;
                                            case Card::Defusing:
                                                mm = "Defusing";
                                                break;
                                            case Card::Bomb:
                                                mm = "Bomb";
                                                break;
                                    default :
                                        mm= "none" ;
                                        break ;
                                    }
                                    cout << mm << " " ;

                        }
                            cout << endl ;
            }
            return card.getType();
        }
    }
    this->currentPlayer = cardOwner;
    return card.getType();
}

void Game::nextRound ()
{
    this->round ++;
    this->nbRoundCardsRevealed = 0;

    // shuffle all cards
    vector<Card *> cards = this->getAllPlayerCards();
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(cards.begin(), cards.end(), default_random_engine(seed));

    // redistribution
    const size_t cardsPerPlayer = cards.size() / this->players.size();
    unsigned i = 0;
    vector<Card *>::iterator cardIt = cards.begin();
    for (vector<Player>::iterator it = this->players.begin(); it != this->players.end(); it ++, i ++) {
        vector<Card> newPlayerCards;
        for (unsigned j = 0; j < cardsPerPlayer; j ++) {
            newPlayerCards.push_back(**cardIt);
            cardIt ++;
        }
        (*it).setCards(newPlayerCards);
    }
}

Player * Game::getPlayerForCard (const Card &card)
{
    for (vector<Player>::iterator it = this->players.begin(); it != this->players.end(); it ++) {
        if ((*it).hasCard(card))
            return &(*it);
    }

    return nullptr;
}

vector<Card *> Game::getAllPlayerCards ()
{
    vector<Card *> cards;
    vector<Card> playerCards;

    for (vector<Player>::iterator it = this->players.begin(); it != this->players.end(); it ++) {
        vector<Card> &playerCards = (*it).getCards();
        for (vector<Card>::iterator it2 = playerCards.begin(); it2 != playerCards.end(); it2 ++)
            cards.push_back(&(*it2));

    }

    return cards;
}

vector<Player *> Game::getPlayersForRevealingCard ()
{
    vector<Player *> players;
    for (vector<Player>::iterator it = this->players.begin(); it != this->players.end(); it ++) {
        if ((&(*it) == this->currentPlayer) || ((*it).getCards().size() <= 0))
            continue;
        players.push_back(&(*it));
    }
    return players;
}

size_t Game::getNbDefusingCardsRevealed () const
{
    return this->nbDefusingCardsRevealed;
}

vector<Player> & Game::getPlayers ()
{
    return this->players;
}

Player *Game::getPlayer(size_t i)
{
    size_t j;
    for (j = 0; j < this->getPlayers().size(); j++)
    {
        if (i == j)
            return &this->getPlayers().at(i);
    }
    return nullptr;
}

