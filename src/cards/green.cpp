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
} // namespace cards