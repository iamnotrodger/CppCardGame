#include "chili.h"

namespace cards
{
    int Chili::getCardsPerCoin(int coint)
    {
        switch (coint)
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
} // namespace cards