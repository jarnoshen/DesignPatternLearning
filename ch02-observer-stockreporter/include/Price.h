/*
 * Price.h
 *
 *  Created on: Aug 4, 2015
 *      Author: ejieysh
 */

#ifndef PRICE_H_
#define PRICE_H_

#include <string>
#include <cmath>
#include <iostream>

class Price
{
public:
  // assume the open price is always 100.0
  Price(const std::string& name/*, float open, float current*/)
    : name(name), open(100.0), current(100.0)
  {}

  bool isFlucted(float percent) const
  {
    return (std::abs(current - open) / open) >= percent;
  }

  void print() const
  {
    char sign = current >= open ? '+' : '-';
    float percent = std::abs(current - open) / open * 100.0;
    std::cout << name << ": " << open << " " << current << " "
              << sign << percent << '%' << std::endl;
  }

  std::string name;
  float       open;
  float       current;
};




#endif /* PRICE_H_ */
