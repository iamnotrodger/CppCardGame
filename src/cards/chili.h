#pragma once
#include "card.h"

namespace cards
{
    class Chili : public Card
    {
    public:
        std::string getName()
        {
            return "Chili";
        }
        int getCardsPerCoin(int);

        int getCoinsPerCards(int);

    protected:
        void print(std::ostream &out) const
        {
            out << "C";
        };
    };
} // namespace cards
