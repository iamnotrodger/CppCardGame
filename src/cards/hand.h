#pragma once
#include <iostream>
#include <vector>
#include "card.h"
#include "cardFactory.h"

namespace cards
{
    class Hand
    {
    private:
        std::vector<Card *> hand;

    public:
        Hand(){};
        ~Hand(){};
        //reconstruct the hand from file
        Hand(std::istream &, const CardFactory *);
        //adds the card rear of the hand
        Hand &operator+=(Card *);
        //returns and removes the the top card from the palyer's hand
        Card *play();
        //returns but does not remove the top card form the player's hand
        Card *top();
        Card *operator[](int);
        int getSize() { return hand.size(); }
        //returns and removes the card from the players hands at the given index
        friend std::ostream &operator<<(std::ostream &, const Hand &);

        // helper functions
        Card *deleteCard(int);
    };

    inline std::ostream &operator<<(std::ostream &os, const Hand &h)
    {
        os << "Hand\t";
        for (int i = 0; i < h.hand.size(); i++)
        {
            os << *(h.hand[i]);
        };
        os << std::endl;
        return os;
    }
} // namespace cards
