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
    Deck::Deck(std::vector<Card *> deckVector)
    {
        for (int i = 0; i < deckVector.size(); i++) {
            deck.push_back(deckVector[i]);
        }
    }

    // Deck::Deck(const CardFactory *) {
    //     CardFactory();
    // }

    Deck::~Deck()
    {
    }

    Card *Deck::draw()
    {
        if (deck.size() == 0) {
            return NULL;
        }

        Card *topCard = deck[0];
        deck.erase(deck.begin(), deck.begin() + 1);
        // std::cout << topCard->getName() << std::endl;
        return topCard;
    }
} 