#pragma once
#include "card.h"

namespace cards
{
    class Black : public Card
    {
    public:
        int getCardsPerCoin(int coin)
        {
            return 1;
        };
        std::string getName()
        {
            return "black";
        }

    protected:
        void print(std::ostream &out) const
        {
            out << "b";
        };
    };
} // namespace cards