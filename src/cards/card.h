#pragma once
#include <iostream>

namespace cards
{
    class Card
    {
    public:
        virtual int getCardsPerCoin(int coins) = 0;
        virtual std::string getName() = 0;
        friend std::ostream &operator<<(std::ostream &os, const Card &card);

        //helper function
        //returns the number of coins per number of cards
        virtual int getCoinsPerCards(int) = 0;

    protected:
        virtual void print(std::ostream &out) const = 0;
    };

    inline std::ostream &operator<<(std::ostream &os, const Card &card)
    {
        card.print(os);
        return os;
    }

} // namespace cards