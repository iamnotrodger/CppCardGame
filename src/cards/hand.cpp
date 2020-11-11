#include "hand.h"

namespace cards
{
    Hand::Hand() {

    }

    // REAR OF THE HAND IS THE END IF THE LIST
    Hand &Hand::operator+=(Card * card) {
        hand.push_back(card);

        std::cout << "Match" << std::endl;
        for (int i = 0; i < hand.size(); i++) {
            std::cout << hand[i]->getName() << std::endl;
        }
        std::cout << "" << std::endl;

        return *this;
    }

    Card *Hand::play() {
        if (hand.size() == 0) {
            return NULL;
        }

        Card * top = hand[0];
        hand.erase(hand.begin(), hand.begin() + 1);
        return top;
    }

    Card *Hand::top() {
        if (hand.size() == 0) {
            return NULL;
        }

        Card * top = hand[0];
        return top;
    }

    Card *Hand::operator[](int index) {
        if (hand.size() == 0) {
            return NULL;
        }

        Card * card = hand[index];
        hand.erase(hand.begin()+index, hand.begin()+index+1);
        return card;
    }
} 