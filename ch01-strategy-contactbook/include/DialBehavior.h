#ifndef DIALBEHAVIOR_H
#define DIALBEHAVIOR_H

#include <string>

class DialBehavior
{
    public:
        virtual void dial(const std::string& name, const std::string& id) const = 0;
    protected:
    private:
};

#endif // DIALBEHAVIOR_H
