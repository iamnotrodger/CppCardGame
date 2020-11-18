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
    pp->addCard(card);
    pp->addCard(card);
    pp->addCard(card);
    pp->printHand(true);
    cout << (*pp) << endl;
}

//g++ player_test.cpp ../src/cards/blue.cpp ../src/cards/chili.cpp ../src/cards/stink.cpp ../src/cards/green.cpp ../src/cards/soy.cpp ../src/cards/black.cpp ../src/cards/red.cpp ../src/cards/garden.cpp ../src/cards/player.cpp ../src/cards/hand.cpp