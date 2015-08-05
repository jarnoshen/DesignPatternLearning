/*
 * IStock.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: ejieysh
 */


#include "IStock.h"
#include "IUser.h"

IStock::IStock(const std::string& name)
  : price(name)
{ }

IStock::~IStock()
{
  for (auto it = users.begin(); it != users.end(); ++it)
  {
    IUser* user = *it;
    user->notifyTerminated();
  }
}

