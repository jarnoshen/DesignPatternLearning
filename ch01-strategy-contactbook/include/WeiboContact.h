#ifndef WEIBOCONTACT_H
#define WEIBOCONTACT_H

#include <Contact.h>
#include <NoDialBehavior.h>
#include <WimBehavior.h>


class WeiboContact : public Contact
{
    public:
        WeiboContact(const std::string& name, const std::string& id)
            : Contact(name, id)
        {
            dialBehavior = std::auto_ptr<DialBehavior>(new NoDialBehavior());
            msgBehavior = std::auto_ptr<MsgBehavior>(new WimBehavior());
        }

        virtual void dial() const
        {
            dialBehavior->dial(name, id);
        }
        virtual bool msg()
        {
            return msgBehavior->msg(name, id);
        }
    protected:
    private:
};

#endif // WEIBOCONTACT_H
