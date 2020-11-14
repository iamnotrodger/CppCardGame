#pragma once
#include "card.h"

namespace cards
{
    class Red : public Card
    {
    public:
        int getCardsPerCoin(int);
        std::string getName()
        {
            return "Red";
        }
        int getCoinsPerCards(int);

    protected:
        void print(std::ostream &out) const
        {
            out << "R";
        };
    };
} // namespace cards