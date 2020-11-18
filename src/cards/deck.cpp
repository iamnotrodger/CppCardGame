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

namespace cards
{
    Deck::Deck(std::vector<Card *> deckVector)
    {
        deck = deckVector;
        shuffle();
    }

    Deck::Deck() {
        for (int i = 0; i < 20; i++)
        {
            deck.push_back(new Blue());
        }

        //push chili cards
        for (int i = 0; i < 18; i++)
        {
            deck.push_back(new Chili());
        }

        //push stink cards
        for (int i = 0; i < 16; i++)
        {
            deck.push_back(new Stink());
        }

        //push green cards
        for (int i = 0; i < 14; i++)
        {
            deck.push_back(new Green());
        }

        //push soy cards
        for (int i = 0; i < 12; i++)
        {
            deck.push_back(new Soy());
        }

        //push black cards
        for (int i = 0; i < 10; i++)
        {
            deck.push_back(new Black());
        }

        //push red cards
        for (int i = 0; i < 8; i++)
        {
            deck.push_back(new Red());
        }

        //push garden
        for (int i = 0; i < 6; i++)
        {
            deck.push_back(new Garden());
        }

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