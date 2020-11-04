#pragma once
#include <vector>
#include "card.h"
#include "chainBase.h"
#include "cardFactory.h"

namespace cards
{
    template <class T>
    class Chain : public Chain_Base
    {
        std::string type;
        std::vector<T> chain;

    public:
        //constructor which accepts an istream and reconstructs the chain from file when a game is resumed
        Chain(std::istream &, const CardFactory *);
        //Adds a card to the Chain. If the run-time type does not match the template type of the chain an exception of type IlligalType needs to be raised
        Chain<T> &operator+=(Card *);
        //Counts the number of cards in the current chain and returns the nubmer conisn according to the function Card::getCardsPerCoin
        int sell();
        friend std::ostream &operator<<(std::ostream &os, const Chain<T> &c)
    };

    template <class T>
    inline std::ostream &operator<<(std::ostream &os, const Chain<T> &c)
    {
        os << type << " : ";
        for (const T &card : c.chain)
        {
            os << card;
        }
        os << std::endl;

        return os;
    }
} // namespace cards