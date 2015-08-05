/*
 * IUser.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: ejieysh
 */


#include "IUser.h"
#include "IStock.h"


IUser::IUser(const uint16_t uid)
  : uid(uid), itsStock(nullptr)
{ }

IUser::~IUser()
{
  if (itsStock)
  {
    itsStock->recvUnsubscription(this);
  }
}
