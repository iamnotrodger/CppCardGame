#include <iostream>
#include <string>
#include <sstream>
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
#include "createClass.h"

namespace cards
{
    //Constructor
    Player::Player(std::istream &is, const CardFactory *cf)
    {
        std::string verify = "Player";
        std::string line;
        std::istringstream ss;

        //verify is we are reading the player class
        std::getline(is, line);
        if (line != verify)
        {
            throw CreateClass("Unable to create Player Class");
        }

        //get the name
        getline(is, line, '\t');
        getline(is, this->name, '\n');

        //get coins
        getline(is, line, '\t');
        getline(is, line, '\n');
        ss.str(line);
        ss >> this->coins;
        if (ss.fail())
        {
            throw CreateClass("Unable to create Player Class");
        }
        ss.clear();

        //get max chains
        getline(is, line, '\t');
        getline(is, line, '\n');
        ss.str(line);
        ss >> this->maxChain;
        if (ss.fail())
        {
            throw CreateClass("Unable to create Player Class");
        }

        this->hand = new Hand(is, cf);

        getline(is, line, '\n');
        Chain_Base *chain;
        while (!line.empty() && getline(is, line, '\t') && !is.eof())
        {
            if (line.compare("Blue") == 0)
            {
                chain = new Chain<Blue>(is, cf);
            }
            else if (line.compare("Chili") == 0)
            {
                chain = new Chain<Chili>(is, cf);
            }
            else if (line.compare("Stink") == 0)
            {
                chain = new Chain<Stink>(is, cf);
            }
            else if (line.compare("Green") == 0)
            {
                chain = new Chain<Green>(is, cf);
            }
            else if (line.compare("soy") == 0)
            {
                chain = new Chain<Soy>(is, cf);
            }
            else if (line.compare("black") == 0)
            {
                chain = new Chain<Black>(is, cf);
            }
            else if (line.compare("Red") == 0)
            {
                chain = new Chain<Red>(is, cf);
            }
            else if (line.compare("garden") == 0)
            {
                chain = new Chain<Garden>(is, cf);
            }
            else
            {
                continue;
            }
            chains.push_back(chain);
        }
    }

    //Deconstructor
    Player::~Player()
    {
        delete hand;
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
        return maxChain;
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
            maxChain++;
        }
    }

    // prints the player's hand
    void Player::printHand(bool show)
    {
        if (!show)
        {
            std::cout << (*(*hand)[0]) << std::endl;
        }
        else
        {
            std::cout << (*hand) << std::endl;
        }
    }

    // adds a card to a player's hand
    void Player::addCard(Card *card)
    {
        *hand += card;
    }

    // deletes a card from a player's hand
    Card *Player::deleteCard(int index)
    {
        return hand->deleteCard(index);
    }

    int Player::sellChain(int index)
    {
        return chains[index]->sell();
    }

    void Player::deleteChain(int index)
    {
        chains.erase(chains.begin(), chains.begin() + index);
    }

    // Adds card into the vector<Chain_Base> and creates a new Chain if the type of card does not exist
    bool Player::addCardToChain(Card *card)
    {
        bool flag = false;
        int size = chains.size();
        Chain_Base *chain;

        for (int i = 0; i < size; i++)
        {
            if (chains[i]->check(card))
            {
                flag = true;
                chain = chains[i];
                break;
            }
        }

        if (!flag)
        {
            if (size >= maxChain)
            {
                std::cout << "Card: " << card->getName() << ", was not added. Chain is full: number of chain " << size << " and max number of chain is " << maxChain << std::endl;
                return false;
            }

            chain = createChain(card);
            chains.push_back(chain);
            std::cout << "A new Chain has been created" << std::endl;
        }

        *(chain) += card;
        return true;
    }

    //
    Chain_Base *Player::createChain(Card *card)
    {
        std::string type = typeid(*(card)).name();

        if (type == typeid(Blue).name())
        {
            Chain<Blue> *chain = new Chain<Blue>();
            return chain;
        }
        else if (type == typeid(Chili).name())
        {
            Chain<Chili> *chain = new Chain<Chili>();
            return chain;
        }
        else if (type == typeid(Stink).name())
        {
            Chain<Stink> *chain = new Chain<Stink>();
            return chain;
        }
        else if (type == typeid(Green).name())
        {
            Chain<Green> *chain = new Chain<Green>();
            return chain;
        }
        else if (type == typeid(Soy).name())
        {
            Chain<Soy> *chain = new Chain<Soy>();
            return chain;
        }
        else if (type == typeid(Black).name())
        {
            Chain<Black> *chain = new Chain<Black>();
            return chain;
        }
        else if (type == typeid(Red).name())
        {
            Chain<Red> *chain = new Chain<Red>();
            return chain;
        }
        else
        {
            Chain<Garden> *chain = new Chain<Garden>();
            return chain;
        }
    }
} // namespace cards
