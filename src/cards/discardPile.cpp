#include "discardPile.h"

namespace cards
{
    DiscardPile::DiscardPile() {

    }

    DiscardPile::~DiscardPile() {

    }

    DiscardPile &DiscardPile::operator+=(Card * card) {
        pile.push_back(card);

        std::cout << "Match" << std::endl;
        for (int i = 0; i < pile.size(); i++) {
            std::cout << pile[i]->getName() << std::endl;
        }
        std::cout << "" << std::endl;

        return *this;
    }
} 