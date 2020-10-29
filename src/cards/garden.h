#pragma once
#include "card.h"

namespace cards
{
    class Garden : public Card
    {
    public:
        int getCardsPerCoin(int coin)
        {
            return 1;
        };
        std::string getName()
        {
            return "garden";
        }

    protected:
        void print(std::ostream &out) const
        {
            out << "g" << std::endl;
        };
    };
} // namespace cards