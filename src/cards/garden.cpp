#include "garden.h"

namespace cards
{
    int Garden::getCardsPerCoin(int coin)
    {
        switch (coin)
        {
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return 0;
        };
    }

    int Garden::getCoinsPerCards(int cards)
    {
        if (cards >= 3)
        {
            return 3;
        }
        else if (cards >= 2)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
} // namespace cards