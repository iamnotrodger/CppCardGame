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
        Player playerOne;
        Player playerTwo;
        Deck deck;
        DiscardPile discard;
        TradeArea trade;
        bool playerOneTurn;

    public:
        Table();
        Table(std::string, std::string);
        //construct which accepts an instream and reconstruct the Table from file
        Table(std::istream &, const CardFactory *);
        //returns true when a player has won. The name of the player is returned by reference (in the argument). The winning condition is that all cards from the deck must have been picked up and then the payer with the most coinds won
        bool win(std::string &);
        //prings the top card of the player's hand (with argumetn false) or all of the player's hand (with arguments true)
        void printHand(bool);
        friend std::ostream &operator<<(std::ostream &, const Table &);

        // helper methods
        void changeTurn();
        bool getTurn() { return playerOneTurn; }
        Player getPlayerOne() { return playerOne; }
        Player getPlayerTwo() { return playerTwo; }
        void add(Card *, bool);
        void add(Card *);
        int getTradeArea();
        void tradePhase();
        void discardCard(int, bool);

        // testing only
        TradeArea getTrade() {return trade;}
    };

    inline std::ostream &operator<<(std::ostream &os, const Table &t)
    {
        os << t.playerOne;
        os << t.playerTwo;
        os << t.discard;
        os << t.trade;

        return os;
    }

} // namespace cards