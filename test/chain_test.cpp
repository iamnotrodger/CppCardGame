#include <iostream>
#include "../src/cards/chain.h"
#include "../src/cards/card.h"
#include "../src/cards/chili.h"
#include "../src/cards/blue.h"

using namespace std;
using namespace cards;

int main()
{
    cout << "Hello World" << endl;
    Chili *c = new Chili();
    Chili *c2 = new Chili();
    Chili *c3 = new Chili();
    Chili *c4 = new Chili();
    Chili *c5 = new Chili();
    Blue *c6 = new Blue();
    Chain<Chili> chain;
    chain += c;
    chain += c2;
    chain += c3;
    chain += c4;
    chain += c5;
    chain += c6;
    cout << chain;
}