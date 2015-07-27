#ifndef IMSGSIMULATOR_H_INCLUDED
#define IMSGSIMULATOR_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

static std::vector<std::string> quarantine;

bool iMsgSimulator_hasIMsg(const std::string& id)
{
    return id == "13816481852";
}

bool iMsgSimulator_msg(const std::string& name, const std::string& id)
{
    static unsigned short quota = 5;

    if (quota > 0)
    {
        --quota;
        std::cout << "Sent iMessage to " << name << ": " << id << " ";
        std::cout << quota << " quota iMessage remains." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Cannot send iMessage" << std::endl;
        quota = 5;
        return false;
    }
}



#endif // IMSGSIMULATOR_H_INCLUDED
