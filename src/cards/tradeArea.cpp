#include "tradeArea.h"
#include "createClass.h"

namespace cards
{
    TradeArea::TradeArea(std::istream &is, const CardFactory *cf)
    {
        CardFactory *cardFac = cf->getFactory();
        std::string verify = "TradeArea";
        std::string line;
        getline(is, line, '\t');

        //verity this class
        if (verify != line)
        {
            throw CreateClass("Unable to make TradeArea Class.");
        }

        getline(is, line, '\n');
        for (std::string::size_type i = 0; i < line.size(); i++)
        {
            *this += cardFac->createCard(line[i]);
        }
    }

    TradeArea &TradeArea::operator+=(Card *card)
    {
        cards.push_back(card);
        return *this;
    }

    bool TradeArea::legal(Card *card)
    {
        for (std::list<Card *>::iterator i = cards.begin(); i != cards.end(); i++)
        {
            if ((*i)->getName() == card->getName())
            {
                return true;
            }
        }

        return false;
    }

    Card *TradeArea::trade(std::string bean)
    {
        for (std::list<Card *>::iterator i = cards.begin(); i != cards.end(); i++)
        {
            if ((*i)->getName() == bean)
            {
                Card *trade = *i;
                cards.erase(i);

                return trade;
            }
        }
        return nullptr;
    }

    Card *TradeArea::trade()
    {
        int j = 0;
        for (std::list<Card *>::iterator i = cards.begin(); i != cards.end(); i++)
        {
            Card *trade = *i;
            cards.erase(i);

            return trade;
        }
        return nullptr;
    }

    void TradeArea::show()
    {
        std::cout << "Trade Area: " << std::endl;
        for (std::list<Card *>::iterator i = cards.begin(); i != cards.end(); i++)
        {
            std::cout << (*i)->getName() << std::endl;
        }
    }
} // namespace cards