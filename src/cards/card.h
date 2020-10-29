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

    protected:
        virtual void print(std::ostream &out) const = 0;
    };

    inline std::ostream &operator<<(std::ostream &os, const Card &card)
    {
        card.print(os);
        return os;
    }

} // namespace cards