#pragma once
#include "deck.h"

namespace cards
{
    class CardFactory
    {
    public:
        CardFactory();
        //returns a pointer to the only instance of card factory
        static CardFactory *getFactory();
        Deck getDeck();
    };
} // namespace cards