#pragma once
#include "deck.h"

namespace cards
{
    class CardFactory
    {
    public:
        //returns a pointer to the only instance of card factory
        static CardFactory *getFactory();
        Deck getDeck();

    private:
        static CardFactory *const cardFactory;
        CardFactory();
        ~CardFactory();
    };
} // namespace cards