#include "discardPile.h"
#include "createClass.h"

namespace cards
{
    DiscardPile::DiscardPile(std::istream &is, const CardFactory *cf)
    {
        CardFactory *cardFac = cf->getFactory();
        std::string verify = "DiscardPile";
        std::string line;
        getline(is, line, '\t');

        //verity this class
        if (verify != line)
        {
            throw CreateClass("Unable to make DiscardPile Class.");
        }

        getline(is, line, '\n');
        for (std::string::size_type i = 0; i < line.size(); i++)
        {
            *this += cardFac->createCard(line[i]);
        }
    }

    DiscardPile &DiscardPile::operator+=(Card *card)
    {
        pile.push_back(card);
        return *this;
    }

    Card *DiscardPile::pickUp()
    {

        if (pile.size() == 0)
        {
            return NULL;
        }

        Card *top = pile[pile.size() - 1];
        pile.erase(pile.begin() + pile.size() - 1, pile.begin() + pile.size());
        return top;
    }

    Card *DiscardPile::top()
    {
        if (pile.size() == 0)
        {
            return NULL;
        }

        Card *top = pile[pile.size() - 1];
        return top;
    }

    void DiscardPile::print(std::ostream &os) const
    {
        os << "DiscardPile\t";
        for (unsigned i = 0; i < pile.size(); i++)
        {
            os << *(pile[i]);
        }
        os << std::endl;
    }

} // namespace cards