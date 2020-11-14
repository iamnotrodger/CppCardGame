#include "black.h"

namespace cards
{
    int Black::getCardsPerCoin(int coin)
    {
        switch (coin)
        {
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        default:
            return 0;
        };
    }

    int Black::getCoinsPerCards(int cards)
    {
        if (cards >= 6)
        {
            return 4;
        }
        else if (cards >= 5)
        {
            return 3;
        }
        else if (cards >= 4)
        {
            return 2;
        }
        else if (cards >= 2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
} // namespace cards