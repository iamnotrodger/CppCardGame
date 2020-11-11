#pragma once
#include <exception>

namespace cards
{
    class IllegalType : public std::exception
    {
        //TODO: add extra information such as type of card that was illegal
    public:
        virtual const char *what() const throw()
        {
            return "IllegalType: You are using an Illegal Type of card";
        }
    };
} // namespace cards