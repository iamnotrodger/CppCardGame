#pragma once
#include "card.h"

namespace cards
{
    class Soy : public Card
    {
    public:
        int getCardsPerCoin(int coin)
        {
            return 1;
        };
        std::string getName()
        {
            return "soy";
        }

    protected:
        void print(std::ostream &out) const
        {
            out << "s" << std::endl;
        };
    };
} // namespace cards