#include <iostream>
#include "cards/blue.h"
#include "cards/chili.h"
using namespace std;

int main()
{
    cards::Chili b;
    cout << "Hello Wrold" << endl;
    cout << b.getName() << endl;
    cout << b;
}