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
cards::Table table = cards::Table(name1,name2);

// save 
bool pause = false;
bool p1 = true;

int main()
{
    setup();
    loop();
}

// sets up all of the variables for the game to take place
void setup() {
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

    for (int i = 0; i < 5; i++) {
        table.add(deck.draw(),true);
    }

    for (int i = 0; i < 5; i++) {
        table.add(deck.draw(),false);
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

void loop() {
    // while (!deck.isEmpty()) {

        // save functionality 
        // if (pause) {
        //     save()
        // }

        table.printHand(true);

    // }
}