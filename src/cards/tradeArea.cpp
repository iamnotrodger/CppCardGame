#include "tradeArea.h"

namespace cards
{
    TradeArea::TradeArea() {

    }

    TradeArea &TradeArea::operator+=(Card * card) {

        cards.push_back(card);

        // std::cout << "Match" << std::endl;
        // for (std::list<Card *>::iterator i = cards.begin(); i != cards.end(); i++) {
        //     std::cout << (*i)->getName() << std::endl;
        // }

        // std::cout << "" << std::endl;

        return *this;
    }

    bool TradeArea::legal(Card * card) {
        for (std::list<Card *>::iterator i = cards.begin(); i != cards.end(); i++) {
            if ((*i)->getName() == card->getName()) {
                return true;
            }
        }

        return false;
    }

    Card * TradeArea::trade(std::string bean) {
        for (std::list<Card *>::iterator i = cards.begin(); i != cards.end(); i++) {
            if ((*i)->getName() == bean) {
                Card * trade = *i;
                cards.erase(i);

                return trade;
            }
        }
    }

    Card * TradeArea::trade(int index) {
        int j=0;
        for (std::list<Card *>::iterator i = cards.begin(); i != cards.end(); i++) {
            if (j == index) {
                Card * trade = *i;
                cards.erase(i);

                return trade;
            }
            j++;
        }
    }

    void TradeArea::show() {
        std::cout << "Trade Area: " << std::endl;
        for (std::list<Card *>::iterator i = cards.begin(); i != cards.end(); i++) {
            std::cout << (*i)->getName() << std::endl;
        }
    }
} 