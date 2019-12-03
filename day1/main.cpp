#include <iostream>
#include <vector>

#include "fuel.h"

int main(int argc, char** argv) {

  std::vector<int> intMasses;

  for(std::string rawInput; std::getline(std::cin, rawInput);){
    intMasses.push_back(std::stoi(rawInput));
  }

  std::cout << calculateTotalRequiredAmount(intMasses) << std::endl;
  return 0;
}
