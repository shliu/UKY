#include "plan.h"

#include <iostream>


void Plan::print() const{
  std::cout << "  Plan - " << type() << ": " << std::endl
    << "    Usage:    " << usage() << " " << usageUnit() << std::endl
    << "    Rate:     " << rate() << " " 
    << rateUnit() << "/" << usageUnit() << std::endl
    << "    Subtotal: " << subtotal() << " " << rateUnit() << std::endl;
}
