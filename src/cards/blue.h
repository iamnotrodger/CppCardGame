#pragma once
#include <iostream>
#include "card.h"

namespace cards
{
    class Blue : public Card
    {
    public:
        int getCardsPerCoin(int coin)
        {
            return 4 + (coin * 2);
        };
        std::string getName()
        {
            return "Blue";
        }

    protected:
        void print(std::ostream &out) const
        {
            out << "B" << std::endl;
        };
    };
} // namespace cards
