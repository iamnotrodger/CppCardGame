#include "cardFactory.h"
#include <iostream>
#include <random>
#include <algorithm>
#include "card.h"
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
    CardFactory::CardFactory() {
        int i = 0;

        for (i; i < 20; i++)
        {
            deckList.push_back(new Blue());
        }

        for (i; i < 38; i++)
        {
            deckList.push_back(new Chili());
        }

        for (i; i < 54; i++)
        {
            deckList.push_back(new Stink());
        }

        for (i; i < 68; i++)
        {
            deckList.push_back(new Green());
        }

        for (i; i < 80; i++)
        {
            deckList.push_back(new Soy());
        }

        for (i; i < 90; i++)
        {
            deckList.push_back(new Black());
        }

        for (i; i < 98; i++)
        {
            deckList.push_back(new Red());
        }

        for (i; i < 104; i++)
        {
            deckList.push_back(new Garden());
        }

        for (int j = 0; j < 5; j++)
        {
            std::cout << deckList[j]->getName() << std::endl;
        }
    }

    CardFactory *CardFactory::getFactory() {
        return cardFactory;
    }

    Deck CardFactory::getDeck() {
        auto randomize = std::default_random_engine {};
        std::shuffle(deckList.begin(), deckList.end(),randomize);
        Deck deck = Deck(deckList);
        return deck;
    }
}