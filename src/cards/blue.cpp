#include "blue.h"

namespace cards
{
    int Blue::getCardsPerCoin(int coin)
    {
        switch (coin)
        {
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 10;
        default:
            return 0;
        };
    }
} // namespace cards