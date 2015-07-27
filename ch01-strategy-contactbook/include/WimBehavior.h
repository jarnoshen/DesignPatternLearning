#ifndef WIMBEHAVIOR_H
#define WIMBEHAVIOR_H

#include <MsgBehavior.h>
#include <iostream>

class WimBehavior : public MsgBehavior
{
    public:
        virtual bool msg(const std::string& name, const std::string& id)
        {
            std::cout << "Sent Weibo Instant Message to " << name << ": " << id << std::endl;
            return true;
        }
    protected:
    private:
};

#endif // WIMBEHAVIOR_H
