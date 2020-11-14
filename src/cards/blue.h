#pragma once
#include <iostream>
#include "card.h"

namespace cards
{
    class Blue : public Card
    {
    public:
        int getCardsPerCoin(int);
        std::string getName()
        {
            return "Blue";
        }
        int getCoinsPerCards(int);

    protected:
        void print(std::ostream &out) const
        {
            out << "B";
        };
    };
} // namespace cards
