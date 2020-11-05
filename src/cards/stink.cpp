#include "stink.h"

namespace cards
{
    int Stink::getCardsPerCoin(int coin)
    {
        switch (coin)
        {
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 8;
        default:
            return 0;
        };
    }
} // namespace cards