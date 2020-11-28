#include <string>
#include <sstream>
#include "table.h"
#include "player.h"
#include "createClass.h"

namespace cards
{
    // constructor
    Table::Table(std::string s1, std::string s2, const CardFactory *cf)
    {
        CardFactory *cardFactory = cf->getFactory();
        this->playerOne = new Player(s1);
        this->playerTwo = new Player(s2);
        this->deck = cardFactory->getDeck();
        this->discard = new DiscardPile();
        this->trade = new TradeArea();
    }

    Table::Table(std::istream &is, const CardFactory *cf)
    {
        CardFactory *cardFac = cf->getFactory();
        std::string verify = "Table";
        std::string line;
        std::istringstream ss;
        getline(is, line, '\n');

        //verity this class
        if (verify != line)
        {
            throw CreateClass("Unable to make Table Class.");
        }

        getline(is, line, '\n');
        getline(is, line, '\t');
        getline(is, line, '\n');
        ss.str(line);
        ss >> this->playerOneTurn;
        if (ss.fail())
        {
            throw CreateClass("Unable to create Table Class");
        }

        getline(is, line, '\n');
        this->deck = new Deck(is, cf);

        getline(is, line, '\n');
        this->playerOne = new Player(is, cf);

        getline(is, line, '\n');
        this->playerTwo = new Player(is, cf);

        getline(is, line, '\n');
        this->discard = new DiscardPile(is, cf);

        getline(is, line, '\n');
        this->trade = new TradeArea(is, cf);
    }

    // returns a boolean indicating who is the winner
    bool Table::win(std::string &winner)
    {
        if (!deck->isEmpty())
        {
            return false;
        }

        if (playerOne->getNumCoins() > playerTwo->getNumCoins())
        {
            winner = playerOne->getName();
        }

        else if (playerOne->getNumCoins() < playerTwo->getNumCoins())
        {
            winner = playerTwo->getName();
        }

        else {
            winner = "no one! It's a tie";
        }

        return true;
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
    void Table::addPlayer(Card *card, bool playerOneHand)
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
    void Table::addTrade(Card *card)
    {
        *trade += card;
    }

    // removes a card from a player's hand
    void Table::discardCard(int index, bool playerOneHand)
    {
        Card *card;
        // true represents playerOne
        if (playerOneHand)
        {
            card = playerOne->deleteCard(index);
            *discard += card;
        }

        // false represents playerTwo
        else if (!playerOneHand)
        {
            card = playerTwo->deleteCard(index);
            *discard += card;
        }
    }

    // removes a card from a player's hand
    Card *Table::discardTopCard()
    {
        Card *card;
        // true represents playerOne
        if (playerOneTurn)
        {
            card = playerOne->deleteCard(0);
        }

        // false represents playerTwo
        else if (!playerOneTurn)
        {
            card = playerTwo->deleteCard(0);
        }

        return card;
    }

    // clears the TradeArea
    void Table::clearTrade()
    {
        Card *card;

        //for (int i = 0; i<trade.numCards(); i++)
        while (trade->numCards() > 0)
        {
            // std::cout << "Traded" << std::endl;
            card = trade->trade();
            *discard += card;
            // std::cout << trade.numCards() << std::endl;
        }
    }

    // returns the size of trade area
    int Table::getTradeArea()
    {
        if (trade->numCards() != 0)
        {
            trade->show();
        }

        return trade->numCards();
    }

    // simulates trade-discard interaction part of trade area phase
    void Table::tradePhase()
    {

        // runs as long as top of discard pile matches a suit in the trade phase
        while (discard->top() != NULL && trade->legal(discard->top()))
        {
            *trade += discard->pickUp();
        }
    }

    Card *Table::tradeCard(std::string bean)
    {
        return trade->trade(bean);
    }

    bool Table::addCardToChain(Card *card)
    {
        if (playerOneTurn)
        {
            return playerOne->addCardToChain(card);
        }

        else
        {
            return playerTwo->addCardToChain(card);
        }
    }

    void Table::sellChain(int index)
    {
        if (playerOneTurn)
        {
            playerOne += playerOne->sellChain(index);
        }

        else
        {
            playerTwo += playerTwo->sellChain(index);
        }
    }

    int Table::getChain() {
        if (playerOneTurn)
        {
            return playerOne->getMaxNumChains();
        }

        else
        {
            return playerTwo->getMaxNumChains();
        }
    }

    int Table::money() {
        if (playerOneTurn)
        {
            return playerOne->getNumCoins();
        }

        else
        {
            return playerTwo->getNumCoins();
        }
    }

    void Table::buyChain() {
        if (playerOneTurn)
        {
            playerOne->buyThirdChain();
        }

        else
        {
            playerTwo->buyThirdChain();
        }
    }

    int Table::getHandSize() {
        if (playerOneTurn)
        {
            return playerOne->getHandSize();
        }

        else
        {
            return playerTwo->getHandSize();
        }
    }

} // namespace cards