/*
 * IStock.h
 *
 *  Created on: Aug 4, 2015
 *      Author: ejieysh
 */

#ifndef ISTOCK_H_
#define ISTOCK_H_

#include "IUser.h"
#include "Price.h"
#include <vector>
#include <string>

class IUser;

class IStock
{
public:
  typedef std::vector<IUser*> IUsers;

  IStock(const std::string& name);

  virtual ~IStock();

  virtual void recvSubscription(IUser* user)    =0;
  virtual void recvUnsubscription(const IUser* user)  =0;
  virtual void setCurrentPrice(const float current)   =0;

  virtual void notifySubscribers()                    =0;

protected:

  Price     price;
  IUsers    users;

};



#endif /* ISTOCK_H_ */
