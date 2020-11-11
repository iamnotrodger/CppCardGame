#pragma once
#include <exception>

namespace cards
{
    class NotEnoughCoins : public std::exception
    {
        //TODO: add extra information such as how many coin was being used
    public:
        virtual const char *what() const throw()
        {
            return "NotEnoughCoins: Damn bruh you a broke ass bitch";
        }
    }
} // namespace cards