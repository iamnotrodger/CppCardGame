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
} // namespace cards