#include <iostream>
#include "../cards/chain.h"
#include "../cards/card.h"
#include "../cards/chili.h"

using namespace std;
using namespace cards;

int main()
{
    cout << "Hello World" << endl;
    Chili c;
    Chain<Chili> chain;
    chain += &c;
}