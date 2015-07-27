#include "Contact.h"
#include "PhoneContact.h"
#include "WeiboContact.h"
#include "ContactBook.h"
#include <iostream>
#include <memory>

int main()
{
    ContactBook cb;

    std::auto_ptr<Contact> c1(new PhoneContact("JieYuan", "11111222333"));
    size_t nAndroidPhoneContact = cb.add(c1);
    std::auto_ptr<Contact> c2(new WeiboContact("JieYuan", "jieyuan@example.com"));
    size_t nWeiboContact = cb.add(c2);
    std::auto_ptr<Contact> c3(new PhoneContact("Brenda", "11111222444"));
    size_t nIPhoneContact = cb.add(c3);

    cb.get(nAndroidPhoneContact)->dial();
    for (unsigned short i = 0; i < 10; i++)
    {
        cb.get(nAndroidPhoneContact)->msg();
    }
    cb.get(nIPhoneContact)->dial();
    for (unsigned short i = 0; i < 10; i++)
    {
        cb.get(nIPhoneContact)->msg();
    }
    cb.get(nWeiboContact)->dial();
    cb.get(nWeiboContact)->msg();

    return 0;
}
