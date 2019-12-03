#include "fuel.h"

int calculateRequiredAmount( int mass ) {
  return (floor((mass)/3)-2);
}

int calculateTotalRequiredAmount( std::vector<int> masses ) {
  int summ=0;
  for( auto each_mass : masses ) {
//    std::cout << each_mass << std::endl;
    summ+=calculateRequiredAmount(each_mass);
  }
  return summ;
}

