#include <iostream>
#include "../src/cards/chain.h"
#include "../src/cards/card.h"
#include "../src/cards/chili.h"

using namespace std;
using namespace cards;

int main()
{
    cout << "Hello World" << endl;
    Chili c;
    Chain<Chili> chain;
    chain += &c;
}