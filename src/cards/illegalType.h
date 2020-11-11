#include <exception>

namespace cards
{
    class IllegalType : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "You are using an Illegal Type of card";
        }
    };
} // namespace cards