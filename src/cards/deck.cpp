#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>

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
#include "createClass.h"

namespace cards
{
    Deck::Deck(std::istream &is, const CardFactory *cf)
    {
        CardFactory *cardFac = cf->getFactory();
        std::string verify = "Deck";
        std::string line;
        getline(is, line, '\t');

        //verity this class
        if (verify != line)
        {
            throw CreateClass("Unable to make Deck Class.");
        }

        getline(is, line, '\n');
        for (std::string::size_type i = 0; i < line.size(); i++)
        {
            deck.push_back(cardFac->createCard(line[i]));
        }
    }

    Deck::Deck(std::vector<Card *> deckVector)
    {
        deck = deckVector;
        shuffle();
    }

    Card *Deck::draw()
    {
        if (deck.size() == 0)
        {
            return NULL;
        }

        Card *topCard = deck.back();
        deck.pop_back();
        return topCard;
    }

    void Deck::shuffle()
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
    }
} // namespace cards