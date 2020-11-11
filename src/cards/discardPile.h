#pragma once
#include <vector>
#include <iostream>
#include "card.h"
#include "cardFactory.h"

namespace cards
{
    class DiscardPile
    {
    private:
        std::vector<Card *> pile;

    public:
        //reconstruct the discard pile from file
        DiscardPile();
        DiscardPile(std::istream &, const CardFactory *);
        ~DiscardPile();
        //discard the card to the pile
        DiscardPile &operator+=(Card *);
        //Returns and removes the top card from the discard pile
        Card *pickUp();
        //returns but does not remove the top card from the discard pile
        Card *top();
        friend std::ostream &operator<<(std::ostream &, const DiscardPile &);

    protected:
        //insert all the cards in the DiscardPile
        void print(std::ostream &) const;
    };

    inline std::ostream &operator<<(std::ostream &os, const DiscardPile &d)
    {
        d.print(os);
        return os;
    }
} // namespace cards