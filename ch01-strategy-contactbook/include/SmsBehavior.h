#ifndef SMSBEHAVIOR_H
#define SMSBEHAVIOR_H

#include <MsgBehavior.h>
#include <iostream>

class SmsBehavior : public MsgBehavior
{
    public:
        virtual bool msg(const std::string& name, const std::string& id)
        {
            std::cout << "Sent SMS to " << name << ": " << id << std::endl;
            return true;
        }
    protected:
    private:
};

#endif // SMSBEHAVIOR_H
