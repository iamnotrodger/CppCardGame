#include "player.h"
#include "notEnougCoins.h"

namespace cards
{
    Player &Player::operator+=(int addCoins)
    {
        coins += addCoins;
        return *this;
    }

    int Player::getMaxNumChains()
    {
        return numChain;
    }

    Chain_Base &Player::operator[](int i)
    {
        return *chains[i];
    }

    void Player::buyThirdChain()
    {
        if (coins < 3)
        {
            throw NotEnoughCoins();
        }

        if (numChain != 3)
        {
            coins -= 3;
            numChain = 3;
        }
    }

    void Player::printHand(bool show)
    {
        if (!show)
        {
            std::cout << hand.top()->getName() << std::endl;
        }

        else
        {
            for (int i = 0; i < hand.getSize(); i++)
            {
                std::cout << hand[i]->getName() << std::endl;
            }
        }
    }
} // namespace cards