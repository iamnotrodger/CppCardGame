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
        //don't use vector::clear() if it storing pointers to objects
    }

    template <class T>
    Chain<T> &Chain<T>::operator+=(T card)
    {
        chain.push_back(card);
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