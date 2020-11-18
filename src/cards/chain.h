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
    public:
        virtual Chain_Base &operator+=(Card *) = 0;
        friend std::ostream &operator<<(std::ostream &, const Chain_Base &);

    protected:
        virtual void print(std::ostream &) const = 0;
    };

    inline std::ostream &operator<<(std::ostream &os, const Chain_Base &cb)
    {
        cb.print(os);
        return os;
    }

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
            int size = c.chain.size();
            if (size > 0)
            {
                os << c.chain[0]->getName() << " \t ";
                for (unsigned i = 0; i < size; i++)
                {
                    os << *(c.chain[i]);
                }
                os << std::endl;
            }

            return os;
        }

    protected:
        void print(std::ostream &os) const
        {
            int size = chain.size();
            if (size > 0)
            {
                os << chain[0]->getName() << " \t ";
                for (unsigned i = 0; i < size; i++)
                {
                    os << *(chain[i]);
                }
                os << std::endl;
            }
        }
    };

    template <class T>
    Chain<T>::~Chain()
    {
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
        if (size > 0)
        {
            Card *card = chain.back();
            return card->getCoinsPerCards(size);
        }
        else
        {
            return 0;
        }
    }

} // namespace cards