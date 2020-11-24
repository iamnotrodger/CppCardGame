#include <iostream>
#include "cards/chili.h"
#include "cards/table.h"
#include "cards/player.h"
#include "cards/deck.h"
#include "cards/hand.h"
#include "cards/card.h"
#include "cards/discardpile.h"
using namespace std;
using namespace cards;

// functions
void setup();
void loop();

// player 1 and player 2
string name1 = "Patrick";
string name2 = "Rodger";

// table
Table table = Table(name1, name2);

// save
bool pause = false;

CardFactory *CardFactory::cardFactory;

int main()
{
    CardFactory *cf = CardFactory::getFactory();
    setup();
    loop();
}

// sets up all of the variables for the game to take place
void setup()
{
    string name1;
    string name2;

    cout << "Welcome to our C++ project!" << endl;

    // adds 5 cards to each player's hand
    for (int i = 0; i < 5; i++)
    {
        table.add(table.draw(), true);
    }

    for (int i = 0; i < 5; i++)
    {
        table.add(table.draw(), false);
    }
}

// main state of the game
void loop()
{
    while (!table.isEmpty())
    {
        // random
        bool removeTop = true;
        bool tradeMatch = false;
        string trading;
        string bean;
        int index;

        // save functionality
        // if (pause) {
        //     save()
        // }

        cout << "Here is your starting hand: " << endl;
        table.printHand(table.getTurn());

        // trading phase
        if (table.getTradeArea() != 0)
        {
            // Give option to take cards
            cout << "Would you like to take any cards from the trading table? " << endl;
            cin >> trading;

            if (trading == "yes")
            {
                while (trading == "yes" && table.getTradeArea() != 0)
                {
                    cout << "Choose a card (by suit): " << endl;
                    cin >> bean;

                    // add cards to chain if possible
                    table.addCardToChain(table.tradeCard(bean));

                    cout << "Would you like to take any cards from the trading table? " << endl;
                    cin >> trading;
                }
            }

            // remove the rest of the cards into the discard pile
            table.clearTrade();
        }

        // adding top card phase
        while (removeTop)
        {
            cout << "Your top card is being added to your chains." << endl;
            cout << "" << endl;

            if (!table.addCardToChain(table.discardTopCard())) {
                cout << "Please choose a chain to discard: (by index): " << endl;
                cin >> index;

                while (index > 1 || index < 0) {
                    cout << "Invalid index. Please choose again." << endl;
                    cin >> index;
                }

                table.sellChain(index);
            }

            // Check if added card is the same type of the chain

            // Check if chains are full

            // Sell chains if needed

            removeTop = false;
        }

        // discard phase
        string discard;
        int discard_index;

        cout << "Here is your hand: " << endl;
        table.printHand(table.getTurn());
        cout << "" << endl;

        cout << "Would you like to discard a card? " << endl;
        cin >> discard;
        cout << "" << endl;

        if (discard == "yes")
        {
            cout << "Which card would you like to discard (choose index): " << endl;
            cin >> discard_index;

            table.discardCard(discard_index, table.getTurn());

            cout << "" << endl;
            cout << "Here is your hand after discarding:" << endl;
            table.printHand(table.getTurn());
            cout << "" << endl;
        }

        // trade area phase
        for (int i = 0; i < 3; i++)
        {
            table.add(table.draw());
        }

        table.tradePhase();

        // add cards to chain, optional for player
        cout << "Here is the tradeArea: " << endl;
        table.getTradeArea();
        // print trade area and optional collection!!!

        // Give option to take cards
        cout << "Would you like to take any cards from the trading table? " << endl;
        cin >> trading;
        cout << "" << endl;

        if (trading == "yes")
        {
            while (trading == "yes" && table.getTradeArea() != 0)
            {
                cout << "" << endl;
                cout << "Choose a card (by suit): " << endl;
                cin >> bean;

                // add cards to chain if possible
                table.addCardToChain(table.tradeCard(bean));

                cout << "Would you like to take any cards from the trading table? " << endl;
                cin >> trading;
            }

            // remove the rest of the cards into the discard pile
        }

        // draw phase
        for (int i = 0; i < 2; i++)
        {
            table.add(table.draw(), table.getTurn());
        }

        cout << "Here is your hand at the end of the round:" << endl;
        table.printHand(table.getTurn());

        // this player's turn is over
        // table.changeTurn();
        cout << "Ready to continue?" << endl;
        cin >> trading;
    }
}