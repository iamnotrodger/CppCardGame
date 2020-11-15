#include <iostream>
#include "../src/cards/card.h"
#include "../src/cards/blue.h"
#include "../src/cards/chili.h"
#include "../src/cards/stink.h"
#include "../src/cards/green.h"
#include "../src/cards/soy.h"
#include "../src/cards/black.h"
#include "../src/cards/red.h"
#include "../src/cards/garden.h"
#include "../src/cards/chain.h"

using namespace cards;
using namespace std;

int main()
{
    Card *blue = new Blue();
    Card *chili = new Chili();
    Card *stink = new Stink();
    Card *green = new Green();
    Card *soy = new Soy();
    Card *black = new Black();
    Card *red = new Red();
    Card *garden = new Garden();

    cout << *(blue) << endl;
    cout << *(chili) << endl;
    cout << *(stink) << endl;
    cout << *(green) << endl;
    cout << *(soy) << endl;
    cout << *(black) << endl;
    cout << *(red) << endl;
    cout << *(garden) << endl;

    cout << typeid(*(blue)).name() << endl;
    cout << typeid(Blue).name() << endl;
}

//g++ cards_test.cpp ../src/cards/blue.cpp ../src/cards/chili.cpp ../src/cards/stink.cpp ../src/cards/green.cpp  ../src/cards/soy.cpp ../src/cards/black.cpp ../src/cards/red.cpp ../src/cards/garden.cpp