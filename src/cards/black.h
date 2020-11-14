#pragma once
#include "card.h"

namespace cards
{
    class Black : public Card
    {
    public:
        int getCardsPerCoin(int);
        std::string getName()
        {
            return "black";
        }
        int getCoinsPerCards(int);

    protected:
        void print(std::ostream &out) const
        {
            out << "b";
        };
    };
} // namespace cards