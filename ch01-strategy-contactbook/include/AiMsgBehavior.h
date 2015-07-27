#ifndef AIMSGBEHAVIOR_H
#define AIMSGBEHAVIOR_H

#include <MsgBehavior.h>
#include <iostream>
#include <iMsgSimulator.h>


class AiMsgBehavior : public MsgBehavior
{
    public:
        virtual bool msg(const std::string& name, const std::string& id)
        {
            return iMsgSimulator_msg(name, id);
        }
    protected:
    private:
};

#endif // AIMSGBEHAVIOR_H
