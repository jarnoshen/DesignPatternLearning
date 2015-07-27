#ifndef MSGBEHAVIOR_H
#define MSGBEHAVIOR_H
#include <string>

class MsgBehavior
{
    public:
        virtual bool msg(const std::string& name, const std::string& id) =0;
    protected:
    private:
};


#endif // MSGBEHAVIOR_H
