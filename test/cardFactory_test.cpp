#include <iostream>
#include "../src/cards/cardFactory.h"

using namespace std;
using namespace cards;

CardFactory *CardFactory::cardFactory;

int main()
{
    CardFactory *cf = CardFactory::getFactory();
    cf->print();
}

// g++ -std=c++11  cardFactory_test.cpp ../src/cards/blue.cpp ../src/cards/chili.cpp ../src/cards/stink.cpp ../src/cards/green.cpp ../src/cards/soy.cpp ../src/cards/black.cpp ../src/cards/red.cpp ../src/cards/garden.cpp ../src/cards/cardFactory.cpp ../src/cards/deck.cpp