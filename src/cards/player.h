#pragma once
#include <vector>
#include <string>
#include "cardFactory.h"
#include "chain.h"
#include "hand.h"

namespace cards
{
    class Player
    {
    private:
        //variables
        std::string name;
        int coins;
        int maxChain;
        Hand *hand;
        std::vector<Chain_Base *> chains;

        //private member functions
        void createChain(Card *);

    public:
        //Constructor
        Player(const std::string &n) : name(n)
        {
            maxChain = 2;
            coins = 0;
            hand = new Hand();
        };
        //Deconstructor
        ~Player();
        //reconstruct player form file
        Player(std::istream &, const CardFactory *);
        std::string getName()
        {
            return name;
        }
        int getNumCoins()
        {
            return coins;
        }
        //Add a number of coins
        Player &operator+=(int);
        //returns either 2 or 3
        int getMaxNumChains();
        //returns the chain at position i
        Chain_Base &operator[](int i);
        //adds an empty third chain to the player for three coins. The functions reduces the coint count for the player by two. if the player does not have enough coins then an exception NotEnoughCoins is thrown
        void buyThirdChain();
        //prints the top card of the player's hand (argument false) or all of the player's hand (with argument true) to the supplied ostream
        friend std::ostream &operator<<(std::ostream &, const Player &);

        void printHand(std::ostream &, bool);
        void printHand(bool);

        // helper functions
        void addCard(Card *);
        Card *deleteCard(int);
        void addCardToChain(Card *);
    };

    inline std::ostream &operator<<(std::ostream &os, const Player &p)
    {
        os << p.name << ":\t" << p.coins << " coins" << std::endl;
        os << "Chains:" << std::endl;
        for (unsigned i = 0; i < p.chains.size(); i++)
        {
            os << *(p.chains[i]);
        }
        os << "Hand:\t" << *(p.hand);

        return os;
    };

} // namespace cards
