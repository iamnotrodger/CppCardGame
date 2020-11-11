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
} 