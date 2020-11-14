#pragma once
#include "card.h"

namespace cards
{
    class Soy : public Card
    {
    public:
        int getCardsPerCoin(int);
        std::string getName()
        {
            return "soy";
        }
        int getCoinsPerCards(int);

    protected:
        void print(std::ostream &out) const
        {
            out << "s";
        };
    };
} // namespace cards