#include "table.h"

namespace cards
{
    Table::Table() {

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

    // Have to complete player in order to work
    // void Table::printHand(bool show) {
    //     if (playerOneTurn) {
    //         playerOne.printHand(show);
    //     }

    //     else {
    //         playerTwo.printHand(show);
    //     }
        
        
    // }
} 