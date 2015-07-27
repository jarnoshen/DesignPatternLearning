#ifndef CONTACT_H
#define CONTACT_H

#include <DialBehavior.h>
#include <MsgBehavior.h>
#include <string>
#include <memory>

class Contact
{
    public:
        Contact(const std::string& name, const std::string& id)
            : name(name), id(id), dialBehavior(), msgBehavior()
        { }
        virtual ~Contact()
        { }

        virtual void dial() const =0;
        virtual bool msg() =0;

    protected:

        std::string                     name;
        std::string                     id;
        std::auto_ptr<DialBehavior>     dialBehavior;
        std::auto_ptr<MsgBehavior>      msgBehavior;
};

#endif // CONTACT_H
