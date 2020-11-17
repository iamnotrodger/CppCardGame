#include "table.h"
#include "player.h"

namespace cards
{
    // constructor
    Table::Table(std::string s1, std::string s2)
    {
        playerOne = Player(s1);
        playerTwo = Player(s2);
    }

    // returns a boolean indicating who is the winner
    bool Table::win(std::string &winner)
    {
        if (!deck.isEmpty())
        {
            return false;
        }

        // If it's a tie, player 1 wins
        if (playerOne.getNumCoins() >= playerTwo.getNumCoins())
        {
            winner = playerOne.getName();
        }

        else if (playerOne.getNumCoins() < playerTwo.getNumCoins())
        {
            winner = playerTwo.getName();
        }
    }

    // prints the hand or the top card of the player who has the turn
    void Table::printHand(bool show)
    {
        if (playerOneTurn)
        {
            playerOne.printHand(show);
        }

        else
        {
            playerTwo.printHand(show);
        }
    }

    // changes the turn
    void Table::changeTurn()
    {
        playerOneTurn = !playerOneTurn;
    }

    // adds a card to a player's hand
    void Table::add(Card *card, bool playerOneHand)
    {
        // true represents playerOne
        if (playerOneHand)
        {
            playerOne.addCard(card);
        }

        // false represents playerTwo
        else if (!playerOneHand)
        {
            playerTwo.addCard(card);
        }
    }

    // adds a card to the trade area
    void Table::add(Card *card)
    {
        trade += card;
    }

    // removes a card from a player's hand
    void Table::discardCard(int index, bool playerOneHand)
    {
        Card * card;
        // true represents playerOne
        if (playerOneHand)
        {
            card = playerOne.deleteCard(index);
            discard += card;
        }

        // false represents playerTwo
        else if (!playerOneHand)
        {
            card = playerTwo.deleteCard(index);
            discard += card;
        }
    }

    // returns the size of trade area
    int Table::getTradeArea() {
        trade.show();
        return trade.numCards();
    }

    // simulates trade-discard interaction part of trade area phase
    void Table::tradePhase() {

        // runs as long as top of discard pile matches a suit in the trade phase
        while (discard.top() != NULL && trade.legal(discard.top())) {
            trade += discard.pickUp();
        }
    }

    Card * Table::tradeCard(std::string bean) {
        return trade.trade(bean);
    }
    

} // namespace cards