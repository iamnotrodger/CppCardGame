#pragma once
#include "card.h"

namespace cards
{
    class Chili : public Card
    {
    public:
        int getCardsPerCoin(int coin)
        {
            return 1;
        };
        std::string getName()
        {
            return "Chili";
        }

    protected:
        void print(std::ostream &out) const
        {
            out << "C" << std::endl;
        };
    };
} // namespace cards
