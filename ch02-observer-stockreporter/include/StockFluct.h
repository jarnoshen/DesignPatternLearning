/*
 * StockFluct.h
 *
 *  Created on: Aug 4, 2015
 *      Author: ejieysh
 */

#ifndef STOCKFLUCT_H_
#define STOCKFLUCT_H_

#include "IStock.h"
#include <algorithm>
#include <string>

class StockFluct : public IStock
{
public:
  StockFluct(const std::string& name, const float fluct);

  virtual void recvSubscription(IUser* user);
  virtual void recvUnsubscription(const IUser* user);
  virtual void setCurrentPrice(const float current);

  virtual void notifySubscribers();

private:
  const float fluct;
  bool        changed;

};

StockFluct::StockFluct(const std::string& name, const float fluct)
  : IStock(name), fluct(fluct), changed(false)
{ }

void StockFluct::recvSubscription(IUser* user)
{
  UserComp comp(user);
  auto it = std::find_if(users.begin(), users.end(), comp);

  if (it == users.end())
  {
    users.push_back(user);
  }
}

void StockFluct::recvUnsubscription(const IUser* user)
{
  UserComp comp(user);
  auto it = std::remove_if(users.begin(), users.end(), comp);
  users.erase(it, users.end());
}


void StockFluct::setCurrentPrice(const float current)
{
  price.current = current;
  if (price.isFlucted(fluct))
  {
    changed = true;
  }
  this->notifySubscribers();
}

void StockFluct::notifySubscribers()
{
  if (changed)
  {
    for (auto it = users.begin(); it != users.end(); ++it)
    {
      IUser* user = *it;
      user->getNotified(price);
    }

    changed = false;
  }
}


#endif /* STOCKFLUCT_H_ */
