#include <string>
#include "player.h"
#include "blue.h"
#include "chili.h"
#include "stink.h"
#include "green.h"
#include "soy.h"
#include "black.h"
#include "red.h"
#include "garden.h"
#include "notEnougCoins.h"
#include "illegalType.h"

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

    // returns the number of chains a player has
    int Player::getMaxNumChains()
    {
        return chains.size();
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

        if (chains.size() != 3)
        {
            coins -= 3;
        }
    }

    // prints the player's hand
    void Player::printHand(bool show)
    {
        //if (!show)
        //{ std::cout << hand.top()->getName() << std::endl;
        //}

        //else
        //{
            //std::cout << "Here" + hand.getSize() << std::endl;
            //for (int i = 0; i < hand.getSize(); i++)
            //{
                //std::cout << hand[i]->getName() + "" << std::endl;
            //}
        //}
        if(!show) {
            std::cout << (*hand)[0] << std::endl;
        } else {
            std::cout << hand << std::endl;
        }
    }

    // adds a card to a player's hand
    void Player::addCard(Card *card)
    {
        *hand += card;
    }

    // deletes a card from a player's hand
    Card * Player::deleteCard(int index)
    {
        return hand.deleteCard(index);
    }

    // Adds card into the vector<Chain_Base> and creates a new Chain if the type of card does not exist
    void Player::addCardToChain(Card *card)
    {
        //TODO: Select which chain to add on
        //TODO: Throw and error if the availalbe chains is already occuppied
        bool flag = false;
        //for(int i = 0; i < chains.size(); i++) {
            //try {
            //} catch() {
                //continue;
            //}
        //}
        createChain(card);
    }

    //
    void Player::createChain(Card *card)
    {
        std::string type = typeid(*(card)).name();
        if (type == typeid(Blue).name())
        {
            Chain<Blue> *chain = new Chain<Blue>();
            *(chain) += card;
            chains.push_back(chain);
        }
        else if (type == typeid(Chili).name())
        {
            Chain<Chili> *chain = new Chain<Chili>();
            *(chain) += card;
            chains.push_back(chain);
        }
        else if (type == typeid(Stink).name())
        {
            Chain<Stink> *chain = new Chain<Stink>();
            *(chain) += card;
            chains.push_back(chain);
        }
        else if (type == typeid(Green).name())
        {
            Chain<Green> *chain = new Chain<Green>();
            *(chain) += card;
            chains.push_back(chain);
        }
        else if (type == typeid(Soy).name())
        {
            Chain<Soy> *chain = new Chain<Soy>();
            *(chain) += card;
            chains.push_back(chain);
        }
        else if (type == typeid(Black).name())
        {
            Chain<Black> *chain = new Chain<Black>();
            *(chain) += card;
            chains.push_back(chain);
        }
        else if (type == typeid(Red).name())
        {
            Chain<Red> *chain = new Chain<Red>();
            *(chain) += card;
            chains.push_back(chain);
        }
        else
        {
            Chain<Garden> *chain = new Chain<Garden>();
            *(chain) += card;
            chains.push_back(chain);
        }
    }
} // namespace cards
