#pragma once
#include <vector>
#include <iostream>
#include "card.h"
#include "cardFactory.h"
#include "illegalType.h"

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
        std::vector<Card *> chain;

    public:
        Chain(){};
        //constructor which accepts an istream and reconstructs the chain from file when a game is resumed
        Chain(std::istream &, const CardFactory *);
        ~Chain();
        //Adds a card to the Chain. If the run-time type does not match the template type of the chain an exception of type IllegalType needs to be raised
        Chain<T> &operator+=(Card *);
        //Counts the number of cards in the current chain and returns the number of coins according to the function Card::getCardsPerCoin
        int sell();
        friend std::ostream &operator<<(std::ostream &os, const Chain<T> &c)
        {
            for (unsigned i = 0; i < c.chain.size(); i++)
            {
                if (i == 0)
                {
                    os << c.chain[i]->getName() << " \t ";
                }
                os << *(c.chain[i]) << " ";
            }
            os << std::endl;

            return os;
        }
    };

    template <class T>
    Chain<T>::~Chain()
    {
        for (int i = 0; i < chain.size(); i++)
        {
            delete chain[i];
        }
        chain.clear();
    }

    template <class T>
    Chain<T> &Chain<T>::operator+=(Card *card)
    {
        if (typeid(T) != typeid(*(card)))
        {
            throw IllegalType();
        }
        chain.push_back(card);
        return *this;
    }

    template <class T>
    int Chain<T>::sell()
    {
        int size = chain.size();
        return 1;
    }

} // namespace cards