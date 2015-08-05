/*
 * IUser.h
 *
 *  Created on: Aug 4, 2015
 *      Author: ejieysh
 */

#ifndef IUSER_H_
#define IUSER_H_

#include "IStock.h"
#include "Price.h"
#include "stdint.h"

class IStock;

class IUser
{
public:

  IUser(const uint16_t uid);

  virtual ~IUser();

  virtual void unsubscribe()                    =0;
  virtual void getNotified(const Price& price)  =0;
  virtual void notifyTerminated()               =0;

  friend  class UserComp;

protected:

  const uint16_t    uid;
  IStock*           itsStock;
};


class UserComp
{
public:
  UserComp(IUser* user)
    : uid(user->uid)
  {}

  UserComp(const IUser* user)
    : uid(user->uid)
  {}

  bool operator ()(const IUser* user) const
  {
    return uid == user->uid;
  }

private:
  const uint16_t uid;
};


#endif /* IUSER_H_ */
