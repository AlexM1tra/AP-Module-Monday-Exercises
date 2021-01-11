#include <iostream>

// Takes a string and returns a boolean value denoting whether the string contains only numeric characters. 
// Used to validate inputs before they are converted to the correct type.
bool isValidNumeric(std::string input) {
  std::string numericChars = "0123456789.-";
  int decimalPointCount = 0;
  for (int index = 0; index < input.size(); index++) {
    if (input[index] == '.') {
      decimalPointCount++;
    }
    if (decimalPointCount > 1 
        || (index != 0 && input[index] == '-') 
        || numericChars.find(input[index]) == std::string::npos) {
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

// Validates user's input and returns valid integer.
int integerInput(std::string errorMessage) {
  std::string input;
  std::cin >> input;
  while (!isValidNumeric(input) || stoi(input) <= 0) {
    std::cout << errorMessage;
    std::cin >> input;
  }
  return stoi(input);
}

int main() {
  std::cout << "Please enter your age: ";
  int age = integerInput("Invalid age. Please enter a positive integer: ");
  std::cout << "Please enter your resting pulse: ";
  int restingPulse = integerInput("Invalid pulse. Please enter a positive integer: ");
  std::cout << "Resting Pulse: " << restingPulse << " Age: " << age << std::endl << "Intensity Rate\n------------------------------\n";
  int targetHR;
  for (int rate = 40; rate < 96; rate += 5) {
    targetHR = (((220 - age) - restingPulse) * rate/100) + restingPulse; // Formula for Karvonen heart rate
    std::cout << rate << "%.\t\t" << targetHR << " bpm\n";
  }
  return 0;
}
