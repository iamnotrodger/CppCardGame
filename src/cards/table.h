#pragma once
#include <iostream>
#include "player.h"
#include "deck.h"
#include "discardPile.h"
#include "tradeArea.h"

namespace cards
{
    class Table
    {
    private:
        Player *playerOne;
        Player *playerTwo;
        Deck *deck;
        DiscardPile *discard;
        TradeArea *trade;
        bool playerOneTurn = true;

    public:
        Table();
        Table(std::string, std::string, const CardFactory *);
        //construct which accepts an instream and reconstruct the Table from file
        Table(std::istream &, const CardFactory *);
        //returns true when a player has won. The name of the player is returned by reference (in the argument). The winning condition is that all cards from the deck must have been picked up and then the payer with the most coinds won
        bool win(std::string &);
        //prings the top card of the player's hand (with argumetn false) or all of the player's hand (with arguments true)
        void printHand(bool);
        friend std::ostream &operator<<(std::ostream &, const Table &);

        // helper methods
        void changeTurn();
        bool getTurn() { return playerOneTurn; };
        void addPlayer(Card *, bool);
        void addTrade(Card *);
        int getTradeArea();
        void tradePhase();
        void discardCard(int, bool);
        Card *tradeCard(std::string bean);
        Card *draw() { return deck->draw(); }
        bool isEmpty() { return deck->isEmpty(); }

        // testing only
        TradeArea getTrade() { return *trade; }
        bool addCardToChain(Card *card);
        void clearTrade();
        Card *discardTopCard();
        void sellChain(int);
    };

    inline std::ostream &operator<<(std::ostream &os, const Table &t)
    {
        os << "Table" << std::endl;
        os << std::endl;
        os << "Player One's Turn:\t" << t.playerOneTurn << std::endl;
        os << std::endl;
        os << *(t.deck) << std::endl;
        os << *(t.playerOne);
        os << *(t.playerTwo);
        os << *(t.discard) << std::endl;
        os << *(t.trade) << std::endl;

        return os;
    }

} // namespace cards