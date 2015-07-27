#ifndef PHONECONTACT_H
#define PHONECONTACT_H

#include <Contact.h>
#include <LteDialBehavior.h>
#include <SmsBehavior.h>
#include <AiMsgBehavior.h>


class PhoneContact : public Contact
{
    public:
        PhoneContact(const std::string& name, const std::string& id)
            : Contact(name, id)
        {
            dialBehavior = std::auto_ptr<DialBehavior>(new LteDialBehavior());
            if (iMsgSimulator_hasIMsg(id))
            {
                msgBehavior = std::auto_ptr<MsgBehavior>(new AiMsgBehavior());
            }
            else
            {
                msgBehavior = std::auto_ptr<MsgBehavior>(new SmsBehavior());
            }
        }

        virtual void dial() const
        {
            dialBehavior->dial(name, id);
        }

        virtual bool msg()
        {
            if (!msgBehavior->msg(name, id))
            {
                msgBehavior = std::auto_ptr<MsgBehavior>(new SmsBehavior());
                msgBehavior->msg(name, id);
            }
        }

    protected:
    private:
};

#endif // PHONECONTACT_H
