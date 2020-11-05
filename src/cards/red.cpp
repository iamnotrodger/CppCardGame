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
} // namespace cards