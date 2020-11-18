#include <iostream>
#include "../src/cards/cardFactory.h"
#include "../src/cards/deck.h"

using namespace std;
using namespace cards;

CardFactory *CardFactory::cardFactory;

int main()
{
    CardFactory *cf = CardFactory::getFactory();
    Deck deck = cf->getDeck();
    cout << deck;
}

// g++ -std=c++11  cardFactory_test.cpp ../src/cards/blue.cpp ../src/cards/chili.cpp ../src/cards/stink.cpp ../src/cards/green.cpp ../src/cards/soy.cpp ../src/cards/black.cpp ../src/cards/red.cpp ../src/cards/garden.cpp ../src/cards/cardFactory.cpp ../src/cards/deck.cpp