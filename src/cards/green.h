#pragma once
#include "card.h"

namespace cards
{
    class Green : public Card
    {
    public:
        int getCardsPerCoin(int coin)
        {
            return 1;
        };
        std::string getName()
        {
            return "Green";
        }

    protected:
        void print(std::ostream &out) const
        {
            out << "G";
        };
    };
} // namespace cards