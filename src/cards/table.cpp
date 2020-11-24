#include "table.h"
#include "player.h"

namespace cards
{
    // constructor
    Table::Table(std::string s1, std::string s2)
    {
        playerOne = new Player(s1);
        playerTwo = new Player(s2);
    }

    // returns a boolean indicating who is the winner
    bool Table::win(std::string &winner)
    {
        if (!deck.isEmpty())
        {
            return false;
        }

        // If it's a tie, player 1 wins
        if (playerOne->getNumCoins() >= playerTwo->getNumCoins())
        {
            winner = playerOne->getName();
        }

        else if (playerOne->getNumCoins() < playerTwo->getNumCoins())
        {
            winner = playerTwo->getName();
        }
    }

    // prints the hand or the top card of the player who has the turn
    void Table::printHand(bool show)
    {
        if (playerOneTurn)
        {
            playerOne->printHand(show);
        }

        else
        {
            playerTwo->printHand(show);
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
            // std::cout << "Finished table" << std::endl;
            playerOne->addCard(card);
        }

        // false represents playerTwo
        else if (!playerOneHand)
        {
            // std::cout << "Finished table 2" << std::endl;
            playerTwo->addCard(card);
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
            card = playerOne->deleteCard(index);
            discard += card;
        }

        // false represents playerTwo
        else if (!playerOneHand)
        {
            card = playerTwo->deleteCard(index);
            discard += card;
        }
    }

    // removes a card from a player's hand
    Card * Table::discardTopCard(bool playerOneHand)
    {
        Card * card;
        // true represents playerOne
        if (playerOneHand)
        {
            card = playerOne->deleteCard(0);
        }

        // false represents playerTwo
        else if (!playerOneHand)
        {
            card = playerTwo->deleteCard(0);
        }

        return card;
    }

    // clears the TradeArea
    void Table::clearTrade()
    {
        Card * card;
        
        //for (int i = 0; i<trade.numCards(); i++)
        while (trade.numCards() > 0) {
            // std::cout << "Traded" << std::endl;
            card = trade.trade();
            discard += card;
            // std::cout << trade.numCards() << std::endl;
        }
    }

    // returns the size of trade area
    int Table::getTradeArea() {
        if (trade.numCards() != 0) {
            trade.show();
        }
        
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


    void Table::addCardToChain(Card *card) {
        if (playerOneTurn)
        {
            playerOne->addCardToChain(card);
        }

        else
        {
            playerTwo->addCardToChain(card);
        }
    }
    
    void Table::sellChain(int index) {
        if (playerOneTurn) {
            playerOne += playerOne->sellChain(index);
        }

        else {
            playerTwo += playerTwo->sellChain(index);
        }
    }

} // namespace cards