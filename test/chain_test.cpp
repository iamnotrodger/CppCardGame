#include <iostream>
#include "../src/cards/chain.h"
#include "../src/cards/chili.h"
#include "../src/cards/blue.h"

using namespace std;
using namespace cards;

int main()
{
    Chili *c = new Chili();
    Chili *c2 = new Chili();
    Chili *c3 = new Chili();
    Chili *c4 = new Chili();
    Chili *c5 = new Chili();
    Blue *c6 = new Blue();
    Chain<Chili> chain;
    try
    {
        chain += c;
        chain += c2;
        chain += c3;
        chain += c4;
        chain += c5;
        chain += c6;
    }
    catch (IllegalType &e)
    {
        cout << e.what() << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    cout << chain;

    cout << chain.sell() << endl;
    cout << chain.check(c3) << endl;
}

//g++ -std=c++11 chain_test.cpp ../src/cards/chili.cpp ../src/cards/blue.cpp