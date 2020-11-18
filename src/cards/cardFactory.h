#pragma once
#include <iostream>
#include "deck.h"
#include "blue.h"
#include "chili.h"
#include "stink.h"
#include "green.h"
#include "soy.h"
#include "black.h"
#include "red.h"
#include "garden.h"

namespace cards
{
    class CardFactory
    {
    protected:
        //variables
        static CardFactory *cardFactory;

        //since the cards doesn't have unique values we will using duplicate pointers to the same card for the deck
        Blue *blueCard;
        Chili *chiliCard;
        Stink *stinkCard;
        Green *greenCard;
        Soy *soyCard;
        Black *blackCard;
        Red *redCard;
        Garden *gardenCard;

        //constructor: creates instances of the card classes
        CardFactory();

    public:
        //returns a pointer to the only instance of card factory
        static CardFactory *getFactory();
        //deletes all instances of the card classes
        ~CardFactory();
        //returns a pointer to the deck
        Deck *getDeck();

        void print()
        {
            std::cout << *blueCard << std::endl;
        }

        //makes it unclonable
        // CardFactory(CardFactory &other) = delete;
        //makes it unassingable
        // void operator=(const CardFactory &) = delete;
    };

} // namespace cards