#pragma once
#include "card.h"

namespace cards
{
    class Green : public Card
    {
    public:
        int getCardsPerCoin(int);
        std::string getName()
        {
            return "Green";
        }
        int getCoinsPerCards(int);

    protected:
        void print(std::ostream &out) const
        {
            out << "G";
        };
    };
} // namespace cards