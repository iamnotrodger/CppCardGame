#include <iostream>
#include "cards/chili.h"
#include "cards/table.h"
#include "cards/player.h"
#include "cards/deck.h"
#include "cards/hand.h"
#include "cards/discardpile.h"
// #include "cards/player.h"
using namespace std;

// functions
void setup();
void loop();

// player 1 and player 2
string name1 = "Patrick";
string name2 = "Rodger";
// cards::Player play1 = cards::Player(name1);
// cards::Player play2 = cards::Player(name2);

// player hands
// cards::Hand hand1 = cards::Hand();
// cards::Hand hand2 = cards::Hand();

// deck,discard pile, and trade area
cards::Deck deck = cards::Deck();
cards::DiscardPile discard = cards::DiscardPile();
cards::TradeArea trade = cards::TradeArea();

// table
cards::Table table = cards::Table(name1, name2);

// save
bool pause = false;

// random
bool removeTop = true;

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
    // cout << "What is Player 1's name? " << endl;
    // cin >> name1;

    // cout << "" << endl;

    // cout << "What is Player 2's name? " << endl;
    // cin >> name2;

    // cout << "" << endl;

    // cards::Player play1 = cards::Player(name1);
    // cards::Player play2 = cards::Player(name2);

    // adds 5 cards to each player's hand
    for (int i = 0; i < 5; i++)
    {
        table.add(deck.draw(), true);
    }

    for (int i = 0; i < 5; i++)
    {
        table.add(deck.draw(), false);
    }

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
    // while (!deck.isEmpty()) {

    // save functionality
    // if (pause) {
    //     save()
    // }

    cout << "Player " << endl;
    table.printHand(true);
    table.add(deck.draw(), table.getTurn());

    // trading phase
    if (trade.numCards() != 0)
    {
        // Give option to take cards
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
    }

    // }
}