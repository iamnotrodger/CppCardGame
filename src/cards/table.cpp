#include "table.h"
#include "player.h"

namespace cards
{
    // constructor 
    Table::Table(std::string s1, std::string s2) {
        playerOne = Player(s1);
        playerTwo = Player(s2);
    }

    // returns a boolean indicating who is the winner
    bool Table::win(std::string & winner) {
        if (!deck.isEmpty()) {
            return false;
        }

        // If it's a tie, player 1 wins 
        if (playerOne.getNumCoins() >= playerTwo.getNumCoins()) {
            winner = playerOne.getName();
        }

        else if (playerOne.getNumCoins() < playerTwo.getNumCoins()) {
            winner = playerTwo.getName();
        }
    }

    // prints the hand or the top card of the player who has the turn
    void Table::printHand(bool show) {
        if (playerOneTurn) {
            playerOne.printHand(show);
        }

        else {
            playerTwo.printHand(show);
        }
        
        
    }

    // changes the turn 
    void Table::changeTurn() {
        playerOneTurn = !playerOneTurn;
    }

    // adds a card to a player's hand
    Table &Table::add(Card * card, bool playerOneHand) {
        // true represents playerOne
        if (playerOneHand) {
            playerOne += card;
        }

        // false represents playerTwo
        else if (!playerOneHand) {
            playerTwo += card;
        }

        return *this;
    }

    // removes a card from a player's hand
    Table &Table::discardCard(int index, bool playerOneHand) {
        // true represents playerOne
        if (playerOneHand) {
            playerOne.deleteCard(index);
        }

        // false represents playerTwo
        else if (!playerOneHand) {
            playerTwo.deleteCard(index);
        }

        return *this;
    }

} 