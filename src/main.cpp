#include <iostream>
#include "cards/blue.h"
#include "cards/chili.h"
#include "cards/deck.h"
#include "cards/cardFactory.h"
#include "cards/player.h"
#include "cards/discardPile.h"
using namespace std;

int main()
{
    cards::Chili b;
    cards::Blue bl;
    cout << "Hello Wrold" << endl;
    cout << b.getName() << endl;
    cout << b;
}