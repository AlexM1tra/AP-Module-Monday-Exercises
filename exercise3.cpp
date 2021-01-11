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
    stod(input);
  } catch (std::out_of_range) {
    return false;
  }
  return true;
}

// Prompts the user, validates their input and returns valid double.
double doubleInput(std::string prompt, std::string errorMessage) {
  std::cout << prompt;
  std::string input;
  std::cin >> input;
  while (!isNumeric(input) || stod(input) <= 0) {
    std::cout << errorMessage;
    std::cin >> input;
  }
  return stod(input);
}

int main() {
  const double feetToMetersRatio = 0.3048; // 1 foot is 0.3048 meters
  double length = doubleInput("What is the length of the room in feet? ", "Invalid length. Please enter a numeric value: "),
    width = doubleInput("What is the width of the room in feet? ", "Invalid width. Please enter a numeric value: "),
    areaInFeet = length * width,
    areaInMeters = length * feetToMetersRatio * width * feetToMetersRatio;
  std::cout 
    << "Your room's dimension is " << length << " by " << width << " feet, the area is:\n" 
    << areaInFeet << " square foot\n"
    << areaInMeters << " square meters" << std::endl;
}
