#include "hand.h"

namespace cards
{
    // constructor
    Hand::Hand()
    {
    }

    Hand::~Hand()
    {
    }

    // REAR OF THE HAND IS THE END IF THE LIST
    Hand &Hand::operator+=(Card *card)
    {
        hand.push_back(card);
        return *this;
    }

    // returns and removes the top card
    Card *Hand::play()
    {
        if (hand.size() == 0)
        {
            return NULL;
        }

        Card *top = hand[0];
        hand.erase(hand.begin(), hand.begin() + 1);
        return top;
    }

    // returns the top card
    Card *Hand::top()
    {
        if (hand.size() == 0)
        {
            return NULL;
        }

        Card *top = hand[0];
        return top;
    }

    // allows indexing for the hand
    Card *Hand::operator[](int index)
    {
        if (hand.size() == 0)
        {
            return NULL;
        }

        Card *card = hand[index];
        // std::cout << "Card: " + card->getName() << std::endl;
        return card;
    }

    // deletes a card
    Card *Hand::deleteCard(int index)
    {
        if (hand.size() == 0)
        {
            return NULL;
        }

        Card *card = hand[index];
        hand.erase(hand.begin() + index, hand.begin() + index + 1);

        // for (int i = 0; i < hand.size(); i++)
        // {
        //     std::cout << hand[i]->getName() << std::endl;
        // }
        return card;
    }
} // namespace cards
