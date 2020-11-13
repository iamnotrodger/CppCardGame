#include "table.h"
#include "player.h"

namespace cards
{
    Table::Table(std::string s1, std::string s2) {
        playerOne = Player(s1);
        playerTwo = Player(s2);
    }

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

    void Table::printHand(bool show) {
        if (playerOneTurn) {
            playerOne.printHand(show);
        }

        else {
            playerTwo.printHand(show);
        }
        
        
    }

    void Table::changeTurn() {
        playerOneTurn = !playerOneTurn;
    }

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

} 