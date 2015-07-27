#ifndef NODIALBEHAVIOR_H
#define NODIALBEHAVIOR_H

#include <DialBehavior.h>
#include <iostream>

class NoDialBehavior : public DialBehavior
{
    public:
        virtual void dial(const std::string& name, const std::string& id) const
        {
            std::cout << "Cannot dial to " << name << ": " << id << std::endl;
        }
    protected:
    private:
};

#endif // NODIALBEHAVIOR_H
