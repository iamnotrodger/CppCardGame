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
} // namespace cards