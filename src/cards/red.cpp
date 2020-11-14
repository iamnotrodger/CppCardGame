#include "red.h"

namespace cards
{
    int Red::getCardsPerCoin(int coin)
    {
        switch (coin)
        {
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return 0;
        };
    }

    int Red::getCoinsPerCards(int cards)
    {
        if (cards >= 5)
        {
            return 4;
        }
        else if (cards >= 4)
        {
            return 3;
        }
        else if (cards >= 3)
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