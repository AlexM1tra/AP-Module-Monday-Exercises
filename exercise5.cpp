#include <iostream>

// Takes a string and returns a boolean value denoting whether the string contains only numeric characters. 
// Used to validate inputs before they are converted to the correct type.
bool isValidNumeric(std::string input) {
  std::string numericChars = "0123456789.-";
  for (char c : input) {
    if (numericChars.find(c) == std::string::npos) {
      return false;
    }
  }
  try {
    int test = 3000 + stoi(input); // Makes sure that the retirement year won't be bigger than INT_MAX
  } catch (std::out_of_range) {
    return false;
  }
  return true;
}

// Validates user's input and returns valid age.
int ageInput(std::string errorMessage) {
  std::string input;
  std::cin >> input;
  while (!isValidNumeric(input) || stoi(input) <= 0) {
    std::cout << errorMessage;
    std::cin >> input;
  }
  return stoi(input);
}

int main() {
  time_t t = time(NULL);
	tm* timePtr = localtime(&t);
  int currentYear = timePtr->tm_year + 1900;

  std::cout << "Please enter your current age? ";
  int age = ageInput("Invalid age. Please enter a valid age: ");
  std::cout << "At what age would you like to retire? ";
  int retirementAge = ageInput("Invalid age. Please enter a valid age: ");

  std::cout << "The current year is " << currentYear 
    << ", can retire in " << currentYear + (retirementAge - age) 
    << "; you have " << (retirementAge - age) << " years remaining.\n";
}
