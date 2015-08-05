/*
 * Employee.h
 *
 *  Created on: Aug 4, 2015
 *      Author: ejieysh
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "IUser.h"
#include "Price.h"
#include "StockManager.h"
#include <string>
#include "stdint.h"

// Employee, watch Stock for
class Employee : public IUser
{
public:
  Employee(const uint16_t uid, const std::string& name);

  virtual void unsubscribe();
  virtual void getNotified(const Price& price);
  virtual void notifyTerminated();

  virtual void changeFluct(const uint8_t fluct);

private:
  const std::string   stockName;
  uint8_t             fluct;

};

Employee::Employee(const uint16_t uid, const std::string& name)
  : IUser(uid), stockName(name), fluct(10)
{
  itsStock = StockManager::getStock(name, fluct);
  itsStock->recvSubscription(this);
}

void Employee::unsubscribe()
{
  if (itsStock)
  {
    itsStock->recvUnsubscription(this);
    itsStock = nullptr;
  }
}

void Employee::getNotified(const Price& price)
{
  std::cout << "User: " << uid << " ";
  price.print();
}

void Employee::notifyTerminated()
{
  itsStock = nullptr;
}

void Employee::changeFluct(const uint8_t newFluct)
{
  if (newFluct != this->fluct)
  {
    this->unsubscribe();
    itsStock = StockManager::getStock(stockName, newFluct);
    itsStock->recvSubscription(this);
    fluct = newFluct;
  }
}

#endif /* EMPLOYEE_H_ */
