#pragma once
#include "card.h"

namespace cards
{
    class Garden : public Card
    {
    public:
        int getCardsPerCoin(int);
        std::string getName()
        {
            return "garden";
        }
        int getCoinsPerCards(int);

    protected:
        void print(std::ostream &out) const
        {
            out << "g";
        };
    };
} // namespace cards