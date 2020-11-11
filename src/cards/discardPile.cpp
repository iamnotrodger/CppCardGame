#include "discardPile.h"

namespace cards
{
    DiscardPile::DiscardPile() {

    }

    DiscardPile::~DiscardPile() {
        for (int i = 0; i < pile.size(); i++) {
            delete pile[i];
        }
    }

    DiscardPile &DiscardPile::operator+=(Card * card) {
        pile.push_back(card);

        // std::cout << "Match" << std::endl;
        // for (int i = 0; i < pile.size(); i++) {
        //     std::cout << pile[i]->getName() << std::endl;
        // }
        // std::cout << "" << std::endl;

        return *this;
    }

    Card * DiscardPile::pickUp() {

        if (pile.size() == 0) {
            return NULL;
        }

        Card * top = pile[pile.size()-1];
        pile.erase(pile.begin() + pile.size()-1, pile.begin() + pile.size());
        return top;
    }

    Card * DiscardPile::top() {
        if (pile.size() == 0) {
            return NULL;
        }

        Card * top = pile[pile.size()-1];
        return top;
    }
} 