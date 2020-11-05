#include <iostream>
#include "cards/blue.h"
#include "cards/chili.h"
#include "cards/deck.h"
#include "cards/cardFactory.h"
using namespace std;

int main()
{
    cards::Chili b;
    cout << "Hello Wrold" << endl;
    cout << b.getName() << endl;
    cout << b;
}