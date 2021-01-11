#include <iostream>

enum NUMBER_TYPE {
  NEGATIVE = 0,
  ZERO = 1,
  POSITIVE = 2,
  NAN = 3
};

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

// Returns true if all characters in the string are 0
bool stringIsZero(std::string input) {
  for (char c : input) {
    if (c != '0') {
      return false;
    }
  }
  return true;
}

// Looks at the user entered input and determines whether 
// the input is NAN (not a number), negative, positive or zero.
int analyze(std::string input) {
  if (!isNumeric(input)) {
    return NAN;
  }
  if (input[0] == '-') {
    return NEGATIVE;
  } else if (stringIsZero(input)) {
    return ZERO;
  }
  return POSITIVE;
}

int main() {
  std::cout << "Please enter a valid numeric, or \"Q\" to finish:\n";
  int numNegatives = 0, numZeroes = 0, numPositives = 0;
  std::string input;
  std::cin >> input;
  while (toupper(input[0]) != 'Q') {
      switch (analyze(input)) {
        case NEGATIVE:
          numNegatives++;
          break;
        case ZERO:
          numZeroes++;
          break;
        case POSITIVE:
          numPositives++;
          break;
        case NAN:
          std::cout << "Invalid value, please try again:\n";
          break;
      }
      std::cin >> input;
  }
  std::cout << "Total number of values entered: " 
    << numNegatives + numZeroes + numPositives << std::endl
    << "Zeros: " << numZeroes << std::endl
    << "Positives: " << numPositives << std::endl
    << "Negatives: " << numNegatives << std::endl;
}
