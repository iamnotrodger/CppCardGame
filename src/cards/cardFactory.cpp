#include "cardFactory.h"
#include "deck.h"

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

    Deck CardFactory::getDeck()
    {
        //create vector<card>
        //push blue cards
        for (int i = 0; i < 20; i++)
        {
            cardList.push_back(blueCard);
        }

        //push chili cards
        for (int i = 0; i < 18; i++)
        {
            cardList.push_back(chiliCard);
        }

        //push stink cards
        for (int i = 0; i < 16; i++)
        {
            cardList.push_back(stinkCard);
        }

        //push green cards
        for (int i = 0; i < 14; i++)
        {
            cardList.push_back(greenCard);
        }

        //push soy cards
        for (int i = 0; i < 12; i++)
        {
            cardList.push_back(soyCard);
        }

        //push black cards
        for (int i = 0; i < 10; i++)
        {
            cardList.push_back(blackCard);
        }

        //push red cards
        for (int i = 0; i < 8; i++)
        {
            cardList.push_back(redCard);
        }

        //push garden
        for (int i = 0; i < 6; i++)
        {
            cardList.push_back(gardenCard);
        }

        Deck deck(cardList);
        return deck;
    }

    Card *CardFactory::createCard(char c)
    {
        if (c == 'B')
        {
            return blueCard;
        }
        else if (c == 'C')
        {
            return chiliCard;
        }
        else if (c == 'S')
        {
            return stinkCard;
        }
        else if (c == 'G')
        {
            return greenCard;
        }
        else if (c == 's')
        {
            return soyCard;
        }
        else if (c == 'b')
        {
            return blackCard;
        }
        else if (c == 'R')
        {
            return redCard;
        }
        else if (c == 'g')
        {
            return gardenCard;
        }

        return nullptr;
    }
} // namespace cards