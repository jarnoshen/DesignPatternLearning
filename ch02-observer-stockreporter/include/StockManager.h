/*
 * StockManager.h
 *
 *  Created on: Aug 5, 2015
 *      Author: ejieysh
 */

#ifndef STOCKMANAGER_H_
#define STOCKMANAGER_H_

#include "IStock.h"
#include "StockFluct.h"
#include "stdint.h"

// manager 'Ericsson' and 'Nokia' stock reporter
// only support 10% and 5% fluct first

class StockManager
{
public:
  static void updateStock(const std::string& name, const float newPrice)
  {
    if (name == "Ericsson")
    {
      getEricsson10()->setCurrentPrice(newPrice);
      getEricsson5()->setCurrentPrice(newPrice);
    }
    else if (name == "Nokia")
    {
      getNokia10()->setCurrentPrice(newPrice);
      getNokia5()->setCurrentPrice(newPrice);
    }
  }

  static IStock* getStock(const std::string& name, const uint8_t fluct)
  {
    if (name == "Ericsson")
    {
      if (fluct == 10)
      {
        return getEricsson10();
      }
      else if (fluct == 5)
      {
        return getEricsson5();
      }
    }
    else if (name == "Nokia")
    {
      if (fluct == 10)
      {
        return getNokia10();
      }
      else if (fluct == 5)
      {
        return getNokia5();
      }
    }
    return nullptr;
  }

private:

  static IStock* getEricsson10()
  {
    if (!Ericsson10)
    {
      Ericsson10 = new StockFluct("Ericsson", 0.1);
    }
    return Ericsson10;
  }

  static IStock* getEricsson5()
  {
    if (!Ericsson5)
    {
      Ericsson5 = new StockFluct("Ericsson", 0.05);
    }
    return Ericsson5;
  }

  static IStock* getNokia10()
  {
    if (!Nokia10)
    {
      Nokia10 = new StockFluct("Nokia", 0.1);
    }
    return Nokia10;
  }

  static IStock* getNokia5()
  {
    if (!Nokia5)
    {
      Nokia5 = new StockFluct("Nokia", 0.05);
    }
    return Nokia5;
  }

  static IStock* Ericsson10;
  static IStock* Ericsson5;
  static IStock* Nokia10;
  static IStock* Nokia5;
};

IStock* StockManager::Ericsson10 = nullptr;
IStock* StockManager::Ericsson5 = nullptr;
IStock* StockManager::Nokia10 = nullptr;
IStock* StockManager::Nokia5 = nullptr;

#endif /* STOCKMANAGER_H_ */
