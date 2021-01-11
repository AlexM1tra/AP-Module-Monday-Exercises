#include <iostream>

// Takes a string and returns a boolean value denoting whether the string contains only numeric characters. 
// Used to validate inputs before they are converted to the correct type.
bool isNumeric(std::string input) {
  std::string numericChars = "0123456789.-";
  for (char c : input) {
    if (numericChars.find(c) == std::string::npos) {
      return false;
    }
  }
  return true;
}

// Returns a boolean showing whether a single digit is even.
bool isEven(char digit) {
  std::string evens = "02468";
  if (evens.find(digit) != std::string::npos) {
    return true;
  }
  return false;
}

// Returns the last character of a string which in this case
// will be the last digit of the user's number.
char lastDigit(std::string number) {
  return number[number.size()-1]; 
}

int main() {
  std::string number;
  std::cout << "Please enter a value? ";
  std::cin >> number;
  while (!isNumeric(number)) {
    std::cout << "Invalid number. Please enter a numeric value: ";
    std::cin >> number;
  }
  if (isEven(lastDigit(number))) {
    std::cout << number << " is an even number" << std::endl;
  } else {
    std::cout << number << " is an odd number" << std::endl;
  }
  return 0;
}
