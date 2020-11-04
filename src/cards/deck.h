#pragma once
#include <vector>
#include "cardFactory.h"
#include "card.h"

namespace cards
{
    class Deck
    {
    private:
        std::vector<Card> deck;

    public:
        //Constructor which acceopts an istream and reconstructs the deck from file
        Deck(std::istream &, const CardFactory *);
        //Returns and rmoeves the top card from the deck
        Card *draw();
        friend std::ostream &operator<<(std::ostream &os, const Deck &d);
    };

    inline std::ostream &operator<<(std::ostream &os, const Deck &d)
    {
        for (const Card &card : d.deck)
        {
            os << card;
        }
        return os;
    }

} // namespace cards