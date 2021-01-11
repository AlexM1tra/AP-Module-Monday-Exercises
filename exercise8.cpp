#include <iostream>

bool isNumeric(std::string input) {
  std::string numericChars = "0123456789.-";
  for (char c : input) {
    if (numericChars.find(c) == std::string::npos) {
      return false;
    }
  }
  return true;
}

int main() {
  std::cout << "Please enter a valid numeric, or \"Q\" to finish:\n";
  int min = INT32_MAX, max = INT32_MIN;
  int numericalInput = 0;
  int numValues = 0;
  std::string input;
  std::cin >> input;
  while (toupper(input[0]) != 'Q') {
      if (!isNumeric(input)) {
        std::cout << "Invalid value, please try again:\n";
      } else {
        numValues ++;
        numericalInput = stoi(input);
        if (numericalInput < min) {
          min = numericalInput;
        }
        if (numericalInput > max) {
          max = numericalInput;
        }
      }

      std::cin >> input;
  }
  std::cout << "Total number of values entered: " << numValues << std::endl
    << "Lowest Value:\t" << min << std::endl
    << "Largest Value:\t " << max << std::endl;
}
