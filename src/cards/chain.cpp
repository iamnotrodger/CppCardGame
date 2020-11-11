#include "chain.h"
#include "card.h"

namespace cards
{
    template <class T>
    Chain<T>::Chain(std::istream &is, const CardFactory *cf)
    {
    }

    template <class T>
    Chain<T>::~Chain()
    {
        for (int i = 0; i < chain.size(); i++)
        {
            delete chain[i];
        }
        chain.clear();
    }

    template <class T>
    Chain<T> &Chain<T>::operator+=(T *card)
    {
        try
        {
            chain.push_back(card);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        return *this;
    }

    template <class T>
    int Chain<T>::sell()
    {
        return 1;
    }

    //this is to avoid linker errors
    template class Chain<int>;
} // namespace cards