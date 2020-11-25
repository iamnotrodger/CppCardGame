#pragma once
#include <vector>
#include <iostream>
#include "card.h"
#include "cardFactory.h"

namespace cards
{
    class Deck
    {
    private:
        std::vector<Card *> deck;

        //shuffles deck
        void shuffle();

    public:
        Deck(){};
        Deck(std::vector<Card *>);
        //Constructor which accepts an istream and reconstructs the deck from file
        Deck(std::istream &, const CardFactory *);
        //Returns and rmoeves the top card from the deck
        Card *draw();
        bool isEmpty() { return deck.empty(); }
        friend std::ostream &operator<<(std::ostream &os, const Deck &d);
    };

    inline std::ostream &operator<<(std::ostream &os, const Deck &d)
    {
        os << "Deck\t";
        for (unsigned i = 0; i < d.deck.size(); i++)
        {
            os << *(d.deck[i]);
        }
        os << std::endl;
        return os;
    }

} // namespace cards