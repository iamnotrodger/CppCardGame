#pragma once
#include "card.h"

namespace cards
{
    class Stink : public Card
    {
    public:
        int getCardsPerCoin(int);
        std::string getName()
        {
            return "Stink";
        }
        int getCoinsPerCards(int);

    protected:
        void print(std::ostream &out) const
        {
            out << "S";
        };
    };
} // namespace cards