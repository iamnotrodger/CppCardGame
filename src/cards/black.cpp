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
} // namespace cards