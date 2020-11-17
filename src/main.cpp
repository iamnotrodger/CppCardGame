#include <iostream>
#include "cards/chili.h"
#include "cards/table.h"
#include "cards/player.h"
#include "cards/deck.h"
#include "cards/hand.h"
#include "cards/card.h"
#include "cards/discardpile.h"
using namespace std;

// functions
void setup();
void loop();

// player 1 and player 2
string name1 = "Patrick";
string name2 = "Rodger";

// table
cards::Table table = cards::Table(name1, name2);

// save
bool pause = false;

int main()
{
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

    // cout << "What is Player 1's name? " << endl;
    // cin >> name1;

    // cout << "" << endl;

    // cout << "What is Player 2's name? " << endl;
    // cin >> name2;

    // cout << "" << endl;

    // cards::Player play1 = cards::Player(name1);
    // cards::Player play2 = cards::Player(name2);

    // testing
    // cout << "Each player starts with 5 cards: " << endl;
    // cout << "" << endl;
    // cout << "Player 1:" << endl;
    // for (int i = 0; i < 5; i++) {
    // cout << b[i]->getName() << endl;
    // table.getPlayerOne().printHand(true);
    // }

    // cout << "" << endl;
    // cout << "Player 2:" << endl;
    // for (int j = 0; j < 5; j++) {
    // cout << c[j]->getName() << endl;
    // table.getPlayerTwo().printHand(false);
    // }
}

// main state of the game
void loop()
{

    while (!table.isEmpty()) {

        // random
        bool removeTop = true;
        bool tradeMatch = false;
        string trading;
        string bean;

    // save functionality
    // if (pause) {
    //     save()
    // }

        cout << "Here is your starting hand: " << endl;
        table.printHand(true);

        // trading phase
        if (table.getTradeArea() != 0)
        {
            // Give option to take cards
            cout << "Would you like to take any cards from the trading table? " << endl;
            cin >> trading;

            if (trading == "yes") {
                while (trading == "yes" && table.getTradeArea() != 0) {
                    cout << "Choose a card (by suit): " << endl;
                    cin >> bean;

                    // add cards to chain if possible
                    // table.add(table.tradeCard(bean), true);

                    cout << "Would you like to take any cards from the trading table? " << endl;
                    cin >> trading;
                }
                
                // remove the rest of the cards into the discard pile
            }
        }

        // adding top card phase
        while (removeTop)
        {
            cout << "Your top card is being added to your chains." << endl;

            // Check if added card is the same type of the chain

            // Check if chains are full

            // Sell chains if needed

            removeTop = false;
        }

        // discard phase
        string discard;
        int discard_index;

        cout << "Here is your hand: " << endl;
        table.printHand(true);
        cout << "" << endl;

        cout << "Would you like to discard a card? " << endl;
        cin >> discard;

        if (discard == "yes")
        {
            table.printHand(true);
            cout << "Which card would you like to discard (choose index): " << endl;
            cin >> discard_index;

            table.discardCard(discard_index, table.getTurn());

            cout << "Here is your hand after discarding:" << endl;
            table.printHand(true);
            cout << "" << endl;
        }


        // trade area phase 
        cout << "Cards are being added to the trade table" << endl;
        for (int i = 0; i < 3; i++) {
            table.add(table.draw());
        }

        cout << "Before trade phase" << endl;
        table.tradePhase();

        // add cards to chain, optional for player
        cout << "Here is the tradeArea: " << endl;
        table.getTradeArea();
        // print trade area and optional collection!!!

        // Give option to take cards
        cout << "Would you like to take any cards from the trading table? " << endl;
        cin >> trading;

        if (trading == "yes") {
            while (trading == "yes" && table.getTradeArea() != 0) {
                cout << "Choose a card (by suit): " << endl;
                cin >> bean;

                // add cards to chain if possible
                // table.add(table.tradeCard(bean), true);

                cout << "Would you like to take any cards from the trading table? " << endl;
                cin >> trading;
            }
            
            // remove the rest of the cards into the discard pile
        }


        // draw phase
        for (int i = 0; i < 2; i++) {
            table.add(table.draw(), true);
        }

        cout << "Here is your hand at the end of the round:" << endl;
        table.printHand(true);

        // this player's turn is over
        // table.changeTurn();
        cout << "Ready to continue?" << endl;
        cin >> trading;

    }
}