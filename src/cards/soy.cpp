#include "soy.h"

namespace cards
{
    int Soy::getCardsPerCoin(int coin)
    {
        switch (coin)
        {
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 7;
        default:
            return 0;
        };
    }

    int Soy::getCoinsPerCards(int cards)
    {
        if (cards >= 7)
        {
            return 4;
        }
        else if (cards >= 6)
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