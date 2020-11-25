#pragma once
#include <iostream>
#include <vector>
#include "card.h"
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
    class Deck;
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

        std::vector<Card *> cardList;

        //constructor: creates instances of the card classes
        CardFactory();
        ~CardFactory();

    public:
        //returns a pointer to the only instance of card factory
        static CardFactory *getFactory();
        Deck *getDeck();
        //return
        Card *createCard(char);

        //Copy constructor is deleted
        CardFactory(CardFactory &other) = delete;
        //Assignment operator is deleted
        void operator=(const CardFactory &) = delete;
    };

} // namespace cards