#include "fuel.h"

int calculateRequiredAmount( int mass ) {
  return (floor((mass)/3)-2);
}

int calculateRequiredAmountRecursive( int mass ) {
  int amount_with_fuelmass_fix=0;
  try { 
    while( true ) { 
      int this_round_fuelmass = calculateRequiredAmount( mass );
      if( this_round_fuelmass <= 0 ) { break; }
      amount_with_fuelmass_fix += this_round_fuelmass;
      mass=this_round_fuelmass;
    }
  } catch(...) {}
  return amount_with_fuelmass_fix; 
}

int calculateTotalRequiredAmount( std::vector<int> masses ) {
  int summ=0;
  for( auto each_mass : masses ) {
//    std::cout << each_mass << std::endl;
    summ+=calculateRequiredAmountRecursive(each_mass);
  }
  return summ;
}

