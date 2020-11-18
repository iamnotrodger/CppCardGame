#include "cardFactory.h"

namespace cards
{
    CardFactory::CardFactory()
    {
        blueCard = new Blue();
        chiliCard = new Chili();
        stinkCard = new Stink();
        greenCard = new Green();
        soyCard = new Soy();
        blackCard = new Black();
        redCard = new Red();
        gardenCard = new Garden();
    }

    CardFactory::~CardFactory()
    {
        delete blueCard;
        delete chiliCard;
        delete stinkCard;
        delete greenCard;
        delete soyCard;
        delete blackCard;
        delete redCard;
        delete gardenCard;
    }

    CardFactory *CardFactory::getFactory()
    {
        if (cardFactory == nullptr)
        {
            cardFactory = new CardFactory();
        }
        return cardFactory;
    }

    // Deck *CardFactory::getDeck()
    // {
    //     Deck *deck = new Deck();
    //     return deck;
    // }
} // namespace cards