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
cards::Player play1;
cards::Player play2;

// player hands
cards::Hand hand1 = cards::Hand();
cards::Hand hand2 = cards::Hand();

// deck,discard pile, and trade area
cards::Deck deck = cards::Deck();
cards::DiscardPile discard = cards::DiscardPile();
cards::TradeArea trade = cards::TradeArea();

// table
cards::Table table = cards::Table();

int main()
{
    setup();
}

// sets up all of the variables for the game to take place
void setup() {
    string name1;
    string name2;
    
    cout << "Welcome to our C++ project!" << endl;
    cout << "What is Player 1's name? " << endl;
    cin >> name1;
    
    cout << "" << endl;

    cout << "What is Player 2's name? " << endl;
    cin >> name2;

    cout << "" << endl;

    cards::Player play1 = cards::Player(name1);
    cards::Player play2 = cards::Player(name2);

    for (int i = 0; i < 5; i++) {
        hand1 += deck.draw();
    }

    for (int i = 0; i < 5; i++) {
        hand2 += deck.draw();
    }

    // testing
    // cout << "Each player starts with 5 cards: " << endl;
    // cout << "" << endl;
    // cout << "Player 1:" << endl;
    // for (int i = 0; i < 5; i++) {
    //     cout << b[i]->getName() << endl;
    // }

    // cout << "" << endl;
    // cout << "Player 2:" << endl;
    // for (int j = 0; j < 5; j++) {
    //     cout << c[j]->getName() << endl;
    // }
}

void loop() {
    
}