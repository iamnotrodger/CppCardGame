#include <iostream>
#include "../src/cards/player.h"
#include "../src/cards/hand.h"
#include "../src/cards/blue.h"

using namespace std;
using namespace cards;

int main()
{
    Player *pp = new Player("PeePee");
    Card *card = new Blue();
    Card *card2 = new Chili();
    Card *card3 = new Stink();
    pp->addCard(card);
    pp->addCard(card);
    pp->addCard(card);
    pp->printHand(true);
    pp->addCardToChain(card);
    pp->addCardToChain(card);
    pp->addCardToChain(card2);
    pp->addCardToChain(card3);
    cout << (*pp) << endl;
}

//g++ -std=c++11 player_test.cpp ../src/cards/blue.cpp ../src/cards/chili.cpp ../src/cards/stink.cpp ../src/cards/green.cpp ../src/cards/soy.cpp ../src/cards/black.cpp ../src/cards/red.cpp ../src/cards/garden.cpp ../src/cards/player.cpp ../src/cards/hand.cpp