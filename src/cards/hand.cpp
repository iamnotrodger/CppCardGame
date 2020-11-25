#include "hand.h"
#include <string>
#include "createClass.h"

namespace cards
{
    // constructor
    Hand::Hand(std::istream &is, const CardFactory *cf)
    {
        CardFactory *cardFac = cf->getFactory();
        std::string verify = "Hand";
        std::string line;
        getline(is, line, '\t');

        //Check if this is a Hand
        if (verify != line.substr(0, 4))
        {
            throw CreateClass("Unable to make Hand Class.");
        }

        getline(is, line, '\n');
        for (std::string::size_type i = 0; i < line.size(); i++)
        {
            *this += cardFac->createCard(line[i]);
        }
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
