#include <iostream>
#include <fstream>
#include <string>
#include "../src/cards/player.h"
#include "../src/cards/hand.h"
#include "../src/cards/blue.h"
#include "../src/cards/cardFactory.h"

using namespace std;
using namespace cards;

CardFactory *CardFactory::cardFactory;

int main()
{
    CardFactory *cf = CardFactory::getFactory();
    fstream myfile("test.txt");

    if (myfile.is_open())
    {
        // Player *pp = new Player("PeePee");
        Player *pp = new Player(myfile, cf);

        pp->addCard(cf->createCard('B'));
        pp->addCard(cf->createCard('B'));
        pp->addCard(cf->createCard('C'));
        pp->printHand(true);

        pp->addCardToChain(cf->createCard('B'));
        pp->addCardToChain(cf->createCard('B'));
        pp->addCardToChain(cf->createCard('C'));
        pp->addCardToChain(cf->createCard('C'));
        pp->addCardToChain(cf->createCard('S'));

        cout << (*pp) << endl;
    }

    myfile.close();
}

//g++ -std=c++11 player_test.cpp ../src/cards/blue.cpp ../src/cards/chili.cpp ../src/cards/stink.cpp ../src/cards/green.cpp ../src/cards/soy.cpp ../src/cards/black.cpp ../src/cards/red.cpp ../src/cards/garden.cpp ../src/cards/player.cpp ../src/cards/hand.cpp ../src/cards/cardFactory.cpp ../src/cards/deck.cpp