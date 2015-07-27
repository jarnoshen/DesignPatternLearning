#ifndef LTEDIALBEHAVIOR_H
#define LTEDIALBEHAVIOR_H

#include <DialBehavior.h>
#include <iostream>


class LteDialBehavior : public DialBehavior
{
    public:
        virtual void dial(const std::string& name, const std::string& id) const
        {
            std::cout << "Dial to " << name << ": " << id << " via LTE..." << std::endl;
        }
    protected:
    private:
};

#endif // LTEDIALBEHAVIOR_H
