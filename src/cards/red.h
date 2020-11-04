#pragma once
#include "card.h"

namespace cards
{
    class Red : public Card
    {
    public:
        int getCardsPerCoin(int coin)
        {
            return 1;
        };
        std::string getName()
        {
            return "Red";
        }

    protected:
        void print(std::ostream &out) const
        {
            out << "R";
        };
    };
} // namespace cards