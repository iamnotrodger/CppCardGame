#include <iostream>
#include "random"
#include "algorithm"
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
    Deck::Deck() {

        int i = 0;

        for (i; i < 20; i++) {
            deck.push_back(new Blue());
        }

        for (i; i < 38; i++) {
            deck.push_back(new Chili());
        }

        for (i; i < 54; i++) {
            deck.push_back(new Stink());
        }

        for (i; i < 68; i++) {
            deck.push_back(new Green());
        }

        for (i; i < 80; i++) {
            deck.push_back(new Soy());
        }

        for (i; i < 90; i++) {
            deck.push_back(new Black());
        }

        for (i; i < 98; i++) {
            deck.push_back(new Red());
        }

        for (i; i < 104; i++) {
            deck.push_back(new Garden());
        }

        std::random_shuffle(deck.begin(),deck.end());

        for (int j = 0; j < 5; j++) {
            std::cout << deck[j]->getName() << std::endl;
        }
    }

    Deck::~Deck() {
        for (int i = 0; i < deck.size(); i++) {
            delete deck[i];
        }
    }

    Card * Deck::draw() {
        Card * topCard = deck[0];
        deck.erase(deck.begin(),deck.begin() + 1);
        // std::cout << topCard->getName() << std::endl;
        return topCard;
    }
}