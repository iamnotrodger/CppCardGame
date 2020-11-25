#include <fstream>
#include "../src/cards/table.h"

using namespace std;
using namespace cards;

CardFactory *CardFactory::cardFactory;

int main()
{
    CardFactory *cf = CardFactory::getFactory();
    fstream myfile("saved_game.txt");

    if (myfile.is_open())
    {
        Table *table = new Table(myfile, cf);
        cout << *table << endl;
        // myfile << *table;
    }
    myfile.close();

    // Table *table = new Table("PlayerOne", "PlayerTwo", cf);

    // // adds 5 cards to each player's hand
    // for (int i = 0; i < 5; i++)
    // {
    //     table->addPlayer(table->draw(), true);
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     table->addPlayer(table->draw(), false);
    // }

    // //add card to chain to player one
    // table->addCardToChain(table->draw());
    // table->addCardToChain(table->draw());

    // table->changeTurn();

    // //add card to chain to player two
    // table->addCardToChain(table->draw());
    // table->addCardToChain(table->draw());
    // cout << *table << endl;
    // table->discardCard(0, true);
    // table->discardCard(0, true);
    // table->discardCard(0, false);
    // table->discardCard(0, false);
    // table->addTrade(table->draw());
    // table->addTrade(table->draw());
    // table->addTrade(table->draw());
}

//g++ -std=c++11 table_test.cpp