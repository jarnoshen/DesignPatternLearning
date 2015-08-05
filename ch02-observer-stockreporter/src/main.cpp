/*
 * main.cpp

 *
 *  Created on: Aug 4, 2015
 *      Author: ejieysh
 */

#include "IStock.h"
#include "StockManager.h"
#include "Employee.h"
#include <iostream>

int main(...)
{
  Employee* e1 = new Employee(1001, "Ericsson");
  Employee* e2 = new Employee(1002, "Ericsson");
  Employee* e3 = new Employee(1003, "Ericsson");
  e3->changeFluct(5);
  Employee* n1 = new Employee(5001, "Nokia");

  StockManager::updateStock("Ericsson", 108.0);
  StockManager::updateStock("Ericsson", 111.0);
  StockManager::updateStock("Ericsson", 93.0);
  StockManager::updateStock("Ericsson", 85.0);
  StockManager::updateStock("Nokia", 117.0);
  StockManager::updateStock("Nokia", 79.0);

  delete e1;
  delete e2;
  delete e3;
  delete n1;

  return 0;
}



