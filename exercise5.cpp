#include <iostream>

int main() {
  time_t t = time(NULL);
	tm* timePtr = localtime(&t);
  int currentYear = timePtr->tm_year + 1900;
  int age;
  int retirementAge;
  std::cout << "Please enter your current age? ";
  std::cin >> age;
  std::cout << "At what age would you like to retire? ";
  std::cin>> retirementAge;
  std::cout << "The current year is " << currentYear 
    << ", can retire in " << currentYear + (retirementAge - age) 
    << "; you have " << (retirementAge - age) << " years remaining.\n";
}
