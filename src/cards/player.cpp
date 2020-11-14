#include "player.h"
#include "notEnougCoins.h"

namespace cards
{
    // constructor
    Player::Player()
    {
    }

    // adds coins to a player's total
    Player &Player::operator+=(int addCoins)
    {
        coins += addCoins;
        return *this;
    }

    // adds a card to a player's hand
    void Player::addCard(Card *card)
    {
        hand += card;
    }

    // returns the number of chains a player has
    int Player::getMaxNumChains()
    {
        return numChain;
    }

    // returns a particular chain
    Chain_Base &Player::operator[](int i)
    {
        return *chains[i];
    }

    // allows the player to buy a third chain slot
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

    // prints the player's hand
    void Player::printHand(bool show)
    {
        if (!show)
        {
            std::cout << hand.top()->getName() << std::endl;
        }

        else
        {
            std::cout << "Here" + hand.getSize() << std::endl;
            for (int i = 0; i < hand.getSize(); i++)
            {
                std::cout << hand[i]->getName() + "" << std::endl;
            }
        }
    }

    // deletes a card from a player's hand
    void Player::deleteCard(int index)
    {
        hand.deleteCard(index);
    }
} // namespace cards