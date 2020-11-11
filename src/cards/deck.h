#pragma once
#include <vector>
#include <iostream>
#include "card.h"

namespace cards
{
    //cannot to an #include "cardFactory.h" since we include this on the CardFactory
    class CardFactory;

    class Deck
    {
    private:
        std::vector<Card *> deck;

    public:
        Deck();
        //Constructor which accepts an istream and reconstructs the deck from file
        Deck(std::istream &, const CardFactory *);
        ~Deck();
        //Returns and rmoeves the top card from the deck
        Card *draw();
        friend std::ostream &operator<<(std::ostream &os, const Deck &d);
    };

    inline std::ostream &operator<<(std::ostream &os, const Deck &d)
    {
        for (unsigned i = 0; i < d.deck.size(); i++)
        {
            os << d.deck[i];
        }
        return os;
    }

} // namespace cards