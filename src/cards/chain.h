#pragma once
#include <vector>
#include <iostream>
#include "card.h"
#include "cardFactory.h"

namespace cards
{
    //base class for Chain
    class Chain_Base
    {
    };
    template <class T>
    class Chain : public Chain_Base
    {
    private:
        std::string type;
        std::vector<T *> chain;

    public:
        Chain(){};
        //constructor which accepts an istream and reconstructs the chain from file when a game is resumed
        Chain(std::istream &, const CardFactory *);
        ~Chain();
        //Adds a card to the Chain. If the run-time type does not match the template type of the chain an exception of type IlligalType needs to be raised
        Chain<T> &operator+=(T *);
        //Counts the number of cards in the current chain and returns the nubmer conisn according to the function Card::getCardsPerCoin
        int sell();
        friend std::ostream &operator<<(std::ostream &, const Chain<T> &);
    };

    template <class T>
    inline std::ostream &operator<<(std::ostream &os, const Chain<T> &c)
    {
        os << c.type << " : ";
        for (unsigned i = 0; i < c.chain.size(); i++)
        {
            os << c.chain[i];
        }
        os << std::endl;

        return os;
    }

} // namespace cards