#pragma once
#include <iostream>
#include <list>
#include "card.h"
#include "cardFactory.h"

namespace cards
{
    class TradeArea
    {
    private:
        std::list<Card *> cards;

    public:
        TradeArea();
        //reconstructs the TradeArea from file
        TradeArea(std::istream &, const CardFactory *);
        //Adds the card to the trade are but it does not check if it is legal to place the card.
        TradeArea &operator+=(Card *);
        //returns true if the card can be legally added to the TradeArea, a card of the same bean is already in the TradeArea
        bool legal(Card *);
        //removes a card of the corresponding bean name from the trade are
        Card *trade(std::string);
        //returns the nubmer of cards currently in the trade area
        int numCards()
        {
            return cards.size();
        }
        friend std::ostream &operator<<(std::ostream &, const TradeArea &);

        // helper functions 
        void show();
    };

    inline std::ostream &operator<<(std::ostream &os, const TradeArea &t)
    {
        //iterator for list
        //yeah i don't exactly know what's happening here either (;
        std::list<Card *>::const_iterator i;
        for (i = t.cards.begin(); i != t.cards.end(); i++)
        {
            os << (*i);
        };

        return os;
    }
} // namespace cards