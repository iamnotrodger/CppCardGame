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
        DiscardPile discard;
        TradeArea trade;

    public:
        Table(std::string, std::string);
        //construct which acceps an isntream and reconstruct the Table from file
        Table(std::istream &, const CardFactory *);
        //returns true when a player has won. The name of the player is returned by refrence (in the argument). The winning condition is that all cards from the deck must have been picked up and then the payer with the most coinds won
        bool win(std::string &);
        //prings the top card of the palyer's hand (with argumetn false) or all of the player's hand (with arguments true)
        void printHand(bool);
        friend std::ostream &operator<<(std::ostream &, const Table &);
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