#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <Contact.h>
#include <vector>
#include <memory>

class ContactBook
{
    public:

        size_t add(std::auto_ptr<Contact>& contact)
        {
            contacts.push_back(contact.get());
            return contacts.size() - 1U;
        }

        Contact* get(size_t n)
        {
            return contacts[n];
        }

    protected:
    private:
        std::vector<Contact*>    contacts;
};

#endif // CONTACTBOOK_H
