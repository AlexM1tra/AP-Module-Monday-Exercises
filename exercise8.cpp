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
  try {
    stoi(input);
  } catch (std::out_of_range) {
    return false;
  }
  return true;
}

int main() {
  std::cout << "Please enter a valid numeric, or \"Q\" to finish:\n";
  double min = INT32_MAX, max = INT32_MIN;
  double numericalInput = 0;
  int numValues = 0;
  std::string input;
  std::cin >> input;
  while (input.size() != 1 || toupper(input[0]) != 'Q') {
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
