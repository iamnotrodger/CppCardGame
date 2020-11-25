#pragma once
#include <exception>

namespace cards
{
    class CreateClass : public std::exception
    {
        const char *message;

    public:
        CreateClass(const char *c)
        {
            message = c;
        }
        virtual const char *what() const throw()
        {
            return message;
        }
    };

} // namespace cards