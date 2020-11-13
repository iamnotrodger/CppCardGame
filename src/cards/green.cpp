#include "green.h"

namespace cards
{
    int Green::getCardsPerCoin(int coin)
    {
        switch (coin)
        {
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        default:
            return 0;
        };
    }

    int Green::getCoinsPerCards(int cards)
    {
        if (cards >= 7)
        {
            return 4;
        }
        else if (cards >= 6)
        {
            return 3;
        }
        else if (cards >= 5)
        {
            return 2;
        }
        else if (cards >= 3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
} // namespace cards