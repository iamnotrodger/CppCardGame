#pragma once
#include <exception>

namespace cards
{
    class IllegalType : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Error: You are using an Illegal Type of card";
        }
    };
} // namespace cards