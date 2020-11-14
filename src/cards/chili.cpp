#include "chili.h"

namespace cards
{
    int Chili::getCardsPerCoin(int coin)
    {
        switch (coin)
        {
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 9;
        default:
            return 0;
        };
    }

    int Chili::getCoinsPerCards(int cards)
    {
        if (cards >= 9)
        {
            return 4;
        }
        else if (cards >= 8)
        {
            return 3;
        }
        else if (cards >= 6)
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